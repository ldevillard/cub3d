/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:46:50 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/15 10:16:39 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_is_map(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (ft_ccheck(str, '1') || ft_ccheck(str, '0'))
	{
		while (str[i])
		{
			if (str[i] != ' ' && str[i] != '0' && str[i] != '1'
						&& str[i] != '2' && str[i] != 'N' && str[i] != 'S'
						&& str[i] != 'E' && str[i] != 'W' && str[i] != '\n'
						&& str[i] != '\t')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_check_map(char *str, t_pars *pars)
{
	if (ft_is_map(str) && (!pars->resx || !pars->resy \
					|| !pars->north || !pars->south || !pars->east \
					|| !pars->west || !pars->sprite
					|| pars->c_fill == false 
					|| pars->f_fill == false))
		pars->error++;
}
