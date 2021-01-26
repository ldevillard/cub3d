/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:46:51 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/26 10:29:12 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_raycast_start(t_pars *pars, int *x)
{
	(void)x;
	(void)pars;
	/*
	pars->ray.hit = 0;
	pars->ray.perpwalldist = 0;
	pars->ray.camerax = 2 * *x / (double)pars->resx - 1;
	pars->ray.raydirx = pars->ray.dirx + pars->ray.planx * pars->ray.camerax;
	pars->ray.raydiry = pars->ray.diry + pars->ray.plany * pars->ray.camerax;
	pars->ray.mapx = (int)pars->ray.posx;
	pars->ray.mapy = (int)pars->ray.posy;
	//printf("%c\n", pars->map[pars->ray.mapx][pars->ray.mapy]);
	//printf("%c\n", pars->map[pars->py][pars->px]);
	*/
}

void	ft_raycast_set_ray(t_pars *pars)
{
	(void)pars;
	/*
	if (pars->ray.raydiry == 0)
		pars->ray.deltadistx = 0;
	else if (pars->ray.raydirx == 0)
		pars->ray.deltadistx = 1;
	else
		pars->ray.deltadistx = sqrt(1 + (pars->ray.raydiry
			* pars->ray.raydiry) / (pars->ray.raydirx *
			pars->ray.raydirx));
	if (pars->ray.raydirx == 0)
		pars->ray.deltadisty = 0;
	else if (pars->ray.raydiry == 0)
		pars->ray.deltadisty = 1;
	else
		pars->ray.deltadisty = sqrt(1 + (pars->ray.raydirx *
			pars->ray.raydirx) / (pars->ray.raydiry *
			pars->ray.raydiry));
	*/
}