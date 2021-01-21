/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:24:51 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/21 15:09:08 by ldevilla         ###   ########lyon.fr   */
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
	/*
	int j;
	int i;

	j = -1;
	pars->ray.drawend = pars->resy - pars->ray.drawstart;
	i = pars->ray.drawend;
	while (++j < pars->ray.drawstart)
		pars->data.addr[j * pars->data.line_length / 4 +
			*x] = createRGB(pars->c_color[0], pars->c_color[1], pars->c_color[2]);
	//if (j <= recup->ray.drawend)
	//	ft_draw_texture(recup, recup->ray.x, j);
	j = i;
	while (++j < pars->resy)
		pars->data.addr[j * pars->data.line_length / 4 +
			*x] = createRGB(pars->f_color[0], pars->f_color[1], pars->f_color[2]);
	*/
}