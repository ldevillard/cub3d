/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 08:47:01 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/14 11:50:10 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_struct(t_pars *t_pars)
{
	int i;
	
	i = 0;
	while (i < 3)
	{
		t_pars->c_color[i] = 0;
		t_pars->f_color[i] = 0;
		i++;
	}
	t_pars->resx = 0;
	t_pars->resy = 0;
	t_pars->error = 0;
	t_pars->north = NULL;
	t_pars->south = NULL;
	t_pars->east = NULL;
	t_pars->west = NULL;
	t_pars->sprite = NULL;
	t_pars->nbrline = 0;
	t_pars->sizeline = 0;
}