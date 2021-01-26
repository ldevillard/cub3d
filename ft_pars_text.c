/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:04:58 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/26 11:02:55 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	ft_check_path(char *str, t_pars *pars)
{
	if (open(str, O_RDONLY) == -1)
		pars->error++;
}

void			ft_set_text(char *str, char **text, t_pars *pars)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (*text)
		pars->error++;
	if (str[i] != ' ' || ft_strlen(str) <= 2)
		pars->error++;
	while (str[i] != '.' && str[i] && !pars->error)
	{
		if (str[i] != ' ')
			pars->error++;
		i++;
	}
	if (str[i] && str[i + 1] == '/')
	{
		while (str[i + j] != ' ' && str[i + j])
			j++;
		*text = ft_substr(&str[i], 0, j);
	}
	while (str[i + j])
		if (str[i + j++] != ' ')
			pars->error++;
	ft_check_path(*text, pars);
}

void			ft_pars_text(char *str, t_pars *pars)
{
	int i;

	i = 0;
	if (str[i] == 'N' && str[i + 1] == 'O')
		ft_set_text(&str[2], &pars->north, pars);
	else if (str[i] == 'S' && str[i + 1] == 'O')
		ft_set_text(&str[2], &pars->south, pars);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		ft_set_text(&str[2], &pars->east, pars);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		ft_set_text(&str[2], &pars->west, pars);
	else if (str[i] == 'S' && str[i + 1] != 'O')
		ft_set_text(&str[1], &pars->sprite, pars);
	else if (str[0] != 'N' && str[0] != 'S' && str[0] != 'W' && str[0] != 'E'
			&& str[0] != 'R' && str[0] != 'F' && str[0] != 'C'
			&& str[0] >= 'A' && str[0] <= 'z')
		pars->error++;
}
