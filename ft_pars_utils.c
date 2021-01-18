/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:24:08 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/18 15:47:55 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_void_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\v'
			&& str[i] != '\n' && str[i] != '\r' && str[i] != '\f')
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_wall(t_pars *pars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pars->map[i][j])
		if (pars->map[i][j] != '1' || pars->map[i][j] != ' ')
			return (0);
	while (i < pars->nbrline - 1)
	{
		j = 0;
		while (pars->map[i][j] == ' ')
			j++;
		if (pars->map[i][j] != 1 && pars->map[i][ft_strlen(pars->map[i]) - 1] != '1')
		i++;
	}
	return (1);
}

void	ft_print_map(t_pars *pars)
{
	int i;

	i = 0;
	while (i < pars->nbrline)
	{
		ft_putendl_fd(pars->map[i], 1);
		i++;
	}
}
