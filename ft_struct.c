/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 08:47:01 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/25 13:38:34 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_struct(t_pars *pars)
{
	int i;

	i = 0;
	while (i < 3)
	{
		pars->c_color[i] = 0;
		pars->f_color[i] = 0;
		i++;
	}
	pars->resx = 0;
	pars->resy = 0;
	pars->error = 0;
	pars->north = NULL;
	pars->south = NULL;
	pars->east = NULL;
	pars->west = NULL;
	pars->sprite = NULL;
	pars->nbrline = 0;
	pars->sizeline = 0;
	pars->f_fill = false;
	pars->c_fill = false;
	pars->map = NULL;
	pars->is_map = false;
	pars->m_line = 0;
	pars->map_finished = 0;
	pars->player = 0;
	pars->px = 0;
	pars->py = 0;
	pars->m_save_line = 0;
	pars->savemap = NULL;
}

void	ft_init_raycast(t_pars *pars)
{
	pars->ray.movespeed = 0.05;
  	pars->ray.rotspeed = 0.033 * 1.8;
	pars->ray.posx = pars->px;
	pars->ray.posy = pars->py;
	pars->ray.dirx = 0;
	pars->ray.diry = 0;
	pars->ray.planx = 0;
	pars->ray.plany = 0;
	pars->ray.front = 0;
	pars->ray.back = 0;
	pars->ray.left = 0;
	pars->ray.right = 0;
	pars->ray.r_left = 0;
	pars->ray.r_right = 0;
	if (pars->po == 'N')
	{
		pars->ray.dirx = -1;
		pars->ray.plany = 0.66;
	}
	else if (pars->po == 'S')
	{
		pars->ray.dirx = 1;
		pars->ray.plany = -0.66;
	}
	else if (pars->po == 'W')
	{
		pars->ray.diry = -1;
		pars->ray.planx = -0.66;
	}
	else if (pars->po == 'E')
	{
		pars->ray.diry = 1;
		pars->ray.planx = 0.66;
	}
}
		