/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_do_instr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:13:27 by arobion           #+#    #+#             */
/*   Updated: 2018/01/18 17:51:02 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_make2(int *pile1, int *pile2, char *line, t_index *n)
{

	if (ft_strcmp(line, "rr") == 0 ||\
			ft_strcmp(line, "\033[34;01mrr\033[00m") == 0)
		instr_rr(pile1, pile2, n);
	else if (ft_strcmp(line, "rra") == 0 ||\
			ft_strcmp(line, "\033[32;02mrra\033[00m") == 0)
		instr_rra(pile1, n);
	else if (ft_strcmp(line, "rrb") == 0 ||\
			ft_strcmp(line, "\033[33;02mrrb\033[00m") == 0)
		instr_rrb(pile2, n);
	else if (ft_strcmp(line, "rrr") == 0 ||\
			ft_strcmp(line, "\033[34;06mrrr\033[00m") == 0)
		instr_rrr(pile1, pile2, n);
	else
		return (0);
	return (1);
}

static int	ft_make(int *pile1, int *pile2, char *line, t_index *n)
{
	if (ft_strcmp(line, "sa") == 0)
		instr_sa(pile1, n);
	else if (ft_strcmp(line, "sb") == 0)
		instr_sb(pile2, n);
	else if (ft_strcmp(line, "ss") == 0)
		instr_ss(pile1, pile2, n);
	else if (ft_strcmp(line, "pa") == 0 ||\
			ft_strcmp(line, "\033[35;01mpa\033[00m") == 0)
		instr_pa(pile1, pile2, n);
	else if (ft_strcmp(line, "pb") == 0 ||\
			ft_strcmp(line, "\033[36;01mpb\033[00m") == 0)
		instr_pb(pile1, pile2, n);
	else if (ft_strcmp(line, "ra") == 0 ||\
			ft_strcmp(line, "\033[32;01mra\033[00m") == 0)
		instr_ra(pile1, n);
	else if (ft_strcmp(line, "rb") == 0 ||\
			ft_strcmp(line, "\033[33;01mrb\033[00m") == 0)
		instr_rb(pile2, n);
	else
		return (ft_make2(pile1, pile2, line, n));
	return (1);
}

static int	ft_check_sort(int *pile1, int argc, t_index n)
{
	int		i;

	i = 0;
	if (n.j != -1)
		return (0);
	while (i < argc - 1)
	{
		if (pile1[i] > pile1[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	free_false(int *pile2, char *line)
{
	free(pile2);
	free(line);
	return (-1);
}

int			do_instr(int *pile1, int argc)
{
	int		*pile2;
	char	*line;
	t_index	n;

	n.i = 0;
	n.j = -1;
	n.argc = argc;
	if (!(pile2 = malloc(sizeof(int) * argc)))
		return (0);
	while (get_next_line(0, &line) == 1)
	{
		if (!(ft_make(pile1, pile2, line, &n)))
			return (free_false(pile2, line));
		free(line);
	}
	if (!(ft_check_sort(pile1, argc, n)))
	{
		free(pile1);
		free(pile2);
		return (0);
	}
	free(pile1);
	free(pile2);
	return (1);
}
