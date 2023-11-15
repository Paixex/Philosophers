/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:36:31 by digil-pa          #+#    #+#             */
/*   Updated: 2023/11/14 17:49:32 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>

# define FORK	"has taken a fork\n"
# define EAT	"is eating\n"
# define SLEEP	"is sleeping\n"
# define THINK	"is thinking\n"
# define DIE	"died\n"

typedef struct s_data
{
	int					nbr_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					times_must_eat;
	int					full;
	int					dead;
	pthread_mutex_t		*life;
	pthread_mutex_t		*food;
	time_t				start_time;
}	t_data;

typedef struct s_philo
{
	int				philo_id;
	int				eat_count;
	int				last_meal;
	pthread_t		thread;
	pthread_mutex_t	*fork;
	t_data			*data;
}	t_philo;

typedef struct s_table
{
	t_data		*data;
	t_philo		*philo;
}	t_table;


#endif