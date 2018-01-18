/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_unsigned_var.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:07:02 by arobion           #+#    #+#             */
/*   Updated: 2017/12/08 19:08:13 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_unsigned_var(unsigned long int var)
{
	int		i;

	i = 0;
	if (var == 0)
		return (1);
	while (var != 0)
	{
		var /= 10;
		i++;
	}
	return (i);
}
