/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:58:24 by arobion           #+#    #+#             */
/*   Updated: 2018/01/18 17:33:21 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cop(int *origine, int *tmp, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		tmp[i] = origine[i];
		i++;
	}
}

int		ft_transcription(int *tmp, int *origine, int nb)
{
	int		i;
	int		j;
	int		*buff;

	if (!(buff = malloc(sizeof(int) * nb)))
		return (0);
	ft_cop(origine, buff, nb);
	i = 0;
	while (i < nb)
	{
		j = 0;
		while (tmp[i] != buff[j])
			j++;
		origine[j] = i;
		i++;
	}
	free(buff);
	return (1);
}

int		ft_is_in_tab(int *tmp, int len, int to_find)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (tmp[i] == to_find)
			return (1);
		i++;
	}
	return (0);
}

void	ft_put_instr(char *save, int s)
{
	int		i;

	i = 0;
	while (i < s)
	{
		if (save[i] == 1)
			write(1, "sa\n", 3);
		if (save[i] == 3)
			write(1, "\033[35;01mpa\033[00m\n", 16);
		if (save[i] == 4)
			write(1, "\033[36;01mpb\033[00m\n", 16);
		if (save[i] == 5)
			write(1, "\033[32;01mra\033[00m\n", 16);
		if (save[i] == 6)
			write(1, "\033[33;01mrb\033[00m\n", 16);
		if (save[i] == 7)
			write(1, "\033[32;02mrra\033[00m\n", 17);
		if (save[i] == 8)
			write(1, "\033[33;02mrrb\033[00m\n", 17);
		if (save[i] == 9)
			write(1, "\033[34;06mrrr\033[00m\n", 17);
		if (save[i] == 10)
			write(1, "\033[34;01mrr\033[00m\n", 16);
		i++;
	}
}
