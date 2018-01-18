/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:33:51 by arobion           #+#    #+#             */
/*   Updated: 2018/01/18 17:09:13 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_back_to_int(long int *tmp, int argc)
{
	int		i;
	int		*pile;

	i = 0;
	if (!(pile = malloc(sizeof(int) * (argc - 1))))
	{
		free(tmp);
		return (0);
	}
	while (i < (argc - 1))
	{
		pile[i] = (int)(tmp[i]);
		i++;
	}
	free(tmp);
	return (pile);
}

static int	ft_check(long int *tmp, int i)
{
	int		j;

	j = 0;
	if (tmp[i] > 2147483647 || tmp[i] < -2147483648)
		return (0);
	while (j < i)
	{
		if (tmp[j] == tmp[i])
			return (0);
		j++;
	}
	return (1);
}

static int	ft_is_number(char *str)
{
	if (*str == '-')
		str++;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int			*ft_parsing(int argc, char **argv)
{
	int			i;
	long int	*tmp;
	int			j;
	int			*pile;

	i = 0;
	j = 0;
	if (!(tmp = malloc(sizeof(long int) * (argc - 1))))
		return (NULL);
	while (i < argc - 1)
	{
		if (!(ft_is_number(argv[i + 1])))
			j = 1;
		tmp[i] = ft_atoi_swap(argv[i + 1]);
		if (!(ft_check(tmp, i)))
			j = 1;
		i++;
	}
	if (!(pile = ft_back_to_int(tmp, argc)))
		return (NULL);
	if (j == 0)
		return (pile);
	free(pile);
	return (NULL);
}

int			*ft_parsing_swap(int argc, char **argv)
{
	int			i;
	long int	*tmp;
	int			j;
	int			*pile;

	i = 0;
	j = 0;
	if (!(tmp = malloc(sizeof(long int) * (argc - 1))))
		return (NULL);
	while (i < argc - 1)
	{
		if (!(ft_is_number(argv[i])))
			j = 1;
		tmp[i] = ft_atoi_swap(argv[i]);
		if (!(ft_check(tmp, i)))
			j = 1;
		i++;
	}
	if (!(pile = ft_back_to_int(tmp, argc)))
		return (NULL);
	if (j == 0)
		return (pile);
	free(pile);
	return (NULL);
}
