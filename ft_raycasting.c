/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:05:18 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/21 11:07:55 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_raycasting(t_pars *pars)
{
	int x;

	x = 0;
	ft_init_raycast(pars);
	ft_mlx(pars);
	while (x < pars->resx)
	{
		//Ray
		x++;
	}
}

void	ft_mlx(t_pars *pars)
{
	pars->data.mlx_ptr = mlx_init();
	pars->data.mlx_win = mlx_new_window(pars->data.mlx_ptr, pars->resx, pars->resy, "cub3d");
	mlx_hook(pars->data.mlx_win, 2, 1L << 0, ft_key_hook, pars);
    mlx_hook(pars->data.mlx_win, 17, 1L << 0, ft_exit, pars);
	mlx_loop(pars->data.mlx_ptr);
}