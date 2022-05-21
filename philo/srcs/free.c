/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:53:52 by tbraquem          #+#    #+#             */
/*   Updated: 2022/05/21 12:58:46 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**free_philosophers(t_philo **philo)
{
	int	i;

	i = 0;
	while (philo[i])
	{
		free(philo[i]);
		i++;
	}
	free(philo);
	philo = NULL;
	return (philo);
}

t_philo	**destroy_mutex(t_philo **philosophers)
{
	int	i;

	i = 0;
	while (philosophers[i])
	{
		pthread_mutex_destroy(&philosophers[i]->fork_mutex);
		i++;
	}
	return (philosophers);
}

t_data	**free_data(t_data **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
	data = NULL;
	return (data);
}
