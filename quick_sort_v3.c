/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_v3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:13:55 by arobion           #+#    #+#             */
/*   Updated: 2018/01/18 12:05:54 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_launch_big(int *pile1, int *pile2, t_index *index, t_datas *d)
{
	ft_place_pack_in_pile2(pile1, pile2, index, d);
	ft_replace_pack_in_pile1(pile1, pile2, index, d);
	d->nb_appel += 1;
	ft_place_pack_in_pile2(pile1, pile2, index, d);
	ft_replace_pack_in_pile1(pile1, pile2, index, d);
	d->nb_appel += 1;
	ft_place_pack_in_pile2(pile1, pile2, index, d);
	ft_replace_pack_in_pile1(pile1, pile2, index, d);
	d->nb_appel += 1;
	ft_place_pack_in_pile2(pile1, pile2, index, d);
	ft_replace_pack_in_pile1(pile1, pile2, index, d);
}

int			ft_quick_sort_big(int *pile1, int nb)
{
	int		*pile2;
	t_index	index;
	t_datas	d;

	if (!(d.save = malloc(sizeof(char) * 100000)))
		return (-1);
	if (!(pile2 = malloc(sizeof(int) * nb + 1)))
		return (-1);
	index.i = 0;
	index.j = 0;
	index.argc = nb;
	d.pack_size = nb / 4;
	d.save_index = 0;
	d.nb_appel = 1;
	ft_launch_big(pile1, pile2, &index, &d);
	while (pile1[index.i] != 0)
		make_rra(pile1, &index, &d);
	ft_merging_instr(d.save, d.save_index);
	ft_put_instr(d.save, d.save_index);
	free(pile2);
	free(d.save);
	return (1);
}

static void	ft_lauch_small(int *pile1, int *pile2,\
		t_index *index, t_datas *d)
{
	ft_place_pack_in_pile2_for_small(pile1, pile2, index, d);
	ft_replace_pack_in_pile1_for_small(pile1, pile2, index, d);
	d->nb_appel += 1;
	ft_place_pack_in_pile2_for_small(pile1, pile2, index, d);
	ft_replace_pack_in_pile1_for_small(pile1, pile2, index, d);
}

int			ft_quick_sort_small(int *pile1, int nb)
{
	int		*pile2;
	t_datas	d;
	t_index	index;

	if (!(d.save = malloc(sizeof(char) * 100000)))
		return (-1);
	if (!(pile2 = malloc(sizeof(int) * nb + 1)))
		return (-1);
	index.i = 0;
	index.j = 0;
	index.argc = nb;
	d.pack_size = nb / 2;
	d.save_index = 0;
	d.nb_appel = 1;
	ft_lauch_small(pile1, pile2, &index, &d);
	while (pile1[index.i] != 0)
		make_rra(pile1, &index, &d);
	ft_merging_instr(d.save, d.save_index);
	ft_put_instr(d.save, d.save_index);
	free(d.save);
	free(pile2);
	return (1);
}
