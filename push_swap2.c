/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:36:04 by arobion           #+#    #+#             */
/*   Updated: 2018/01/18 14:37:33 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_for_sorted_tab(int *pile1, int nb)
{
	t_index index;
	t_datas d;

	index.i = 0;
	index.argc = nb;
	if (!(d.save = malloc(sizeof(char) * 10000)))
		exit(0);
	d.save_index = 0;
	ft_sort(pile1, &index, &d);
	free(d.save);
	ft_put_instr(d.save, d.save_index);
}

int		ft_verif_sort(int *pile1, int nb)
{
	t_index index;

	index.i = 0;
	index.argc = nb;
	if (ft_is_sort(pile1, index) == 1)
		return (1);
	return (0);
}

void	ft_launch(int *origine, int nb)
{
	if (ft_verif_sort(origine, nb) == 1)
		ft_for_sorted_tab(origine, nb);
	else if (nb == 3)
		ft_sort_for_three_nbrs(origine, nb);
	else if (nb <= 50)
		ft_sort_for_less_ten(origine, nb);
	else if (nb <= 200)
		ft_quick_sort_small(origine, nb);
	else if (nb > 200)
		ft_quick_sort_big(origine, nb);
}

void	ft_push_swap(int *origine, int nb)
{
	int		*tmp;
	char	*save;

	if (!(save = malloc(sizeof(char ) * 100000)))
		exit(0);
	if (!(tmp = malloc(sizeof(int) * nb)))
		exit(0);
	ft_cop(origine, tmp, nb);
	ft_sorttab(tmp, nb);
	if (!(ft_transcription(tmp, origine, nb)))
		exit(0);
	ft_launch(origine, nb);
	free(save);
	free(tmp);
}
