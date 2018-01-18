/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iota.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:11:55 by arobion           #+#    #+#             */
/*   Updated: 2017/11/28 12:45:49 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int		i;

	i = 1;
	if (n < 0)
		i++;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_neg(char *str, int i, int n)
{
	str[0] = '-';
	str[i] = '\0';
	i--;
	while (n < 0)
	{
		str[i] = ((n % 10) * -1) + '0';
		i--;
		n = n / 10;
	}
}

static void	ft_pos(char *str, int i, int n)
{
	str[i] = '\0';
	i--;
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = count(n);
	if (n == 0)
	{
		if (!(str = malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (n < 0)
		ft_neg(str, i, n);
	else
		ft_pos(str, i, n);
	return (str);
}
