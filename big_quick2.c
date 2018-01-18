/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_quick2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:31:00 by arobion           #+#    #+#             */
/*   Updated: 2018/01/18 13:31:30 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_for_norme_boucle1(int *pile1, int *pile2, t_index *index,\
		t_datas *d)
{
	if (pile1[index->i] >= d->encadreur &&\
			pile1[index->i] < d->encadreur + d->pack_size)
	{
		make_pb(pile1, pile2, index, d);
		(d->i)++;
	}
	else
		make_ra(pile1, index, d);
}

static void	ft_for_norme_boucle2(int *pile1, int *pile2, t_index *index,\
		t_datas *d)
{
	if (pile1[index->i] >= d->encadreur &&\
			pile1[index->i] < d->encadreur + d->pack_size)
	{
		make_pb(pile1, pile2, index, d);
		(d->i)++;
	}
	else
		make_rra(pile1, index, d);
}

void		ft_place_pack_in_pile2(int *pile1, int *pile2,\
		t_index *index, t_datas *d)
{
	d->i = 0;
	d->encadreur = index->argc - (d->nb_appel * d->pack_size);
	if (d->nb_appel == 4)
	{
		d->encadreur = 0;
		d->pack_size += index->argc % 4;
	}
	if (d->nb_appel == 1)
		while (d->i < d->pack_size)
			ft_for_norme_boucle1(pile1, pile2, index, d);
	else if (d->nb_appel > 1 && d->nb_appel < 4)
		while (pile1[index->i] !=\
				(index->argc - (d->nb_appel - 1) * d->pack_size))
			if (pile1[index->i] >= d->encadreur &&\
					pile1[index->i] < d->encadreur + d->pack_size)
				make_pb(pile1, pile2, index, d);
			else
				make_ra(pile1, index, d);
	else if (d->nb_appel == 4)
		while (d->i < d->pack_size)
			ft_for_norme_boucle2(pile1, pile2, index, d);
}
