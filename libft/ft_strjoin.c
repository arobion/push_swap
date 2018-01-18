/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:41:21 by arobion           #+#    #+#             */
/*   Updated: 2017/11/11 13:48:55 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		while (s1[i] != '\0')
			i++;
		while (s2[j] != '\0')
			j++;
	}
	i = i + j;
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (s1 && s2)
	{
		ft_strcat(str, s1);
		ft_strcat(str, s2);
	}
	str[i] = '\0';
	return (&str[0]);
}
