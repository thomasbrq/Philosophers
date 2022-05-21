/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraquem <tbraquem@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:34:38 by tbraquem          #+#    #+#             */
/*   Updated: 2022/05/21 12:59:52 by tbraquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	i = 0;
	j = 0;
	ret = NULL;
	ret = (char *) malloc(len * sizeof(char));
	if (!ret)
		return (ret);
	while (s1[i])
		ret[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ret[j++] = s2[i++];
	ret[j] = '\0';
	return (ret);
}

int	count_digit(long long int n)
{
	int				ret;
	long long int	save;

	ret = 0;
	save = n;
	while (save != 0)
	{
		save = save / 10;
		ret++;
	}
	return (ret);
}

char	*malloc_ret(int size)
{
	char	*ret;

	ret = (char *) malloc((size + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[size] = '\0';
	return (ret);
}

char	*fill_ret(char *ret, long long int n, int size)
{
	int	save;
	int	i;

	i = 1;
	while (i <= size)
	{
		if (n >= 10)
		{
			save = (n % 10) + '0';
			n = n / 10;
		}
		else
			save = n + '0';
		ret[size - i] = save;
		i++;
	}
	return (ret);
}

char	*ft_itoa(long long int n)
{
	char	*ret;
	int		size;

	ret = NULL;
	size = count_digit(n);
	if (size <= 0)
		return (NULL);
	ret = malloc_ret(size);
	if (!ret)
		return (NULL);
	ret = fill_ret(ret, n, size);
	return (ret);
}
