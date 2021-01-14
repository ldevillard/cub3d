/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:04:58 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/14 10:24:41 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_text(char *str, char **text, t_pars *t_pars)
{
	int i;
	
	i = 0;
	if (str[i] != ' ' || ft_strlen(str) <= 2)
		t_pars->error++;
	while (str[i] != '.' && str[i] && !t_pars->error)
	{
		if (str[i] != ' ')
			t_pars->error++;
		i++;
	}
	if (str[i] && str[i + 1] == '/')
		*text = ft_strdup(&str[i]);
}

void	ft_pars_text(char *str, t_pars *t_pars)
{
	int i;

	i = 0;
	if (str[i] == 'N' && str[i + 1] == 'O')
		ft_set_text(&str[2], &t_pars->north, t_pars);
	else if (str[i] == 'S' && str[i + 1] == 'O')
		ft_set_text(&str[2], &t_pars->south, t_pars);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		ft_set_text(&str[2], &t_pars->east, t_pars);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		ft_set_text(&str[2], &t_pars->west, t_pars);
	else if (str[i] == 'S' && str[i + 1] != 'O')
		ft_set_text(&str[1], &t_pars->sprite, t_pars);
	else if (str[0] != 'N' && str[0] != 'S' && str[0] != 'W' && str[0] != 'E'
			&& str[0] != 'R' && str[0] != 'F' && str[0] != 'C'
			&& str[0] >= 'A' && str[0] <= 'z')
		t_pars->error++;
}