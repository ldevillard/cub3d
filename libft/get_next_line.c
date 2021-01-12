/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:31:40 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/12 14:37:50 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(char *s1, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = 0;
	if (!s1)
	{
		if (!(str = malloc(sizeof(char) * 2)))
			return (0);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + 2))))
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s1);
	return (str);
}

int			get_next_line(char **line)
{
	char	buf;
	int		i;
	int		ret;

	ret = 0;
	if (!line)
		return (-1);
	if (!(*line = malloc(sizeof(char) * 1)))
		return (-1);
	*line[0] = 0;
	while ((i = read(0, &buf, 1)) && buf != '\n')
		*line = ft_join(*line, buf);
	if (!*line)
		*line = ft_join(*line, '\0');
	if (i > 0)
		ret = 1;
	return (ret);
}
