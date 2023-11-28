/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:26:40 by digil-pa          #+#    #+#             */
/*   Updated: 2023/11/28 17:01:04 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	data_init(t_table *f, int ac, char **av)
{
	f->data = malloc(sizeof(t_data));
	if (!f->data)
		return (0);
	f->data->nbr_of_philo = ft_atoi(av[1]);
	f->data->time_to_die = ft_atoi(av[2]);
	f->data->time_to_eat = ft_atoi(av[3]);
	f->data->time_to_sleep = ft_atoi(av[4]);
	f->data->times_must_eat = -1;
	if (ac == 6)
		f->data->times_must_eat = ft_atoi(av[5]);
	if (!f->data->nbr_of_philo <= 0 || !f->data->time_to_die <= 0 
			|| !f->data->time_to_eat <= 0 || !f->data->time_to_sleep <= 0)
	{
		free (f->data);
		return (0);
	}
	f->data->dead = 0;
	f->data->full = 0;
	f->data->life = malloc(sizeof(pthread_mutex_t));
	f->data->food = malloc(sizeof(pthread_mutex_t));
	if (!f->data->food || !f->data->life
			|| pthread_mutex_init(f->data->food,NULL)
			|| pthread_mutex_inti(f->data->life))
			return (0);
	return (1);
}

int	philo_init(t_table *f)
{
	int	i;

	i = -1;
	if (!f->philo)
		return (0);
	while (++i < f->data->nbr_of_philo)
	{
		f->philo[i].philo_id = i + 1;
		f->philo[i].eat_count = 0;
		f->philo[i].last_meal = 0;
		f->philo[i].data = f->data;
		f->philo[i].fork = malloc(sizeof(pthread_mutex_t));
		if (!f->philo[i].fork)
			return (0);
		if (pthread_mutex_init(f->philo[i].fork, NULL))
			return (0);
	}
	return (1);
}

void	free_philo(t_table *f)
{
	int	i;
	
	i = -1;
	if (!f->philo)
		return (0);
	while (++i < f->data->nbr_of_philo)
	{
		if (f->philo[i].fork)
		{
			pthread_mutex_destroy(f->philo[i].fork);
			free(f->philo[i].fork);
		}
	}
	if (f->data)
	{
		pthread_mutex_destroy(f->data->life);
		free(f->data->life);
		pthread_mutex_destroy(f->data->food);
		free(f->data->food);
		f->data = NULL;
	}
	if (f->philo)
		free (f->philo);
}

int	init(t_table *f, int ac, char **av)
{
	f->data = 	NULL;
	f->philo =	NULL;
	if (!f->data)
}

