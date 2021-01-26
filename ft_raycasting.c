/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:15:13 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/26 13:30:24 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int		ft_raycasting(t_pars *values)
{
	int x;

	x = -1;
	while (++x < values->resx)
	{
		ft_raycast_set(values, &x);
		if(values->data.raydirx < 0)
		{
			values->data.stepx = -1;
			values->data.sidedistx = (values->data.posx - values->data.mapx) * values->data.deltadistx;
		}
		else
		{
			values->data.stepx = 1;
			values->data.sidedistx = (values->data.mapx + 1.0 - values->data.posx) * values->data.deltadistx;
		}
		if(values->data.raydiry < 0)
		{
			values->data.stepy = -1;
			values->data.sidedisty = (values->data.posy - values->data.mapy) * values->data.deltadisty;
		}
		else
		{
			values->data.stepy = 1;
			values->data.sidedisty = (values->data.mapy + 1.0 - values->data.posy) * values->data.deltadisty;
		}
		//perform DDA
		while (values->data.hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if(values->data.sidedistx < values->data.sidedisty)
			{
				values->data.sidedistx += values->data.deltadistx;
				values->data.mapx += values->data.stepx;
				values->data.side = 0;
			}
			else
			{
				values->data.sidedisty += values->data.deltadisty;
				values->data.mapy += values->data.stepy;
				values->data.side = 1;
			}
			//Check if ray has hit a wall
			if(values->map[values->data.mapx][values->data.mapy] == '1') values->data.hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if(values->data.side == 0) values->data.perpwalldist = (values->data.mapx - values->data.posx + (1 - values->data.stepx) / 2) / values->data.raydirx;
		else values->data.perpwalldist = (values->data.mapy - values->data.posy + (1 - values->data.stepy) / 2) / values->data.raydiry;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(values->resy / values->data.perpwalldist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + values->resy / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + values->resy / 2;
		if(drawEnd >= values->resy)drawEnd = values->resy - 1;

		//choose wall color
		int color = creatergb(200, 200, 0);

		//give x and y sides different brightness
		if(values->data.side == 1) {color = color / 2;}

		//draw the pixels of the stripe as a vertical line


		int j;

		j = -1;
		if (values->data.side == 1)
			color = color / 2;
		while (++j < drawStart)
			my_mlx_pixel_put(values, x, j + 1, creatergb(values->c_color[0],values->c_color[1],values->c_color[2]));
		while (++j < drawEnd)
			my_mlx_pixel_put(values, x, j, color);
		while (++j < values->resy)
			my_mlx_pixel_put(values, x, j, creatergb(values->f_color[0],values->f_color[1],values->f_color[2]));


	}
	ft_move_fb(values);
	ft_move_rl(values);
	ft_rot_right(values);
	ft_rot_left(values);
	mlx_put_image_to_window(values->data.mlx, values->data.mlx_win, values->data.img, 0, 0);
	mlx_do_sync(values->data.mlx);
	return (0);
}

void	ft_init_player(t_pars *values)
{
	if (values->po == 'N')
	{
		values->data.dirx = -1;
		values->data.planey = 0.66;
	}
	else if (values->po == 'S')
	{
		values->data.dirx = 1;
		values->data.planey = -0.66;
	}
	else if (values->po == 'W')
	{
		values->data.diry = -1;
		values->data.planex = -0.66;
	}
	else if (values->po == 'E')
	{
		values->data.diry = 1;
		values->data.planex = 0.66;
	}
}

void	ft_mlx(t_pars *values)
{
	ft_raycast_start(values);
	ft_init_player(values);
	values->data.mlx = mlx_init();
	values->data.mlx_win = mlx_new_window(values->data.mlx, values->resx, values->resy, "cub3d");
	values->data.img = mlx_new_image(values->data.mlx, values->resx, values->resy);
	values->data.addr = mlx_get_data_addr(values->data.img, &values->data.bits_per_pixel, &values->data.line_length, &values->data.endian);
	mlx_hook(values->data.mlx_win, 17, 1L << 0, ft_exit, values);
	mlx_hook(values->data.mlx_win, 2, 1L << 0, ft_press, &values->data);
	mlx_loop_hook(values->data.mlx, ft_raycasting, values);
	mlx_hook(values->data.mlx_win, 3, 1L << 1, ft_release, &values->data);
	mlx_loop(values->data.mlx);
}
