/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_res.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:08:43 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/15 09:50:21 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int		ft_pass(char *str, int i)
{
	while (!(ft_isdigit(str[i])))
		i++;
	while ((ft_isdigit(str[i])))
		i++;
	return (i);
}

void	ft_pars_res(char *str, t_pars *pars)
{
	int i;

	i = 0;
	if (str[i] == 'R')
	{
		if (pars->resx && pars->resy)
			pars->error++;
		if (str[1] != ' ' || !ft_check_line(&str[1]))
			pars->error++;
		pars->resx = ft_atoi(&str[1]);
		i = ft_pass(str, i);
		pars->resy = ft_atoi(&str[i]);
		if (pars->resx <= 0 || pars->resy <= 0)
			pars->error++;
		i = ft_pass(str, i);
		while (str[i])
		{
			if (ft_isdigit(str[i]))
				pars->error++;
			i++;
		}
	}
}
