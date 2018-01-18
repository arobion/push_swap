/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 13:14:11 by arobion           #+#    #+#             */
/*   Updated: 2018/01/18 14:53:09 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_smallest(int *biggest, int n)
{
	int		i;
	int		min;

	min = 1000;
	i = 0;
	while (i < n)
	{
		if (biggest[i] < min)
			min = biggest[i];
		i++;
	}
	return (min);
}

int		ft_smallest_pos(int *biggest, int n)
{
	int		i;
	int		pos;
	int		min;

	min = 1000;
	i = 0;
	pos = 0;
	while (i < n)
	{
		if (biggest[i] < min)
		{
			min = biggest[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int		find_closest_in_the_n_biggest_to_x(int *pile2,\
		t_index *index, int n, int x)
{
	int		i;
	int		*biggest;
	int		to_return;

	i = 0;
	if (!(biggest = malloc(sizeof(int) * n)))
		return (-1);
	while (i < n)
	{
		biggest[i] = 0;
		i++;
	}
	i = index->j;
	while (i > 0)
	{
		if (pile2[i] > ft_smallest(biggest, n) && pile2[i] < x)
			biggest[ft_smallest_pos(biggest, n)] = pile2[i];
		i--;
	}
	to_return = find_closest(biggest, n, pile2, index);
	free(biggest);
	return (to_return);
}
