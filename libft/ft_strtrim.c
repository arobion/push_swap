/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:49:02 by arobion           #+#    #+#             */
/*   Updated: 2017/11/12 15:54:39 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	int				j;
	char			*str;

	i = 0;
	j = 0;
	str = NULL;
	if (s)
	{
		while (s[i] && (s[i] == '\t' || s[i] == '\n' || s[i] == ' '))
			i++;
		j = ft_strlen(s);
		j--;
		while ((int)i < j && (s[j] == '\t' || s[j] == '\n' || s[j] == ' '))
			j--;
		if (!(str = ft_strsub(s, i, j - i + 1)))
			return (NULL);
	}
	return (str);
}
