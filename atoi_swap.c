/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:05:41 by arobion           #+#    #+#             */
/*   Updated: 2018/01/18 17:09:07 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	sign(long long *i, const char *str)
{
	if (str[*i] == '-')
	{
		*i = *i + 1;
		return (-1);
	}
	if (str[*i] == '+')
		*i = *i + 1;
	return (1);
}

static long long	ft_over(const char *str)
{
	long long			i;
	long long			s;
	long long			j;

	j = 0;
	i = 0;
	while (str[i] != '\0' && ft_iswp(str[i]) == 1)
		i++;
	s = sign(&i, str);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) != 1)
			break ;
		i++;
		j++;
	}
	if (j >= 19 && s == -1)
		return (0);
	else if (j >= 19 && s == 1)
		return (-1);
	else
		return (1);
}

long long			ft_atoi_swap(const char *str)
{
	long long		i;
	long long		res;
	long long		s;

	i = 0;
	res = 0;
	while (str[i] != '\0' && ft_iswp(str[i]) == 1)
		i++;
	s = sign(&i, str);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) != 1)
			return (res * s);
		res = res * 10 + str[i] - '0';
		if ((res > 2147483647 && s == 1) || (res > 2147483648 && s == -1))
			return (2147483649);
		i++;
	}
	if (ft_over(str) == -1 || ft_over(str) == 0)
		return (ft_over(str));
	return ((res * s));
}
