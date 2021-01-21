/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:54:31 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/21 10:57:33 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_key_hook(int keycode, t_pars *pars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(pars->data.mlx_ptr, pars->data.mlx_win);
		exit(0);
	}
	return (0);
}

int		ft_exit(t_pars *pars)
{
	(void)pars;
	exit(0);
	return (0);
}