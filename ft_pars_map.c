/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:46:50 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/18 14:06:52 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_map(char *str, t_pars *pars)
{
	int			j;
	static int	i = 0;

	j = 0;
	pars->map[i] = NULL;
	if (!(pars->map[i] = malloc(sizeof(char) * pars->sizeline + 1)))
		ft_error("Malloc fail", pars);
	pars->m_line++;
	while (str[j])
	{
		if (str[j] == ' ' || str[j] == '\t')
			pars->map[i][j] = '1';
		else
			pars->map[i][j] = str[j];
		j++;
	}
	pars->map[i][j] = '\0';
	if (i + 1 == pars->nbrline)
		pars->map_finished = 1;
	printf("%s\n", pars->map[i]);
	i++;
}

void	ft_pars_map(char *file, t_pars *pars)
{
	char	*line;
	int		fd;
	int		gnl;

	gnl = 1;
	fd = open(file, O_RDONLY);
	if (!(pars->map = malloc(sizeof(char *) * pars->nbrline)))
		ft_error("Malloc fail", pars);
	while (gnl != 0)
	{
		gnl = get_next_line(fd, &line);
		if (ft_is_map(line))
		{
			pars->is_map = true;
			ft_fill_map(line, pars);
		}
		if (pars->is_map == true && !pars->map_finished)
			if (!ft_void_line(line))
				ft_error("Missing line in map", pars);
		free(line);
	}
	close(fd);
}

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
	if (ft_is_map(str))
	{
		if (!pars->resx || !pars->resy \
			|| !pars->north || !pars->south || !pars->east \
			|| !pars->west || !pars->sprite
			|| pars->c_fill == false
			|| pars->f_fill == false)
			pars->error++;
		else if (pars->sizeline < (int)ft_strlen(str))
			pars->sizeline = ft_strlen(str);
		pars->nbrline++;
	}
	else if (pars->resx && pars->resy
		&& pars->north && pars->south && pars->east
		&& pars->west && pars->sprite
		&& pars->c_fill == true
		&& pars->f_fill == true && ft_void_line(str))
		pars->error++;
}
