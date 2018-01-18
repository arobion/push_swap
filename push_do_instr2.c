/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_do_instr2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:07:42 by arobion           #+#    #+#             */
/*   Updated: 2018/01/16 16:20:18 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_sa(int *pile1, t_index *n, t_datas *d)
{
	int		tmp;

	d->save[(d->save_index)++] = 1;
	if ((*n).i < (*n).argc - 1)
	{
		tmp = pile1[(*n).i];
		pile1[(*n).i] = pile1[(*n).i + 1];
		pile1[(*n).i + 1] = tmp;
	}
}

void	make_sb(int *pile2, t_index *n, t_datas *d)
{
	int		tmp;

	d->save[(d->save_index)++] = 2;
	if ((*n).j > 0)
	{
		tmp = pile2[(*n).j];
		pile2[(*n).j] = pile2[(*n).j - 1];
		pile2[(*n).j - 1] = tmp;
	}
}

void	make_ss(int *pile1, int *pile2, t_index *n, t_datas *d)
{
	make_sa(pile1, n, d);
	make_sb(pile2, n, d);
}

void	make_pa(int *pile1, int *pile2, t_index *n, t_datas *d)
{
	d->save[(d->save_index)++] = 3;
	if ((*n).j > -1)
	{
		(*n).i -= 1;
		pile1[(*n).i] = pile2[(*n).j];
		(*n).j -= 1;
	}
}

void	make_pb(int *pile1, int *pile2, t_index *n, t_datas *d)
{
	d->save[(d->save_index)++] = 4;
	if ((*n).i < (*n).argc)
	{
		(*n).j += 1;
		pile2[(*n).j] = pile1[(*n).i];
		(*n).i += 1;
	}
}
