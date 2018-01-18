/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:22:50 by arobion           #+#    #+#             */
/*   Updated: 2017/11/29 16:03:30 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(char **s)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i] != NULL)
		{
			ft_putendl(s[i]);
			i++;
		}
	}
}
