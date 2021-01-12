/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:53:24 by ldevilla          #+#    #+#             */
/*   Updated: 2020/11/24 09:57:56 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	charac;
	unsigned int	i;

	str = (unsigned char *)s;
	charac = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == charac)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
