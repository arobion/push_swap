/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:36:54 by arobion           #+#    #+#             */
/*   Updated: 2017/11/12 13:59:30 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*m1;
	unsigned char	*m2;

	i = 0;
	m1 = (unsigned char*)s1;
	m2 = (unsigned char*)s2;
	while (i < (unsigned int)n)
	{
		if (m1[i] != m2[i])
			return ((unsigned int)(m1[i] - m2[i]));
		i++;
	}
	return (0);
}
