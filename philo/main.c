/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:50:03 by tbraquem          #+#    #+#             */
/*   Updated: 2022/05/20 16:32:53 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_philo		**philosophers;
	t_data		**data;

	philosophers = NULL;
	data = NULL;
	if (argc < 5 || argc > 6)
	{
		printf("Error args.\n");
		return (1);
	}
	init_vars(&vars, argv);
	philosophers = init_philosophers(vars, philosophers);
	philosophers = init_mutex(philosophers);
	data = init_data(philosophers, vars, data);
	vars.start_time = get_time();
	start_threads(philosophers, data);
	philosophers = destroy_mutex(philosophers);
	philosophers = free_philosophers(philosophers);
	data = free_data(data);
	return (0);
}
