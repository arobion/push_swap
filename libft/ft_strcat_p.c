/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:38:44 by arobion           #+#    #+#             */
/*   Updated: 2017/11/16 12:21:09 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat_p(char *dest, const char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (dest && src)
	{
		while (dest[i] != '\0')
			i++;
		while (src[j] != '\0')
		{
			dest[i] = src[j];
			i++;
			j++;
		}
		if (src[j] == '\0')
			dest[i] = src[j];
		return (dest);
	}
	return (NULL);
}
