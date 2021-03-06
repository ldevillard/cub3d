/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:26:51 by ldevilla          #+#    #+#             */
/*   Updated: 2021/02/02 11:15:52 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_fb(t_pars *values)
{
	if (values->data.front)
	{
		if (values->map[(int)(values->data.posx + values->data.dirx\
				* values->data.movespeed)][(int)(values->data.posy)] == '0')
			values->data.posx += values->data.dirx * values->data.movespeed;
		if (values->map[(int)(values->data.posx)][(int)(values->data.posy\
				+ values->data.diry * values->data.movespeed)] == '0')
			values->data.posy += values->data.diry * values->data.movespeed;
	}
	if (values->data.back)
	{
		if (values->map[(int)(values->data.posx - values->data.dirx\
				* values->data.movespeed)][(int)(values->data.posy)] == '0')
			values->data.posx -= values->data.dirx * values->data.movespeed;
		if (values->map[(int)(values->data.posx)][(int)(values->data.posy\
				- values->data.diry * values->data.movespeed)] == '0')
			values->data.posy -= values->data.diry * values->data.movespeed;
	}
}

void	ft_move_rl(t_pars *values)
{
	if (values->data.left)
	{
		if (values->map[(int)(values->data.posx + values->data.dirx\
				* values->data.movespeed)][(int)(values->data.posy)] == '0')
			values->data.posx -= values->data.diry * values->data.movespeed;
		if (values->map[(int)(values->data.posx)][(int)(values->data.posy\
				+ values->data.diry * values->data.movespeed)] == '0')
			values->data.posy += values->data.dirx * values->data.movespeed;
	}
	if (values->data.right)
	{
		if (values->map[(int)(values->data.posx - values->data.dirx\
				* values->data.movespeed)][(int)(values->data.posy)] == '0')
			values->data.posx += values->data.diry * values->data.movespeed;
		if (values->map[(int)(values->data.posx)][(int)(values->data.posy\
				- values->data.diry * values->data.movespeed)] == '0')
			values->data.posy -= values->data.dirx * values->data.movespeed;
	}
}

void	ft_rot_right(t_pars *values)
{
	double oldplanex;
	double olddirx;

	if (values->data.r_right)
	{
		olddirx = values->data.dirx;
		values->data.dirx = values->data.dirx * cos(-values->data.rotspeed)\
				- values->data.diry * sin(-values->data.rotspeed);
		values->data.diry = olddirx * sin(-values->data.rotspeed)\
				+ values->data.diry * cos(-values->data.rotspeed);
		oldplanex = values->data.planex;
		values->data.planex = values->data.planex * cos(-values->data.rotspeed)\
				- values->data.planey * sin(-values->data.rotspeed);
		values->data.planey = oldplanex * sin(-values->data.rotspeed)\
				+ values->data.planey * cos(-values->data.rotspeed);
	}
}

void	ft_rot_left(t_pars *values)
{
	double olddirx;
	double oldplanex;

	if (values->data.r_left)
	{
		olddirx = values->data.dirx;
		values->data.dirx = values->data.dirx * cos(values->data.rotspeed)\
				- values->data.diry * sin(values->data.rotspeed);
		values->data.diry = olddirx * sin(values->data.rotspeed)\
				+ values->data.diry * cos(values->data.rotspeed);
		oldplanex = values->data.planex;
		values->data.planex = values->data.planex * cos(values->data.rotspeed)\
				- values->data.planey * sin(values->data.rotspeed);
		values->data.planey = oldplanex * sin(values->data.rotspeed)\
				+ values->data.planey * cos(values->data.rotspeed);
	}
}
