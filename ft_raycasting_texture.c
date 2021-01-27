/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 09:16:47 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/27 14:21:21 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_load_text(t_pars *values)
{
	if (!(values->texdata[0].img = mlx_xpm_file_to_image(values->data.mlx,\
					values->north, &(values->texdata[0].width),\
					&(values->texdata[0].height))))
		ft_error("North texture failed", values);
	if (!(values->texdata[1].img = mlx_xpm_file_to_image(values->data.mlx,\
					values->south, &(values->texdata[1].width),\
					&(values->texdata[1].height))))
		ft_error("South texture failed", values);
	if (!(values->texdata[2].img = mlx_xpm_file_to_image(values->data.mlx,\
					values->west, &(values->texdata[2].width),\
					&(values->texdata[2].height))))
		ft_error("West texture failed", values);
	if (!(values->texdata[3].img = mlx_xpm_file_to_image(values->data.mlx,\
					values->east, &(values->texdata[3].width),\
					&(values->texdata[3].height))))
		ft_error("East texture failed", values);
	if (!(values->texdata[4].img = mlx_xpm_file_to_image(values->data.mlx,\
					values->sprite, &(values->texdata[4].width),\
					&(values->texdata[4].height))))
		ft_error("Sprite texture failed", values);
	ft_load_tex_addr(values);
}

void			ft_load_tex_addr(t_pars *values)
{
	values->texdata[0].addr = mlx_get_data_addr(values->texdata[0].img,
			&values->texdata[0].bits_per_pixel,
			&values->texdata[0].line_length, &values->texdata[0].endian);
	values->texdata[1].addr = mlx_get_data_addr(values->texdata[1].img,
			&values->texdata[1].bits_per_pixel,
			&values->texdata[1].line_length, &values->texdata[1].endian);
	values->texdata[2].addr = mlx_get_data_addr(values->texdata[2].img,
			&values->texdata[2].bits_per_pixel,
			&values->texdata[2].line_length, &values->texdata[2].endian);
	values->texdata[3].addr = mlx_get_data_addr(values->texdata[3].img,
			&values->texdata[3].bits_per_pixel,
			&values->texdata[3].line_length, &values->texdata[3].endian);
	values->texdata[4].addr = mlx_get_data_addr(values->texdata[4].img,
			&values->texdata[4].bits_per_pixel,
			&values->texdata[4].line_length, &values->texdata[4].endian);
}

static void		ft_swap_addr(t_pars *values, int x, int *y)
{
	values->data.addr[*y * values->data.line_length + x *\
			(values->data.bits_per_pixel) / 8] =
		values->texdata[values->tex.texdir].addr[values->tex.texy *\
		values->texdata[values->tex.texdir].line_length + values->tex.texx *\
		(values->texdata[values->tex.texdir].bits_per_pixel) / 8];
	values->data.addr[*y * values->data.line_length + x *\
			(values->data.bits_per_pixel) / 8 + 1] =
		values->texdata[values->tex.texdir].addr[values->tex.texy *\
		values->texdata[values->tex.texdir].line_length + values->tex.texx *\
		(values->texdata[values->tex.texdir].bits_per_pixel) / 8 + 1];
	values->data.addr[*y * values->data.line_length + x *\
			(values->data.bits_per_pixel) / 8 + 2] =
		values->texdata[values->tex.texdir].addr[values->tex.texy *\
		values->texdata[values->tex.texdir].line_length + values->tex.texx *\
		(values->texdata[values->tex.texdir].bits_per_pixel) / 8 + 2];
}

void			ft_text_print(t_pars *values, int x, int *y)
{
	*y = values->data.drawstart - 1;
	ft_text_init(values);
	values->tex.step = 1.0 * values->texdata[0].height
		/ values->data.lineheight;
	values->tex.texx = (int)(values->tex.wallx * (double)values->texdata\
			[values->tex.texdir].width);
	if (values->data.side == 0 && values->data.raydirx > 0)
		values->tex.texx = values->texdata[values->tex.texdir].width -\
			values->tex.texx - 1;
	if (values->data.side == 1 && values->data.raydiry < 0)
		values->tex.texx = values->texdata[values->tex.texdir].width -\
			values->tex.texx - 1;
	values->tex.texpos = (values->data.drawstart - values->resy / 2 +\
			values->data.lineheight / 2) * values->tex.step;
	while (++*y <= values->data.drawend)
	{
		values->tex.texy = (int)values->tex.texpos &\
			(values->texdata[values->tex.texdir].height - 1);
		values->tex.texpos += values->tex.step;
		if (*y < values->resy && x < values->resx)
			ft_swap_addr(values, x, y);
	}
}

void			ft_text_init(t_pars *values)
{
	if (values->data.side == 0 && values->data.raydirx < 0)
		values->tex.texdir = 0;
	if (values->data.side == 0 && values->data.raydirx >= 0)
		values->tex.texdir = 1;
	if (values->data.side == 1 && values->data.raydiry < 0)
		values->tex.texdir = 2;
	if (values->data.side == 1 && values->data.raydiry >= 0)
		values->tex.texdir = 3;
	if (values->data.side == 0)
		values->tex.wallx = values->data.posy + values->data.perpwalldist \
							* values->data.raydiry;
	else
		values->tex.wallx = values->data.posx + values->data.perpwalldist \
							* values->data.raydirx;
	values->tex.wallx -= floor((values->tex.wallx));
}
