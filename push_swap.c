/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 12:27:59 by arobion           #+#    #+#             */
/*   Updated: 2018/01/18 14:43:14 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_norminette(char **av, char **argv, int **pile, int argc)
{
	int		i;

	i = 0;
	if (!(av = ft_strsplit(argv[1], ' ')))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	while (av[i] != 0)
		i++;
	if (!(*pile = ft_parsing_swap(i + 1, av)))
	{
		ft_free_double_tab(av);
		write(1, "Error\n", 6);
		exit(0);
	}
	argc = i + 1;
	ft_free_double_tab(av);
	return (argc);
}

int		main(int argc, char **argv)
{
	int		*pile;
	char	**av;

	if (argc == 1)
		return (write(1, "Error\n", 6));
	if (argc == 2)
		argc = ft_norminette(av, argv, &pile, argc);
	else
	{
		if (!(pile = ft_parsing(argc, argv)))
			return (write(1, "Error\n", 6));
	}
	ft_push_swap(pile, argc - 1);
	free(pile);
	return (0);
}
