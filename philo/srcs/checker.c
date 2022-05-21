/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:08:43 by tbraquem          #+#    #+#             */
/*   Updated: 2022/05/21 15:28:49 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	This function check if everyone ate at least 'max_eat' and return 1;
	Otherwise, return 0;
*/

int	check_everyone_ate(t_philo **philo, int max_eat)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (!philo)
		return (1);
	while (philo[i])
	{
		if (philo[i]->ate < max_eat)
			ret = 0;
		else
			ret = 1;
		i++;
	}
	return (ret);
}
