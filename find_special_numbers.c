/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_special_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 13:17:22 by arobion           #+#    #+#             */
/*   Updated: 2018/01/18 11:34:23 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_return(t_rot s, int *pile2)
{
	if (s.nb_reverse_rotate < s.nb_rotate)
		return (pile2[s.reverse_rotate]);
	else if (s.nb_rotate < s.nb_reverse_rotate)
		return (pile2[s.rotate]);
	else
	{
		if (pile2[s.rotate] < pile2[s.reverse_rotate])
			return (pile2[s.rotate]);
		else
			return (pile2[s.reverse_rotate]);
	}
}

int			find_closest(int *smallest, int n, int *pile2, t_index *index)
{
	t_rot	s;

	s.rotate = index->j;
	s.reverse_rotate = 1;
	s.nb_rotate = 0;
	s.nb_reverse_rotate = 1;
	while (ft_is_in_tab(smallest, n, pile2[s.rotate]) == 0)
	{
		(s.rotate)--;
		(s.nb_rotate)++;
	}
	while (ft_is_in_tab(smallest, n, pile2[s.reverse_rotate]) == 0)
	{
		(s.reverse_rotate)++;
		(s.nb_reverse_rotate)++;
	}
	return (ft_return(s, pile2));
}

int			find_max_in_pile2(int *pile2, t_index *index)
{
	int		i;
	int		max;

	max = 0;
	i = index->j;
	while (i > 0)
	{
		if (pile2[i] > max)
			max = pile2[i];
		i--;
	}
	return (max);
}

int			find_min_in_pile2(int *pile2, t_index *index)
{
	int		i;
	int		min;

	min = 1000;
	i = index->j;
	while (i > 0)
	{
		if (pile2[i] < min)
			min = pile2[i];
		i--;
	}
	return (min);
}
