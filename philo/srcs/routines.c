/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:30:22 by tbraquem          #+#    #+#             */
/*   Updated: 2022/05/21 15:34:55 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Routine to each odd Philosopher.
*/

void	*routine(void *arg)
{
	t_data	*data;

	data = (t_data *) arg;
	while (data && data->philo_tab[data->index]->state != DEAD)
	{
		if (philo_eat(data))
			break ;
		if (philo_sleep(data))
			break ;
		if (philo_think(data))
			break ;
	}
	return (NULL);
}

/*
	Routine to each even Philosopher.
*/

void	*routine2(void *arg)
{
	t_data	*data;

	data = (t_data *) arg;
	while (data && data->philo_tab[data->index]->state != DEAD)
	{
		if (philo_think(data))
			break ;
		if (philo_eat(data))
			break ;
		if (philo_sleep(data))
			break ;
	}
	return (NULL);
}

/*
	Routine to each odd Philosopher and when the max_philo is odd.
*/

void	*routine_odd(void *arg)
{
	t_data	*data;

	data = (t_data *) arg;
	if (philo_think(data))
		return (NULL);
	while (data && data->philo_tab[data->index]->state != DEAD)
	{
		if (philo_think(data))
			break ;
		if (philo_eat(data))
			break ;
		if (philo_sleep(data))
			break ;
	}
	return (NULL);
}

/*
	This function manages time and checks every 60 microseconds if
	all Philosophers ate at least max_eat (if necessary)
	or if a Philosopher is dead.
*/

void	loop_time(t_data *data, int *i, int *print)
{
	int		elapsed_time;
	t_philo	*philo;

	elapsed_time = 0;
	philo = data->philo_tab[*i];
	while (data && philo && *i < data->vars.max_philo && philo->state != DEAD)
	{
		philo = data->philo_tab[*i];
		elapsed_time = get_time() - philo->last_meal;
		if (elapsed_time > data->vars.time_to_die)
			philo->state = DEAD;
		if (check_everyone_ate(data->philo_tab, data->vars.max_eat)
			&& data->vars.max_eat > 0)
		{
			(*print) = 0;
			data->vars.continue_sim = 0;
			usleep(mstou(100));
			break ;
		}
		(*i)++;
		if (*i == data->vars.max_philo)
			*i = 0;
		usleep(60);
	}
}

void	*routine_time(void *arg)
{
	t_data	**d;
	t_data	*data;
	int		i;
	int		print;

	d = (t_data **) arg;
	data = d[0];
	i = 0;
	print = 1;
	loop_time(data, &i, &print);
	data->vars.continue_sim = 0;
	if (print == 1)
		print_message(get_time(), data->philo_tab[i]->id, "died\n");
	data->philo_tab = destroy_mutex(data->philo_tab);
	data->philo_tab = free_philosophers(data->philo_tab);
	d = free_data(d);
	exit(1);
	return (NULL);
}
