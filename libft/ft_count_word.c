/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:52:14 by arobion           #+#    #+#             */
/*   Updated: 2017/11/13 10:59:34 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_word(char const *str, int c)
{
	int		i;
	int		nb_word;

	nb_word = 0;
	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
				nb_word++;
			i++;
		}
	}
	return (nb_word);
}
