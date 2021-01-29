/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:09:35 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/29 11:01:45 by ldevilla         ###   ########lyon.fr   */
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
	/*
    k = 0;//RM
    while (k < values->sp.count)//RM
    {
        printf("Dist %f of %d sprite\n", values->spcoord[k].d, k + 1);//RM
        k++;//RM
    }//RM*/
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
	values->sp.spritex = values->spcoord[values->sp.order[i]].x - values->data.posx;
    values->sp.spritey = values->spcoord[values->sp.order[i]].y - values->data.posy;
	values->sp.invdet = 1.0 / (values->data.planex * values->data.diry -
			values->data.dirx * values->data.planey);
	values->sp.transformx = values->sp.invdet * (values->data.diry *
			values->sp.spritex - values->data.dirx * values->sp.spritey);
	values->sp.transformy = values->sp.invdet * (-values->data.planey *
			values->sp.spritex + values->data.planex * values->sp.spritey);
	values->sp.spritescreenx = (int)((values->resx / 2) * (1 + values->sp.transformx
				/ values->sp.transformy));
	values->sp.spriteheight = abs((int)(values->resy / (values->sp.transformy)));
	values->sp.drawstarty = -values->sp.spriteheight / 2 + values->resy / 2;
	if (values->sp.drawstarty < 0)
		values->sp.drawstarty = 0;
	values->sp.drawendy = values->sp.spriteheight / 2 + values->resy / 2;
	if (values->sp.drawendy >= values->resy)
		values->sp.drawendy = values->resy;
	values->sp.spritewidth = abs((int)(values->resy / (values->sp.transformy)));
	values->sp.drawstartx = -values->sp.spritewidth / 2 + values->sp.spritescreenx;
	if (values->sp.drawstartx < 0)
		values->sp.drawstartx = 0;
	values->sp.drawendx = values->sp.spritewidth / 2 + values->sp.spritescreenx;
	if (values->sp.drawendx >= values->resx)
		values->sp.drawendx = values->resx;
}

void	ft_draw_sprite(t_pars *values, int j, int texx, int stripe)
{
	int		d;
	int		texy;

	while (j < values->sp.drawendy)
	{
		d = (j) * 256 - values->resy * 128 + values->sp.spriteheight * 128;
		texy = ((d * values->texdata[4].height) / values->sp.spriteheight) / 256;
		if (values->texdata[4].addr[texy *\
				values->texdata[4].line_length + texx *\
				(values->texdata[4].bits_per_pixel) / 8])
		{
			values->data.addr[j * values->data.line_length + stripe *\
					(values->data.bits_per_pixel) / 8] =
			values->texdata[4].addr[texy *\
				values->texdata[4].line_length + texx *\
				(values->texdata[4].bits_per_pixel) / 8];
			values->data.addr[j * values->data.line_length + stripe *\
					(values->data.bits_per_pixel) / 8 + 1] =
			values->texdata[4].addr[texy *\
				values->texdata[4].line_length + texx *\
				(values->texdata[4].bits_per_pixel) / 8 + 1];
			values->data.addr[j * values->data.line_length + stripe *\
					(values->data.bits_per_pixel) / 8 + 2] =
			values->texdata[4].addr[texy *\
				values->texdata[4].line_length + texx *\
				(values->texdata[4].bits_per_pixel) / 8 + 2];
			values->data.addr[j * values->data.line_length + stripe *\
					(values->data.bits_per_pixel) / 8 + 3] =
			values->texdata[4].addr[texy *\
				values->texdata[4].line_length + texx *\
				(values->texdata[4].bits_per_pixel) / 8 + 3];
		}
		j++;
	}
}

void	ft_sprite(t_pars *values, int *x)
{
	int i;
	int j;
	int stripe;
	int texx;
(void)x;
	i = 0;
	ft_treat_sprites(values);
	while (i < values->sp.count)
	{
		ft_matrix(values, i);
		stripe = values->sp.drawstartx;
		while (stripe < values->sp.drawendx)
		{
			texx = (int)(256 * (stripe - (-values->sp.spritewidth / 2 +
							values->sp.spritescreenx)) * values->texdata[4].width
					/ values->sp.spritewidth) / 256;
			if (values->sp.transformy > 0 && stripe >= 0 && stripe < values->resx
					&& values->sp.transformy < values->sp.walldist[stripe])
			{
				j = values->sp.drawstarty;
				ft_draw_sprite(values, j, texx, stripe);
			}
			stripe++;
		}
		i++;
	}
}