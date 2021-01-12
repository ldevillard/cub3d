/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:52:24 by ldevilla          #+#    #+#             */
/*   Updated: 2020/11/25 11:07:33 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	src_l;

	i = -1;
	j = -1;
	k = 0;
	src_l = ft_strlen(src);
	while (++i < dstsize && dst[k])
		k++;
	if (i == dstsize)
		return (i + src_l);
	while (src[++j])
		if (j < dstsize - i - 1)
			dst[k++] = src[j];
	dst[k] = '\0';
	return (i + j);
}
