/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:13:28 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/29 10:22:50 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_spcoord(t_pars *values)
{
	int i;
	int j;

	i = 0;
	values->sp.count = 0;
	while (i < values->nbrline)
	{
		j = 0;
		while (values->map[i][j++])
			if (values->map[i][j] == '2')
				values->sp.count++;
		i++;
	}
	if (!(values->spcoord = malloc(sizeof(t_spcoord) * values->sp.count)))
		ft_error("Error while malloc", values);
	if (!(values->sp.order = malloc(sizeof(int) * values->sp.count)))
		ft_error("Error while malloc", values);
	if (!(values->sp.walldist = malloc(sizeof(double) * values->resx)))
		ft_error("Error while malloc", values);
	ft_fill_spcoord(values);
}

void	ft_fill_spcoord(t_pars *values)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < values->nbrline && k < values->sp.count)
	{
		j = 0;
		while (values->map[i][j++])
			if (values->map[i][j] == '2')
			{
				values->spcoord[k].x = (double)i + 0.5;
				values->spcoord[k].y = (double)j + 0.5;
				k++;
			}
		i++;
	}
}
