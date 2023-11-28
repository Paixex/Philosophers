/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:56:08 by digil-pa          #+#    #+#             */
/*   Updated: 2023/11/28 14:25:09 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	thread_init(t_table *f)
{
	int	i;

	i = 0;
	while (i < f->data->nbr_of_philo)
	{
		if (pthread_create(&f->philo[i].thread, NULL,
				(void *)routine, &(f->philo[i])))
				return (0);
		i++;
	}
	return (1);
}

int	join_threads(t_table *f)
{
	int	i;
	
	i = 0;
	while (i < f->data->nbr_of_philo)
	{
		if (pthread_join(&f->philo[i].thread, NULL))
			return (0);
		i++;
	}
	return (1);
}
