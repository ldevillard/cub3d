/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:01:34 by ldevilla          #+#    #+#             */
/*   Updated: 2020/11/24 14:28:44 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ds1;
	unsigned char	*ds2;

	ds1 = (unsigned char *)s1;
	ds2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (ds1[i] && ds2[i] && ds1[i] == ds2[i] && i < n - 1)
		i++;
	return (ds1[i] - ds2[i]);
}
