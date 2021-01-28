/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:19:43 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/28 13:00:32 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_load_pars(char *str, t_pars *pars)
{
	if (pars->sizeline > 0 && (pars->north == NULL || pars->south == NULL ||
				pars->west == NULL || pars->east == NULL
				|| pars->sprite == NULL))
		pars->error++;
	ft_check_map(str, pars);
	ft_pars_res(str, pars);
	ft_pars_color(str, pars);
	ft_pars_text(str, pars);
}

void	ft_parsing(char *file, t_pars *pars)
{
	char	*line;
	int		fd;
	int		gnl;

	gnl = 1;
	fd = ft_check_gnl(pars, file);
	while (gnl != 0)
	{
		gnl = get_next_line(fd, &line);
		if (gnl == -1 || pars->error)
		{
			ft_error("Problem encountered while parsing", pars);
			free(line);
			return ;
		}
		ft_load_pars(line, pars);
		free(line);
	}
	close(fd);
	ft_check_errors(pars, file);
	ft_mlx(pars);
}

void	ft_check_file(char *file, t_pars *pars)
{
	int i;

	i = 0;
	while (file[i] != '.')
	{
		if (!file[i])
		{
			ft_error("Invalid file name", pars);
			return ;
		}
		i++;
	}
	if (file[i + 1] == 'c' && file[i + 2] == 'u' && file[i + 3] == 'b')
	{
		if (file[i + 4] == '\0')
			ft_parsing(file, pars);
		else
		{
			ft_error("Invalid file name", pars);
			return ;
		}
	}
	else
		ft_error("Invalid file name", pars);
	return ;
}

int		main(int ac, char **av)
{
	t_pars	pars;

	ft_init_struct(&pars);
	if (ac == 2)
	{
		ft_check_file(av[1], &pars);
	}
	else
		printf("Error\nWrong number of arguments\n");
	ft_free(&pars);
	return (0);
}
