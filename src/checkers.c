/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:36:35 by digil-pa          #+#    #+#             */
/*   Updated: 2023/12/06 15:28:41 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	checker(t_table *f)
{
	time_t	now;
	int		i;

	i = 0;
	while (!(f->data->dead) && !(f->data->full))
	{
		usleep(100);
		i = 0;
		while (i < f->data->nbr_of_philo)
		{
			now = get_time() - f->data->start_time;
			pthread_mutex_lock(f->data->food);
			if (now >= f->philo[i].last_meal + f->data->time_to_die)
			{
				pthread_mutex_unlock(f->data->food);
				philo_die(f, i);
			}
			else
				pthread_mutex_unlock(f->data->food);
			i++;
		}
		if (f->data->times_must_eat != -1)
			philo_full(f);
	}
}

void	philo_die(t_table *f, int i)
{
	time_t	time;

	time = get_time() - f->philo->data->start_time;
	if (f->data->dead || f->data->full)
		return ;
	pthread_mutex_lock(f->data->life);
	f->data->dead = 1;
	pthread_mutex_unlock(f->data->life);
	usleep(10);
	printf("\033[0;90m%ld \033[0;9m%d \033[0;0m%s", time, i + 1, DIE);
}

void	philo_full(t_table *f)
{
	int	i;

	i = 0;
	while (i < f->data->nbr_of_philo)
	{
		pthread_mutex_lock(f->data->food);
		if (f->philo[i].eat_count < f->data->times_must_eat)
		{
			pthread_mutex_unlock(f->data->food);
			return ;
		}
		pthread_mutex_unlock(f->data->food);
		i++;
	}
	pthread_mutex_lock(f->data->food);
	f->data->full = 1;
	pthread_mutex_unlock(f->data->food);
}
