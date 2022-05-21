/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:33:05 by tbraquem          #+#    #+#             */
/*   Updated: 2022/05/21 15:39:02 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	This function redirect the Philosopher to the right routine.
	Check if the Philosopher index is even or odd,
	and if the max_philo is odd or no.
*/

void	thread_redirect(t_philo *philo, t_data **data, int i)
{
	int	save;

	save = i;
	if (i % 2 == 0 && i % 3 == 2 && data[i]->vars.max_philo % 2 == 1)
	{
		philo->index = save;
		philo->last_meal = get_time();
		pthread_create(&philo->thread, NULL, routine_odd, data[i]);
	}
	else if (i % 2 == 0)
	{
		philo->index = save;
		philo->last_meal = get_time();
		pthread_create(&philo->thread, NULL, routine2, data[i]);
	}
	else if (i % 2 == 1)
	{
		philo->index = save;
		philo->last_meal = get_time();
		pthread_create(&philo->thread, NULL, routine, data[i]);
	}
}

/*
	This function start the Philosophers thread and the time checker thread.
*/

void	start_threads(t_philo **philo, t_data **data)
{
	int			i;
	pthread_t	time;

	i = 0;
	while (philo[i])
	{
		thread_redirect(philo[i], data, i);
		i++;
	}
	pthread_create(&time, NULL, routine_time, data);
	i = 0;
	while (philo[i])
	{
		pthread_join(philo[i]->thread, NULL);
		i++;
	}
	pthread_join(time, NULL);
}
