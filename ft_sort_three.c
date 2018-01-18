/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:37:34 by arobion           #+#    #+#             */
/*   Updated: 2018/01/18 14:05:58 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_norme_sort(int i, int nb, int *tmp)
{
	while (i < nb - 1)
	{
		if (tmp[i] > tmp[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int			ft_is_sort(int *pile, t_index n)
{
	int		*tmp;
	int		min;
	int		i;

	if (!(tmp = malloc(sizeof(int) * n.argc)))
		return (0);
	ft_cop(pile, tmp, n.argc);
	min = pile[n.i];
	i = n.i;
	while (i < n.argc)
	{
		if (pile[i] < min)
			min = pile[i];
		i++;
	}
	while (tmp[n.i] != min)
		instr_ra(tmp, &n);
	i = n.i;
	i = ft_norme_sort(i, n.argc, tmp);
	free(tmp);
	return (i);
}

void		ft_sort(int *pile, t_index *n, t_datas *d)
{
	int		min;
	int		i;

	i = n->i;
	min = pile[n->i];
	while (i < n->argc)
	{
		if (pile[i] < min)
			min = pile[i];
		i++;
	}
	while (pile[n->i] != min)
		make_ra(pile, n, d);
}

void		ft_sort_for_three_nbrs(int *pile1, int nb)
{
	t_index index;
	t_datas	d;

	if (!(d.save = malloc(sizeof(char) * 10)))
		return ;
	d.save_index = 0;
	index.i = 0;
	index.argc = nb;
	if (ft_is_sort(pile1, index) == 1)
		ft_sort(pile1, &index, &d);
	else if (pile1[0] == 0)
	{
		write(1, "sa\n", 3);
		write(1, "ra\n", 3);
	}
	else if (pile1[0] == 1)
		write(1, "sa\n", 3);
	else if (pile1[0] == 2)
	{
		write(1, "sa\n", 3);
		write(1, "rra\n", 4);
	}
	free(d.save);
	ft_put_instr(d.save, d.save_index);
}
