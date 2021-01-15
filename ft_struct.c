/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 08:47:01 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/15 10:14:39 by ldevilla         ###   ########lyon.fr   */
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
}
