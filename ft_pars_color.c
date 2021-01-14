/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:51:58 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/14 12:10:27 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_check_value(char *str, t_pars *t_pars)
{
	int i;
	int nbr;
	bool test;
	int loop;
	
	test = false;
	i = 0;
	nbr = 0;
	loop = 3;
	while (loop != 0)
	{
		while (str[i] != ',' && str[i])
		{
			if (str[i] == ' ')
				test = false;
			else if (ft_isdigit(str[i]) && test == false)
			{
				nbr++;
				test = true;
			}
			i++;
		}
		test = false;
		i++;
		loop--;
	}
	if (nbr != 3)
		t_pars->error++;
}

static void		ft_check_str(char *str, t_pars *t_pars)
{
	int i;
	int comma;

	i = 0;
	comma = 0;
	if (str[0] != ' ')
		t_pars->error++;
	while (str[i])
	{
		if (str[i] == ',')
			comma++;
		if (!(ft_isdigit(str[i])) && str[i] != ' ' && str[i] != ',')
			t_pars->error++;	
		i++;
	}
	if (comma != 2)
		t_pars->error++;
	if (!t_pars->error)
		ft_check_value(str, t_pars);		
}

static void		ft_fill(char *str, int *tab)
{
	int i;
	int j;

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
}
static void		ft_check_tab(int *tab, t_pars *t_pars)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (!(tab[i] >= 0 && tab[i] <= 255))
			t_pars->error++;
		i++;
	}
}
void			ft_pars_color(char *str,t_pars *t_pars)
{
    int i;

	i = 0;
	if (str[i] == 'C')
	{
		ft_check_str(&str[1], t_pars);
		if (!t_pars->error)
		{
			ft_fill(&str[1], t_pars->c_color);
			ft_check_tab(t_pars->c_color, t_pars);
		}
	}
	else if (str[i] == 'F')
	{
		ft_check_str(&str[1], t_pars);
		if (!t_pars->error)
		{
			ft_fill(&str[1], t_pars->f_color);
			ft_check_tab(t_pars->f_color, t_pars);
		}
	}
}