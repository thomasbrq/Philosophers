/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:32:27 by tbraquem          #+#    #+#             */
/*   Updated: 2022/05/21 15:29:22 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(long int timestamp, int id, const char *message)
{
	char	*buffer;
	char	*timestamp_array;
	char	*id_array;
	char	*temp;

	buffer = NULL;
	timestamp_array = ft_itoa(timestamp);
	id_array = ft_itoa(id);
	buffer = ft_strjoin(timestamp_array, " ");
	free(timestamp_array);
	temp = ft_strjoin(buffer, id_array);
	free(buffer);
	free(id_array);
	buffer = ft_strjoin(temp, " ");
	free(temp);
	temp = ft_strjoin(buffer, message);
	free(buffer);
	write(1, temp, ft_strlen(temp));
	free(temp);
}
