/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:00:26 by arobion           #+#    #+#             */
/*   Updated: 2017/11/11 19:08:31 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*m;
	unsigned int	i;
	unsigned char	*d;

	d = dest;
	m = (void*)src;
	i = 0;
	while (i < n)
	{
		d[i] = m[i];
		i++;
	}
	return (dest);
}
