/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:47:10 by arobion           #+#    #+#             */
/*   Updated: 2017/11/12 13:53:21 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t size)
{
	unsigned int	i;
	unsigned char	*m1;
	unsigned char	*m2;

	i = 0;
	m1 = (unsigned char*)s1;
	m2 = (unsigned char*)s2;
	while (m1[i] != '\0' && m2[i] != '\0' && m1[i] == m2[i] \
			&& i < (unsigned int)size)
		i++;
	if (size == 0)
		return (0);
	if (i == size)
		return ((unsigned int)(m1[i - 1] - m2[i - 1]));
	return ((unsigned int)(m1[i] - m2[i]));
}
