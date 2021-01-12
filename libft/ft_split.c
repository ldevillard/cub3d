/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:02:13 by ldevilla          #+#    #+#             */
/*   Updated: 2020/11/27 14:23:52 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		wc(char const *s, char c)
{
	int word;
	int i;

	word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			word++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (word);
}

static int		wl(char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i] != c && s[i])
	{
		i++;
		size++;
	}
	return (size);
}

static void		*free_tab(char **tab, int words)
{
	int	i;

	i = 0;
	while (i < words)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static char		**cut(char const *s, int words, char c, char **tab)
{
	int	i;
	int	j;
	int	w_size;
	int k;

	i = 0;
	k = 0;
	while (i < words)
	{
		while (s[k] == c)
			k++;
		w_size = wl(&s[k], c);
		if (!(tab[i] = malloc(sizeof(char) * (w_size + 1))))
			return (free_tab(tab, i));
		j = 0;
		while (j < w_size)
			tab[i][j++] = s[k++];
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char			**ft_split(char	const *s, char c)
{
	char	**tab;
	int		words;

	if (!s)
		return (NULL);
	words = wc(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	tab = cut(s, words, c, tab);
	return (tab);
}
