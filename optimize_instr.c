/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_instr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 13:00:44 by arobion           #+#    #+#             */
/*   Updated: 2018/01/18 13:33:54 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init(t_merge *m)
{
	m->ra = 0;
	m->rb = 0;
	m->rra = 0;
	m->rrb = 0;
	m->j = m->i + 1;
}

static void	ft_count_to_merge(char *save, t_merge *m)
{
	if (save[m->i + m->j] == 5)
		(m->ra)++;
	if (save[m->i + m->j] == 6)
		(m->rb)++;
	if (save[m->i + m->j] == 7)
		(m->rra)++;
	if (save[m->i + m->j] == 8)
		(m->rrb)++;
	(m->j)++;
}

void		ft_merging_instr(char *save, int save_index)
{
	t_merge	m;

	m.j = 0;
	m.i = 0;
	while (m.i < save_index)
	{
		if (save[m.i] == 3 || save[m.i] == 4)
		{
			ft_init(&m);
			while (save[m.i + m.j] != 4 && save[m.i + m.j] != 3\
					&& m.i + m.j < save_index)
				ft_count_to_merge(save, &m);
			m.diff_rr = m.ra;
			if (m.rb < m.ra)
				m.diff_rr = m.rb;
			m.diff_rrr = m.rra;
			if (m.rrb < m.rra)
				m.diff_rrr = m.rrb;
			ft_supp_doublons(save, m);
		}
		m.i++;
	}
}
