/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_res.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:08:43 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/14 10:24:28 by ldevilla         ###   ########lyon.fr   */
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

void	ft_pars_res(char *str, t_pars *t_pars)
{
	int i;

	i = 0;
	if (str[i] == 'R')
	{
		if (t_pars-> resx && t_pars->resy)
			t_pars->error++;
		if (str[1] != ' ' || !ft_check_line(&str[1]))
			t_pars->error++;
		t_pars->resx = ft_atoi(&str[1]);
		i = ft_pass(str, i);
		t_pars->resy = ft_atoi(&str[i]);
		if (t_pars->resx <= 0 || t_pars->resy <= 0)
			t_pars->error++;
		i = ft_pass(str, i);
		while (str[i])
		{
			if (ft_isdigit(str[i]))
				t_pars->error++;
			i++;
		}
	}
}