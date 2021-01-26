/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:39:20 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/26 12:44:56 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			my_mlx_pixel_put(t_pars *values, int x, int y, int color)
{
	char	*dst;

	dst = values->data.addr + (y * values->data.line_length + x * (values->data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int		ft_press(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	else if (keycode == W)
		data->front = 1;
	else if (keycode == S)
		data->back = 1;
	else if (keycode == A)
		data->left = 1;
	else if (keycode == D)
		data->right = 1;
	else if (keycode == LEFT_ARROW)
		data->r_left = 1;
	else if (keycode == RIGHT_ARROW)
		data->r_right = 1;
	return (1);
}
int				ft_release(int keycode, t_data *data)
{
	if (keycode == W)
		data->front = 0;
	else if (keycode == S)
		data->back = 0;
	else if (keycode == A)
		data->left = 0;
	else if (keycode == D)
		data->right = 0;
	else if (keycode == LEFT_ARROW)
		data->r_left = 0;
	else if (keycode == RIGHT_ARROW)
		data->r_right = 0;
	return (1);
}

unsigned long	creatergb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}