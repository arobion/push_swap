/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorttab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:25:26 by arobion           #+#    #+#             */
/*   Updated: 2017/12/19 21:08:02 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sorttab(int *s, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	int				buffer;

	j = 0;
	i = 0;
	if (s)
	{
		while (i < n)
		{
			while (j < (n - 1))
			{
				if (s[j] > s[j + 1])
				{
					buffer = s[j];
					s[j] = s[j + 1];
					s[j + 1] = buffer;
				}
				j++;
			}
			j = 0;
			i++;
		}
	}
}
