/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:24:51 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/25 13:36:54 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned long    createRGB(int r, int g, int b)
{
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void            my_mlx_pixel_put(t_pars *pars, int x, int y, int color)
{
	char *dst;
	dst = pars->data.addr + (y * pars->data.line_length + x * (pars->data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void			ft_draw_col(t_pars *pars, int *x)
{
	int j;
	int color;
	
	j = 0;
	color = createRGB(200, 200, 0);
	 if (pars->ray.side == 1)
		color = color / 2;
	while (j++ <= pars->ray.drawstart)
		my_mlx_pixel_put(pars, *x, j, createRGB(pars->c_color[0], pars->c_color[1], pars->c_color[2]));
	while (j++ <= pars->ray.drawend)
		my_mlx_pixel_put(pars, *x, j, color);
	while (j++ < pars->resy)
		my_mlx_pixel_put(pars, *x, j, createRGB(pars->f_color[0], pars->f_color[1], pars->f_color[2]));
}

int		ft_press(int keycode, t_pars *pars)
{
	if (keycode == W)
		pars->ray.front = 1;
	else if (keycode == S)
		pars->ray.back = 1;
    else if (keycode == A)
		pars->ray.left = 1;
	else if (keycode == D)
		pars->ray.right = 1;
	else if (keycode == LEFT_ARROW)
		pars->ray.r_left = 1;
	else if (keycode == RIGHT_ARROW)
		pars->ray.r_right = 1;
	//printf("%f\n %f\n", pars->ray.posx, pars->ray.posx);
	return (1);
}

int		ft_release(int keycode, t_pars *pars)
{
	if (keycode == W)
		pars->ray.front = 0;
	else if (keycode == S)
		pars->ray.back = 0;
  else if (keycode == A)
		pars->ray.left = 0;
	else if (keycode == D)
		pars->ray.right = 0;
	else if (keycode == LEFT_ARROW)
		pars->ray.r_left = 0;
	else if (keycode == RIGHT_ARROW)
		pars->ray.r_right = 0;
   return (1);
}