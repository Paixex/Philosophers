/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:36:35 by digil-pa          #+#    #+#             */
/*   Updated: 2023/11/14 19:07:27 by digil-pa         ###   ########.fr       */
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
				pthread_mutez_unlock(f->data->food);
				philo_kill(f, i);
			}
			else
				pthred_mutex_unlock(f->data->food);
			i++;
		}
		if (f->data->times_must_eat != -1)
			philo_full(f);
	}
}