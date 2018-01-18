/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reput_to_pile1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 13:24:39 by arobion           #+#    #+#             */
/*   Updated: 2018/01/18 13:36:00 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reput_sorted_to_pile1_for_small2(int *pile1, int *pile2,\
		t_index *index, t_datas *d)
{
	d->med = d->pack_size;
	d->encadreur = d->pack_size;
	d->x = d->encadreur;
	d->to_put = find_closest_in_the_n_biggest_to_x(pile2, index, 6, d->x);
	d->n = 6;
	while (d->to_put >= d->encadreur - d->med + 3)
		ft_norme_boucle1(pile1, pile2, index, d);
	d->x = d->encadreur - d->med - 2;
	d->to_put = find_closest_in_the_n_smallest_from_x(pile2, index, 5, d->x);
	d->n = 5;
	while (d->to_put < find_max_in_pile2(pile2, index) - 2)
		ft_norme_boucle2(pile1, pile2, index, d);
	d->x = d->encadreur + d->med + 2;
	d->n = 1;
	while (index->j > 0)
		ft_norme_boucle4(pile1, pile2, index, d);
}

void	ft_reput_sorted_to_pile1_for_small(int *pile1, int *pile2,\
		t_index *index, t_datas *d)
{
	d->med = d->pack_size;
	d->x = d->encadreur;
	d->to_put = find_closest_in_the_n_biggest_to_x(pile2, index, 6, d->x);
	d->n = 6;
	while (d->to_put >= d->encadreur - d->med + 3)
		ft_norme_boucle1(pile1, pile2, index, d);
	d->x = d->encadreur - d->med - 2;
	d->to_put = find_closest_in_the_n_smallest_from_x(pile2, index, 5, d->x);
	d->n = 5;
	while (d->to_put < find_max_in_pile2(pile2, index) - 2)
		ft_norme_boucle2(pile1, pile2, index, d);
	d->x = d->encadreur + d->med + 2;
	d->to_put = find_closest_in_the_n_biggest_to_x(pile2, index, 5, d->x);
	d->n = 5;
	while (d->to_put >= find_min_in_pile2(pile2, index) + 2)
		ft_norme_boucle3(pile1, pile2, index, d);
	d->x = d->encadreur - d->med - 2;
	d->n = 1;
	while (index->j > 0)
		ft_norme_boucle4bis(pile1, pile2, index, d);
}

void	ft_reput_sorted_to_pile1(int *pile1, int *pile2,\
		t_index *index, t_datas *d)
{
	int		to_place;

	d->med = d->pack_size / 2;
	d->x = d->encadreur;
	d->to_put = find_closest_in_the_n_biggest_to_x(pile2, index, 6, d->x);
	d->n = 6;
	while (d->to_put >= d->encadreur - d->med + 3)
		ft_norme_boucle1(pile1, pile2, index, d);
	d->x = d->encadreur - d->med - 2;
	d->to_put = find_closest_in_the_n_smallest_from_x(pile2, index, 5, d->x);
	d->n = 5;
	while (d->to_put < find_max_in_pile2(pile2, index) - 2)
		ft_norme_boucle2(pile1, pile2, index, d);
	d->x = d->encadreur + d->med + 2;
	d->to_put = find_closest_in_the_n_biggest_to_x(pile2, index, 5, d->x);
	d->n = 5;
	while (d->to_put > find_min_in_pile2(pile2, index) + 2)
		ft_norme_boucle3(pile1, pile2, index, d);
	d->x = d->encadreur - d->med - 2;
	d->to_put = find_closest_in_the_n_smallest_from_x(pile2, index, 1, d->x);
	d->n = 1;
	while (index->j > 0)
		ft_norme_boucle4bis(pile1, pile2, index, d);
}
