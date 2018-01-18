/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_do_instr2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:16:13 by arobion           #+#    #+#             */
/*   Updated: 2018/01/13 18:26:49 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instr_ra(int *pile1, t_index *n)
{
	int		i;
	int		tmp;

	i = (*n).i;
	tmp = pile1[i];
	while (i < (*n).argc - 1)
	{
		pile1[i] = pile1[i + 1];
		i++;
	}
	pile1[i] = tmp;
}

void	instr_rb(int *pile2, t_index *n)
{
	int		j;
	int		tmp;

	j = (*n).j;
	tmp = pile2[j];
	while (j > 0)
	{
		pile2[j] = pile2[j - 1];
		j--;
	}
	pile2[j] = tmp;
}

void	instr_rr(int *pile1, int *pile2, t_index *n)
{
	instr_ra(pile1, n);
	instr_rb(pile2, n);
}

void	instr_rra(int *pile1, t_index *n)
{
	int		i;
	int		tmp;

	i = (*n).argc - 1;
	tmp = pile1[i];
	while (i > (*n).i)
	{
		pile1[i] = pile1[i - 1];
		i--;
	}
	pile1[i] = tmp;
}

void	instr_rrb(int *pile2, t_index *n)
{
	int		j;
	int		tmp;

	j = 0;
	tmp = pile2[j];
	while (j < (*n).j)
	{
		pile2[j] = pile2[j + 1];
		j++;
	}
	pile2[j] = tmp;
}
