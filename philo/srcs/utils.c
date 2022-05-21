/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:25:46 by tbraquem          #+#    #+#             */
/*   Updated: 2022/05/21 12:59:30 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		ret;
	int		minus;
	char	*str2;

	minus = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' && minus++ == 0)
		str++;
	else if (*str == '+')
		str++;
	ret = 0;
	str2 = (char *)str;
	while (*str2 >= '0' && *str2 <= '9')
		str2++;
	if ((str2 - str) > 10 && minus == 0)
		return (-1);
	else if ((str2 - str) > 10 && minus == 1)
		return (0);
	while (*str >= '0' && *str <= '9')
		ret = ret * 10 + *str++ - '0';
	if (minus)
		ret *= -1;
	return (ret);
}

int	previous_philo(int index, int max_philo)
{
	int	ret;

	ret = index - 1;
	if (ret < 0)
		ret = max_philo - 1;
	return (ret);
}

int	mstou(int ms)
{
	return (ms * 1000);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long long int	get_time(void)
{
	struct timeval	tp;
	long long int	milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}
