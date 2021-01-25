/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:19:43 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/22 12:15:43 by ldevilla         ###   ########lyon.fr   */
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
	if ((fd = open(file, O_DIRECTORY)) != -1)
	{
		ft_error("Your .cub is a directory", pars);
		return ;
	}
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_error("Invalid file", pars);
		return ;
	}
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
	if (!pars->nbrline || !pars->sizeline)
		ft_error("Missing map", pars);
	if (!pars->error)
		ft_pars_map(file, pars);
	if (pars->player != 1)
		ft_error("There is no or multiple player in the map", pars);
	ft_strsdup(pars->map, pars);
	if (ft_check_wall(pars, pars->px, pars->py) == 0)
		ft_error("Map isn't closed", pars);
	
	//DISPLAY
	printf("RES X %d\n", pars->resx);
	printf("RES Y %d\n", pars->resy);
	printf("NO : %s\n", pars->north);
	printf("SO : %s\n", pars->south);
	printf("EA : %s\n", pars->east);
	printf("WE : %s\n", pars->west);
	printf("S : %s\n", pars->sprite);
	printf("F : %d,%d,%d\n", pars->f_color[0], pars->f_color[1], pars->f_color[2]);
	printf("C : %d,%d,%d\n", pars->c_color[0], pars->c_color[1], pars->c_color[2]);
	
	printf("SIZELINE : %d\n", pars->sizeline);
	printf("NBRLINE : %d\n", pars->nbrline);
	printf("PLAYER : NBR : %d / X : %d / Y : %d / O : %c\n", pars->player, pars->px, pars->py, pars->po);
	ft_putchar('\n');
	ft_print_map(pars);

	//RAYCAST
	ft_mlx(pars);
	//ft_raycasting(pars);
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
	ft_free(&pars); //Just for a moment
	return (0);
}
