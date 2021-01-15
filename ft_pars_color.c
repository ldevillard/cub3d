/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:51:58 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/15 10:15:46 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_cutils(int *nbr, bool *test)
{
	*nbr += 1;
	*test = true;
}

static void		ft_check_value(char *str, t_pars *pars)
{
	int		i;
	int		nbr;
	bool	test;
	int		loop;

	loop = 3;
	i = 0;
	nbr = 0;
	while (loop != 0)
	{
		while (str[i] != ',' && str[i])
		{
			if (str[i] == ' ')
				test = false;
			else if (ft_isdigit(str[i]) && test == false)
				ft_cutils(&nbr, &test);
			i++;
		}
		test = false;
		i++;
		loop--;
	}
	if (nbr != 3)
		pars->error++;
}

static void		ft_check_str(char *str, t_pars *pars)
{
	int i;
	int comma;

	i = 0;
	comma = 0;
	if (str[0] != ' ')
		pars->error++;
	while (str[i])
	{
		if (str[i] == ',')
			comma++;
		if (!(ft_isdigit(str[i])) && str[i] != ' ' && str[i] != ',')
			pars->error++;
		i++;
	}
	if (comma != 2)
		pars->error++;
	if (!pars->error)
		ft_check_value(str, pars);
}

static void		ft_fill(char *str, int *tab, t_pars *pars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		tab[i] = ft_atoi(&str[j]);
		while (str[j] != ',' && str[j])
			j++;
		j++;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (!(tab[i] >= 0 && tab[i] <= 255))
			pars->error++;
		i++;
	}
}

void			ft_pars_color(char *str, t_pars *pars)
{
	int	i;

	i = 0;
	if (str[i] == 'C')
	{
		ft_check_str(&str[1], pars);
		if (!pars->error)
			ft_fill(&str[1], pars->c_color, pars);
		if (!pars->error)
			pars->c_fill = true;
	}
	else if (str[i] == 'F')
	{
		ft_check_str(&str[1], pars);
		if (!pars->error)
			ft_fill(&str[1], pars->f_color, pars);
		if (!pars->error)
			pars->f_fill = true;
	}
}
