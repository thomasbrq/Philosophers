/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:54:30 by tbraquem          #+#    #+#             */
/*   Updated: 2022/05/20 17:20:20 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_vars(t_vars *vars, char **argv)
{
	vars->max_philo = ft_atoi(argv[1]);
	vars->time_to_die = ft_atoi(argv[2]);
	vars->time_to_eat = ft_atoi(argv[3]);
	vars->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		vars->max_eat = ft_atoi(argv[5]);
	else
		vars->max_eat = 0;
	vars->forks = ft_atoi(argv[1]);
	vars->continue_sim = 1;
}

t_philo	*init_var_philosopher(t_vars vars, t_philo *philo, int id)
{
	(void) vars;
	philo->id = id;
	philo->state = IDLE;
	philo->ate = 0;
	return (philo);
}

t_philo	**init_philosophers(t_vars vars, t_philo **philosophers)
{
	int	max;
	int	i;
	int	j;

	max = vars.max_philo;
	i = 0;
	j = 1;
	philosophers = (t_philo **) malloc(sizeof(t_philo *) * (max + 1));
	if (!philosophers)
		return (NULL);
	while (i < max)
	{
		philosophers[i] = (t_philo *) malloc(sizeof(t_philo));
		if (!philosophers[i])
			return (philosophers);
		philosophers[i] = init_var_philosopher(vars, philosophers[i], j);
		i++;
		j++;
	}
	philosophers[i] = NULL;
	return (philosophers);
}

t_philo	**init_mutex(t_philo **philosophers)
{
	int	i;

	i = 0;
	while (philosophers[i])
	{
		pthread_mutex_init(&philosophers[i]->fork_mutex, NULL);
		i++;
	}
	return (philosophers);
}

t_data	**init_data(t_philo **philo, t_vars vars, t_data **data)
{
	int	max;
	int	i;

	max = vars.max_philo;
	i = 0;
	data = (t_data **) malloc(sizeof(t_data *) * (max + 1));
	if (!data)
		return (NULL);
	while (i < max)
	{
		data[i] = (t_data *) malloc(sizeof(t_data));
		if (!data[i])
			return (data);
		data[i]->vars = vars;
		data[i]->philo_tab = philo;
		data[i]->index = i;
		i++;
	}
	data[i] = NULL;
	return (data);
}
