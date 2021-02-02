/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:09:35 by ldevilla          #+#    #+#             */
/*   Updated: 2021/02/02 11:10:57 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_treat_sprites(t_pars *values)
{
	int k;

	k = 0;
	while (k < values->sp.count)
	{
		values->sp.order[k] = k;
		values->spcoord[k].d = sqrt(((values->data.posx - values->spcoord[k].x)\
				* (values->data.posx - values->spcoord[k].x))\
				+ ((values->data.posy - values->spcoord[k].y)\
				* (values->data.posy - values->spcoord[k].y)));
		k++;
	}
	ft_set_sp_order(values);
}

void	ft_set_sp_order(t_pars *values)
{
	int		i;
	int		j;
	double	tmp;

	i = 0;
	while (i < values->sp.count)
	{
		j = i + 1;
		while (j < values->sp.count)
		{
			if (values->spcoord[i].d < values->spcoord[j].d)
			{
				tmp = values->spcoord[i].d;
				values->spcoord[i].d = values->spcoord[j].d;
				values->spcoord[j].d = tmp;
				tmp = values->sp.order[i];
				values->sp.order[i] = values->sp.order[j];
				values->sp.order[j] = (int)tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_matrix(t_pars *values, int i)
{
	values->sp.spritex = values->spcoord[values->sp.order[i]].x\
			- values->data.posx;
	values->sp.spritey = values->spcoord[values->sp.order[i]].y -\
			values->data.posy;
	values->sp.invdet = 1.0 / (values->data.planex *\
			values->data.diry -
			values->data.dirx * values->data.planey);
	values->sp.transformx = values->sp.invdet * (values->data.diry *
			values->sp.spritex - values->data.dirx *\
			values->sp.spritey);
	values->sp.transformy = values->sp.invdet * (-values->data.planey *
			values->sp.spritex + values->data.planex * values->sp.spritey);
	values->sp.spritescreenx = (int)((values->resx / 2) *\
			(1 + values->sp.transformx
				/ values->sp.transformy));
	values->sp.spriteheight = abs((int)(values->resy /\
			(values->sp.transformy)));
	values->sp.drawstarty = -values->sp.spriteheight /\
			2 + values->resy / 2;
	if (values->sp.drawstarty < 0)
		values->sp.drawstarty = 0;
	values->sp.drawendy = values->sp.spriteheight / 2 + values->resy / 2;
	ft_matrix_two(values);
}

void	ft_draw_sprite(t_pars *values, int j, int texx, int stripe)
{
	int		d;
	int		texy;

	while (j < values->sp.drawendy)
	{
		d = (j) * 256 - values->resy * 128 + values->sp.spriteheight * 128;
		texy = ((d * values->texdata[4].height) /\
				values->sp.spriteheight) / 256;
		if (values->texdata[4].addr[texy *\
				values->texdata[4].line_length + texx *\
				(values->texdata[4].bits_per_pixel) / 8])
			set_sp_addr(values, j, texx, stripe);
		j++;
	}
}

void	ft_sprite(t_pars *values)
{
	int i;
	int j;
	int stripe;
	int texx;

	i = 0;
	j = 0;
	texx = 0;
	ft_treat_sprites(values);
	while (i < values->sp.count)
	{
		ft_matrix(values, i);
		stripe = values->sp.drawstartx;
		while (stripe < values->sp.drawendx)
		{
			ft_buf_draw_sp(values, j, texx, stripe);
			stripe++;
		}
		i++;
	}
}
