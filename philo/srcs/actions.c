/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:26:06 by tbraquem          #+#    #+#             */
/*   Updated: 2022/05/21 15:27:33 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_think(t_data *data)
{
	int		index;
	t_philo	*previous;

	index = data->index;
	if (data->vars.continue_sim == 0 || data->philo_tab[index]->state == DEAD)
		return (1);
	usleep(10);
	if (data->philo_tab[index]->state != THINK)
		print_message(get_time(), data->philo_tab[index]->id, "is thinking\n");
	data->philo_tab[index]->state = THINK;
	previous = data->philo_tab[previous_philo(index, data->vars.max_philo)];
	while (previous->state == EAT)
		usleep(50);
	return (0);
}

int	philo_sleep(t_data *data)
{
	int	index;

	index = data->index;
	if (data->vars.continue_sim == 0 || data->philo_tab[index]->state == DEAD)
		return (1);
	usleep(10);
	data->philo_tab[index]->state = SLEEP;
	print_message(get_time(), data->philo_tab[index]->id, "is sleeping\n");
	usleep(mstou(data->vars.time_to_sleep));
	return (0);
}

void	eating(t_data *data, int index)
{
	data->philo_tab[index]->state = EAT;
	data->philo_tab[index]->last_meal = get_time();
	print_message(get_time(), data->philo_tab[index]->id, "has taken a fork\n");
	print_message(get_time(), data->philo_tab[index]->id, "is eating\n");
	usleep(mstou(data->vars.time_to_eat));
	data->philo_tab[index]->ate++;
}

int	philo_eat(t_data *data)
{
	int		i;
	int		index;
	int		mutex;
	t_philo	*previous;

	i = 0;
	index = data->index;
	if (data->vars.continue_sim == 0 || data->philo_tab[index]->state == DEAD)
		return (1);
	usleep(10);
	previous = data->philo_tab[previous_philo(index, data->vars.max_philo)];
	mutex = pthread_mutex_lock(&previous->fork_mutex);
	if (mutex != 0)
		return (1);
	mutex = pthread_mutex_lock(&data->philo_tab[index]->fork_mutex);
	if (mutex != 0)
		return (1);
	eating(data, index);
	mutex = pthread_mutex_unlock(&previous->fork_mutex);
	if (mutex != 0)
		return (1);
	mutex = pthread_mutex_unlock(&data->philo_tab[index]->fork_mutex);
	if (mutex != 0)
		return (1);
	return (0);
}
