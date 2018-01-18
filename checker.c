/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:15:14 by arobion           #+#    #+#             */
/*   Updated: 2018/01/18 16:57:47 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_norme(char **av, char **argv, int **pile, int argc)
{
	int		j;

	j = 0;
	if (!(av = ft_strsplit(argv[1], ' ')))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	while (av[j] != 0)
		j++;
	if (!(*pile = ft_parsing_swap(j + 1, av)))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	argc = j + 1;
	ft_free_double_tab(av);
	return (argc);
}

int		main(int argc, char **argv)
{
	int		*pile;
	int		i;
	char	**av;

	av = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		argc = ft_norme(av, argv, &pile, argc);
	else
	{
		if (!(pile = ft_parsing(argc, argv)))
			return (write(1, "Error\n", 6));
	}
	if ((i = do_instr(pile, argc - 1)) == 1)
		return (write(1, "OK\n", 3));
	else if (i == 0)
		write(1, "KO\n", 3);
	else if (i == -1)
		write(1, "Error\n", 6);
	return (1);
}
