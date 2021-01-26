/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:01:08 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/26 14:21:14 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calc_ray(t_pars *values)
{
	if (values->data.side == 0)
		values->data.perpwalldist = (values->data.mapx - values->data.posx\
				+ (1 - values->data.stepx) / 2) / values->data.raydirx;
	else
		values->data.perpwalldist = (values->data.mapy - values->data.posy\
				+ (1 - values->data.stepy) / 2) / values->data.raydiry;
	values->data.lineheight = (int)(values->resy / values->data.perpwalldist);
	values->data.drawstart = -values->data.lineheight / 2 + values->resy / 2;
	if (values->data.drawstart < 0)
		values->data.drawstart = 0;
	values->data.drawend = values->data.lineheight / 2 + values->resy / 2;
	if (values->data.drawend >= values->resy)
		values->data.drawend = values->resy - 1;
}
