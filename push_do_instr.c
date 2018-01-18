/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_do_instr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:02:22 by arobion           #+#    #+#             */
/*   Updated: 2018/01/16 16:18:39 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_ra(int *pile1, t_index *n, t_datas *d)
{
	int		i;
	int		tmp;

	i = (*n).i;
	tmp = pile1[i];
	if (i < (*n).argc - 1)
		d->save[(d->save_index)++] = 5;
	while (i < (*n).argc - 1)
	{
		pile1[i] = pile1[i + 1];
		i++;
	}
	pile1[i] = tmp;
}

void	make_rb(int *pile2, t_index *n, t_datas *d)
{
	int		j;
	int		tmp;

	j = (*n).j;
	tmp = pile2[j];
	if (j > 1)
		d->save[(d->save_index)++] = 6;
	while (j > 1)
	{
		pile2[j] = pile2[j - 1];
		j--;
	}
	pile2[j] = tmp;
}

void	make_rr(int *pile1, int *pile2, t_index *n, t_datas *d)
{
	make_ra(pile1, n, d);
	make_rb(pile2, n, d);
}

void	make_rra(int *pile1, t_index *n, t_datas *d)
{
	int		i;
	int		tmp;

	d->save[(d->save_index)++] = 7;
	i = (*n).argc - 1;
	tmp = pile1[i];
	while (i > (*n).i)
	{
		pile1[i] = pile1[i - 1];
		i--;
	}
	pile1[i] = tmp;
}

void	make_rrb(int *pile2, t_index *n, t_datas *d)
{
	int		j;
	int		tmp;

	j = 1;
	tmp = pile2[j];
	d->save[(d->save_index)++] = 8;
	while (j < (*n).j)
	{
		pile2[j] = pile2[j + 1];
		j++;
	}
	pile2[j] = tmp;
}
