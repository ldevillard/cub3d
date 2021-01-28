/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:13:28 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/28 15:30:05 by ldevilla         ###   ########lyon.fr   */
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
	ft_fill_spcoord(values);
}

void	ft_fill_spcoord(t_pars *values)
{
	int i;
	int j;
	int k;
	values->data.posx = (double)4 + 0.5;
	values->data.posy = (double)3 + 0.5;
	i = 0;
	k = 0;
	while (i < values->nbrline && k < values->sp.count)
	{
		j = 0;
		while (values->map[i][j++])
			if (values->map[i][j] == '2')
			{
				values->spcoord[k].x = (double)j + 0.5;
				values->spcoord[k].y = (double)i + 0.5;
				values->spcoord[k].d = sqrt(((values->spcoord[k].x - values->data.posx)\
						* (values->spcoord[k].x - values->data.posx))\
						+ ((values->spcoord[k].y - values->data.posy)\
						* (values->spcoord[k].y - values->data.posy)));
				k++;
			}
		i++;
	}
	k = 0;
	while (k < values->sp.count)
	{
		printf("%f %f\n", values->data.posy, values->data.posy);
		printf("X : %f Y : %f of sp : %d\n", values->spcoord[k].x, values->spcoord[k].y, k + 1);
		printf("Dist %f\n", values->spcoord[k].d);
		k++;
	}
	/*DO THAT DURING THE RAYCAST BECAUSE 
	WE HAVE TO CALCULATE EACH FRAME THE SPRITE DIST
	AND HERE POSX AND POSY ARE UNINITIALIZED*/
}
