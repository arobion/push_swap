/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_do_instr3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:17:48 by arobion           #+#    #+#             */
/*   Updated: 2018/01/13 20:36:08 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instr_sa(int *pile1, t_index *n)
{
	int		tmp;

	if ((*n).i < (*n).argc - 1)
	{
		tmp = pile1[(*n).i];
		pile1[(*n).i] = pile1[(*n).i + 1];
		pile1[(*n).i + 1] = tmp;
	}
}

void	instr_sb(int *pile2, t_index *n)
{
	int		tmp;

	if ((*n).j > 0)
	{
		tmp = pile2[(*n).j];
		pile2[(*n).j] = pile2[(*n).j - 1];
		pile2[(*n).j - 1] = tmp;
	}
}

void	instr_ss(int *pile1, int *pile2, t_index *n)
{
	instr_sa(pile1, n);
	instr_sb(pile2, n);
}

void	instr_pa(int *pile1, int *pile2, t_index *n)
{
	if ((*n).j > -1)
	{
		(*n).i -= 1;
		pile1[(*n).i] = pile2[(*n).j];
		(*n).j -= 1;
	}
}

void	instr_pb(int *pile1, int *pile2, t_index *n)
{
	if ((*n).i < (*n).argc)
	{
		(*n).j += 1;
		pile2[(*n).j] = pile1[(*n).i];
		(*n).i += 1;
	}
}
