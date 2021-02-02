/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:48:30 by ldevilla          #+#    #+#             */
/*   Updated: 2021/02/02 11:08:03 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_sp_addr(t_pars *values, int j, int texx, int stripe)
{
	int		d;
	int		texy;

	d = (j) * 256 - values->resy * 128 + values->sp.spriteheight * 128;
	texy = ((d * values->texdata[4].height) /\
			values->sp.spriteheight) / 256;
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
}

void	ft_buf_draw_sp(t_pars *values, int j, int texx, int stripe)
{
	texx = (int)(256 * (stripe - (-values->sp.spritewidth / 2 +
					values->sp.spritescreenx)) *\
			values->texdata[4].width
			/ values->sp.spritewidth) / 256;
	if (values->sp.transformy > 0 && stripe >= 0
			&& stripe < values->resx
			&& values->sp.transformy < values->sp.walldist[stripe])
	{
		j = values->sp.drawstarty;
		ft_draw_sprite(values, j, texx, stripe);
	}
}

void	ft_matrix_two(t_pars *values)
{
	if (values->sp.drawendy >= values->resy)
		values->sp.drawendy = values->resy;
	values->sp.spritewidth = abs((int)(values->resy /\
			(values->sp.transformy)));
	values->sp.drawstartx = -values->sp.spritewidth /\
			2 + values->sp.spritescreenx;
	if (values->sp.drawstartx < 0)
		values->sp.drawstartx = 0;
	values->sp.drawendx = values->sp.spritewidth /\
			2 + values->sp.spritescreenx;
	if (values->sp.drawendx >= values->resx)
		values->sp.drawendx = values->resx;
}
