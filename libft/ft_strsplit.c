/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:36:13 by arobion           #+#    #+#             */
/*   Updated: 2017/12/19 14:28:20 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_count_size(char const *str, int *size_word, int c)
{
	int		i;
	int		size;
	int		j;

	j = 0;
	i = 0;
	size = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			if (str[i] != c)
				size++;
			if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			{
				size_word[j] = size;
				size = 0;
				j++;
			}
			i++;
		}
	}
}

static void	ft_duplicate(char const *str, char **tab, int c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			tab[j][k] = str[i];
			k++;
		}
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
		{
			tab[j][k] = str[i];
			tab[j][k++] = '\0';
			j++;
			k = 0;
		}
		i++;
	}
	tab[j] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	int		nb_word;
	int		*size_word;
	char	**tab;
	int		i;

	i = 0;
	nb_word = ft_count_word(s, c);
	if (!(size_word = malloc(sizeof(int) * (nb_word + 1))))
		return (NULL);
	ft_count_size(s, size_word, c);
	if (!(tab = malloc(sizeof(char *) * (nb_word + 1))))
		return (NULL);
	while (i < nb_word)
	{
		if (!(tab[i] = malloc(sizeof(char) * (size_word[i] + 1))))
			return (NULL);
		i++;
	}
	free(size_word);
	if (s)
		ft_duplicate(s, tab, c);
	return (tab);
}
