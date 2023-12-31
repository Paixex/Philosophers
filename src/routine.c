/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:27:51 by digil-pa          #+#    #+#             */
/*   Updated: 2023/12/06 15:42:04 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_or_die(t_philo *philo, time_t time)
{
	time_t	start;
	time_t	now;

	start = get_time();
	while (1)
	{
		pthread_mutex_lock(philo->data->life);
		if (philo->data->dead)
		{
			pthread_mutex_unlock(philo->data->life);
			return ;
		}
		pthread_mutex_unlock(philo->data->life);
		now = get_time();
		if (now - start >= time)
			break ;
		usleep(100);
	}
}

void	actions(t_philo *philo, int action)
{
	if (action == 1)
	{
		print_status(philo, FORK);
		print_status(philo, FORK);
		print_status(philo, EAT);
		pthread_mutex_lock(philo->data->food);
		philo->last_meal = get_time() - philo->data->start_time;
		philo->eat_count++;
		pthread_mutex_unlock(philo->data->food);
		wait_or_die(philo, philo->data->time_to_eat);
	}
	else if (action == 2)
	{
		print_status(philo, SLEEP);
		wait_or_die(philo, philo->data->time_to_sleep);
		print_status(philo, THINK);
	}
}

//ChatGPT
void	forks(t_philo *philo, int action)
{
	t_philo	*next_philo;
	
	if (philo->philo_id < philo->data->nbr_of_philo)
		next_philo = &philo[1];
	else
		next_philo = &philo[-1 * (philo->data->nbr_of_philo - 1)];
	if (action == 1)
	{
		if (philo->philo_id < next_philo->philo_id)
		{
			pthread_mutex_lock(philo->fork);
			pthread_mutex_lock(next_philo->fork);
			return ;
		}
		pthread_mutex_lock(next_philo->fork);
		pthread_mutex_lock(philo->fork);
	}
	else if (action == 2)
	{
		pthread_mutex_unlock(philo->fork);
		pthread_mutex_unlock(next_philo->fork);
	}
}

void	ciclo(t_philo *philo)
{
	while (1)
	{
		usleep(100);
		pthread_mutex_lock(philo->data->life);
		pthread_mutex_lock(philo->data->food);
		if (philo->data->dead || philo->data->full)
		{
			pthread_mutex_unlock(philo->data->life);
			pthread_mutex_unlock(philo->data->food);
			return ;
		}
		pthread_mutex_unlock(philo->data->life);
		pthread_mutex_unlock(philo->data->food);
		forks(philo, 1);
		actions(philo, 1);
		forks(philo, 2);
		actions(philo, 2);
	}
}

void	routine(void *arg)
{
	time_t	time;
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	if (philo->data->nbr_of_philo == 1)
	{
		time = philo->data->time_to_die;
		wait_or_die(philo, philo->data->time_to_die);
		printf("%ld %d %s", time, philo->philo_id, DIE);
		return ;
	}
	else
	{
		if (philo->philo_id % 2)
			wait_or_die(philo, philo->data->nbr_of_philo);
		if (!philo->data->dead)
			ciclo(philo);
	}
}
