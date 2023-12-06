/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:45:21 by digil-pa          #+#    #+#             */
/*   Updated: 2023/12/06 14:53:30 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_table	f;
	
	if (ac < 5 || ac > 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	if (!check_input(ac, av))
	{
		printf("Error: Invalid arguments\n");
		return (1);
	}
	if (!init_all(&f, ac, av))
	{
		printf("Error: Initializing arguments\n");
		free_philo(&f);
		return (1);
	}
	free_philo(&f);
	return (0);
}