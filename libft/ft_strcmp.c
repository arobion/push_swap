/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:32:56 by arobion           #+#    #+#             */
/*   Updated: 2017/11/11 17:01:24 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*m1;
	unsigned char	*m2;

	m1 = (unsigned char*)s1;
	m2 = (unsigned char*)s2;
	i = 0;
	while (m1[i] != '\0' && m2[i] != '\0' && m1[i] == m2[i])
		i++;
	return ((unsigned int)(m1[i] - m2[i]));
}
