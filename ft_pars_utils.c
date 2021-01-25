/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:24:08 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/22 11:48:02 by ldevilla         ###   ########lyon.fr   */
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

int		ft_check_wall(t_pars *pars, int x, int y)
{
	int ret;

	ret = 0;
	if (pars->savemap[y][x] == '1' || pars->savemap[y][x] == '+')
		return (1);
	if (pars->savemap[y][x] == ' ')
		return (0);
	if (x < 1 || y < 1 || x + 1 >= pars->sizeline || y + 1 >= pars->nbrline)
		return (0);
	pars->savemap[y][x] = '+';
	ret = ft_check_wall(pars, x, y + 1) &&
		ft_check_wall(pars, x + 1, y) &&
		ft_check_wall(pars, x, y - 1) &&
		ft_check_wall(pars, x - 1, y);
	return (ret);
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
	//i = 0;
	//ft_putchar('\n');
	//while (i < pars->nbrline)
	//{
	//	ft_putendl_fd(pars->savemap[i], 1);
	//	i++;
	//}
}

void	ft_strsdup(char **sstr, t_pars *pars)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(pars->savemap = malloc(sizeof(char *) * pars->nbrline)))
		ft_error("Malloc fail", pars);
	while (i < pars->nbrline)
	{
		j = 0;
		if (!(pars->savemap[i] = malloc(sizeof(char) * pars->sizeline + 1)))
			ft_error("Malloc fail", pars);
		while (sstr[i][j])
		{
			pars->savemap[i][j] = sstr[i][j];
			j++;
		}
		pars->savemap[i][j] = '\0';
		i++;
		pars->m_save_line++;
	}
}
