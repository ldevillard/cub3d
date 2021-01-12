/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:42:48 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/12 15:51:19 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_digit(char *c, t_pars *t_pars)
{
	if (*c == '0' || *c == '1' || *c == '2')
		return (1);
	else
	{
		if ((*c == 'N' || *c == 'S' || *c == 'E' || *c == 'W')
			&& !t_pars->player)
			{
				t_pars->pl_o =  *c;
				t_pars->player++;
			}
	}
	return (0);
}

