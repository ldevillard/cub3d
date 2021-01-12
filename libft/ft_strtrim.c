/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:15:26 by ldevilla          #+#    #+#             */
/*   Updated: 2020/11/27 13:11:09 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sep_check(char const *s1, char const *set)
{
	int i;
	int j;
	int nop;

	nop = 0;
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (!(ft_ccheck(set, s1[i])))
			nop = 1;
		if (nop == 1)
			return (1);
		i++;
	}
	return (0);
}

static int		set_count(int count, char const *s1, char const *set)
{
	int i;

	i = 0;
	count = 0;
	while (s1[i])
	{
		if (ft_ccheck(set, s1[i]) == 1)
			count++;
		else
			break ;
		i++;
	}
	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		if (ft_ccheck(set, s1[i]) == 1)
			count++;
		else
			break ;
		i--;
	}
	return (count);
}

static char		*nullstr(char *str)
{
	if (!(str = malloc(sizeof(char) * 1)))
		return (NULL);
	str[0] = '\0';
	return (str);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		count;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	j = 0;
	i = 0;
	count = 0;
	count = set_count(count, s1, set);
	str = NULL;
	if (sep_check(s1, set) == 0)
		return (nullstr(str));
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) - count + 1))))
		return (NULL);
	i = 0;
	while (ft_ccheck(set, s1[i]) == 1)
		i++;
	while (j < (int)(ft_strlen(s1) - count))
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
