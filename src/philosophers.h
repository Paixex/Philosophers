/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:36:31 by digil-pa          #+#    #+#             */
/*   Updated: 2023/12/06 13:11:20 by digil-pa         ###   ########.fr       */
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

/*--------------------------Structs---------------------------*/

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

/*-------------------------Prototypes-------------------------*/

void		checker(t_table *f);
void		philo_die(t_table *f, int i);
void		philo_full(t_table *f);
time_t		get_time(void);
void		print_status(t_philo *philo, char *str);
int			ft_atoi(char *str);
int			check_num(char *av);
int			check_input(int ac, char **av);
void		routine(void *arg);
void		ciclo(t_philo *philo);
void		forks(t_philo *philo, int action);
void		actions(t_philo *philo, int action);
void		wait_or_die(t_philo *philo, time_t time);
int			thread_init(t_table *f);
int			join_threads(t_table *f);
int			data_init(t_table *f, int ac, char **av);
int			philo_init(t_table *f);
void		free_philo(t_table *f);
int			init_all(t_table *f, int ac, char **av);

#endif