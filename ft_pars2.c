/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:35:50 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/26 14:49:56 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_gnl(t_pars *pars, char *file)
{
	int fd;

	if ((fd = open(file, O_DIRECTORY)) != -1)
	{
		ft_error("Your .cub is a directory", pars);
	}
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_error("Invalid file", pars);
	}
	return (fd);
}

void	ft_check_errors(t_pars *pars, char *file)
{
	if (!pars->nbrline || !pars->sizeline)
		ft_error("Missing map", pars);
	if (!pars->error)
		ft_pars_map(file, pars);
	if (pars->player != 1)
		ft_error("There is no or multiple player in the map", pars);
	ft_strsdup(pars->map, pars);
	if (ft_check_wall(pars, pars->px, pars->py) == 0)
		ft_error("Map isn't closed", pars);
}
