/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_do_instr3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:12:54 by arobion           #+#    #+#             */
/*   Updated: 2018/01/16 16:20:38 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_rrr(int *pile1, int *pile2, t_index *n, t_datas *d)
{
	make_rra(pile1, n, d);
	make_rrb(pile2, n, d);
}
