/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:46:51 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/26 13:23:51 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_raycast_start(t_pars *values)
{
	values->data.movespeed = 0.05;
	values->data.rotspeed = 0.033 * 1.8;
	values->data.front = 0;
	values->data.back = 0;
	values->data.right = 0;
	values->data.left = 0;
	values->data.r_left = 0;
	values->data.r_right = 0;
	values->data.posx = (double)values->py + 0.5;
	values->data.posy = (double)values->px + 0.5;
	values->data.dirx = 0;
	values->data.diry = 0;
	values->data.planex = 0;
	values->data.planey = 0;
	values->resx = (values->resx > 2560) ? 2560 : values->resx;
	values->resy = (values->resy > 1440) ? 1440 : values->resy;
}

void	ft_raycast_set(t_pars *values, int *x)
{		
	//calculate ray position and direction
	values->data.camerax = 2 * *x / (double)values->resx - 1; //x-coordinate in camera space
	values->data.raydirx = values->data.dirx + values->data.planex * values->data.camerax;
	values->data.raydiry = values->data.diry + values->data.planey * values->data.camerax;
	//which box of the map we're in
	values->data.mapx = (int)values->data.posx;
	values->data.mapy = (int)values->data.posy;
	//length of ray from one x or y-side to next x or y-side
	values->data.deltadistx = fabs(1 / values->data.raydirx);
	values->data.deltadisty = fabs(1 / values->data.raydiry);
	values->data.hit = 0;
	//calculate step and initial sideDist
}