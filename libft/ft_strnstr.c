/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:18:09 by arobion           #+#    #+#             */
/*   Updated: 2017/11/12 14:19:33 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*s2 == '\0')
		return ((char*)s1);
	while (s1[i] != '\0' && i < (int)n)
	{
		while (s1[i + j] == s2[j] && i + j < (int)n)
		{
			j++;
			if (s2[j] == '\0')
				return ((char*)&s1[i]);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
