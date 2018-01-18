/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorttab_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:48:28 by arobion           #+#    #+#             */
/*   Updated: 2017/11/13 16:15:09 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sorttab_char(char **tab_char)
{
	int		i;
	char	*buffer;
	int		j;

	i = 0;
	j = 0;
	if (tab_char)
	{
		while (tab_char[i] != NULL)
		{
			while (tab_char[j] != NULL)
			{
				if (ft_strcmp(tab_char[i], tab_char[j]) <= 0)
				{
					buffer = tab_char[i];
					tab_char[i] = tab_char[j];
					tab_char[j] = buffer;
				}
				j++;
			}
			i++;
			j = 0;
		}
	}
}
