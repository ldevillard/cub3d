/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:15:13 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/26 14:24:19 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_side(t_pars *values)
{
	if (values->data.raydirx < 0)
	{
		values->data.stepx = -1;
		values->data.sidedistx = (values->data.posx - values->data.mapx)\
			* values->data.deltadistx;
	}
	else
	{
		values->data.stepx = 1;
		values->data.sidedistx = (values->data.mapx + 1.0 - values->data.posx)\
			* values->data.deltadistx;
	}
	if (values->data.raydiry < 0)
	{
		values->data.stepy = -1;
		values->data.sidedisty = (values->data.posy - values->data.mapy)\
			* values->data.deltadisty;
	}
	else
	{
		values->data.stepy = 1;
		values->data.sidedisty = (values->data.mapy + 1.0 - values->data.posy)\
			* values->data.deltadisty;
	}
}

void	ft_check_hit(t_pars *values)
{
	while (values->data.hit == 0)
	{
		if (values->data.sidedistx < values->data.sidedisty)
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
		if (values->map[values->data.mapx][values->data.mapy] == '1')
			values->data.hit = 1;
	}
}

int		ft_raycasting(t_pars *values)
{
	int x;

	x = -1;
	while (++x < values->resx)
	{
		ft_raycast_set(values, &x);
		ft_set_side(values);
		ft_check_hit(values);
		ft_calc_ray(values);
		ft_raycast_draw(values, &x);
	}
	ft_move_fb(values);
	ft_move_rl(values);
	ft_rot_right(values);
	ft_rot_left(values);
	mlx_put_image_to_window(values->data.mlx,\
			values->data.mlx_win, values->data.img, 0, 0);
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
	values->data.mlx_win = mlx_new_window(values->data.mlx,\
			values->resx, values->resy, "cub3d");
	values->data.img = mlx_new_image(values->data.mlx,\
			values->resx, values->resy);
	values->data.addr = mlx_get_data_addr(values->data.img,\
			&values->data.bits_per_pixel, &values->data.line_length,\
			&values->data.endian);
	mlx_hook(values->data.mlx_win, 17, 1L << 0, ft_exit, values);
	mlx_hook(values->data.mlx_win, 2, 1L << 0, ft_press, &values->data);
	mlx_loop_hook(values->data.mlx, ft_raycasting, values);
	mlx_hook(values->data.mlx_win, 3, 1L << 1, ft_release, &values->data);
	mlx_loop(values->data.mlx);
}
