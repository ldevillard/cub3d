/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:07:48 by ldevilla          #+#    #+#             */
/*   Updated: 2020/11/24 09:38:13 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*source;
	unsigned char	*dest;
	unsigned char	charac;

	i = 0;
	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	charac = (unsigned char)c;
	while (i < n)
	{
		dest[i] = source[i];
		if (source[i] == charac)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
