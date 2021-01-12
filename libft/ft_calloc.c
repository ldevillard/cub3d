/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:23:45 by ldevilla          #+#    #+#             */
/*   Updated: 2020/11/27 11:36:43 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *to_alloc;

	to_alloc = malloc(count * size);
	if (to_alloc == NULL)
		return (NULL);
	ft_bzero(to_alloc, size * count);
	return (to_alloc);
}
