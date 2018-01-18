/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_road_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:17:16 by arobion           #+#    #+#             */
/*   Updated: 2018/01/17 17:54:08 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sim_rb(int *pile, int j, int sommet)
{
	int		tmp;
	int		i;
	int		buff;

	i = 0;
	while (pile[j] != sommet)
	{
		buff = j;
		tmp = pile[j];
		while (j > 0)
		{
			pile[j] = pile[j - 1];
			j--;
		}
		pile[j] = tmp;
		j = buff;
		i++;
	}
	return (i);
}

void	rrb(int *pile2, t_index *n)
{
	int		j;
	int		tmp;

	j = 1;
	tmp = pile2[j];
	while (j < (*n).j)
	{
		pile2[j] = pile2[j + 1];
		j++;
	}
	pile2[j] = tmp;
}

int		sim_rrb(int *pile, int j, int sommet)
{
	int		i;
	t_index n;

	n.j = j;
	i = 0;
	if (j > 1)
	{
		while (pile[j] != sommet)
		{
			rrb(pile, &n);
			i++;
		}
	}
	return (i);
}

void	ft_find_road_b(int to_find, int *pile2, t_index *n, t_datas *d)
{
	int		i;
	int		j;
	int		*tmp;
	int		*tmp2;

	if (!(tmp = malloc(sizeof(int) * n->argc)))
		return ;
	if (!(tmp2 = malloc(sizeof(int) * n->argc)))
		return ;
	ft_cop(pile2, tmp, n->argc);
	ft_cop(pile2, tmp2, n->argc);
	i = n->i;
	j = n->j;
	if (sim_rb(tmp, j, to_find) > sim_rrb(tmp2, j, to_find))
	{
		while (pile2[n->j] != to_find)
			make_rrb(pile2, n, d);
	}
	else
	{
		while (pile2[n->j] != to_find)
			make_rb(pile2, n, d);
	}
	free(tmp);
	free(tmp2);
}
