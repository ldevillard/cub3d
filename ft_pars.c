/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:19:43 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/13 10:35:15 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parsing(char *file, t_pars *t_pars)
{
	char	*line;
	int		fd;
	int		gnl;
	
	gnl = 1;
	if ((fd = open(file, O_DIRECTORY)) != -1)
	{
		ft_error("Your .cub is a directory", t_pars);
		return ;
	}
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_error("Invalid file", t_pars);
		return ;
	}
	while ((gnl = get_next_line(fd, &line)) != 0)
	{
		if (gnl == -1)
		{
			ft_error("Problem encountered while parsing", t_pars);
			return ;
		}
		printf("%s\n", line);
		free(line);
	}
	close(fd);	
}

void	ft_check_file(char *file, t_pars *t_pars)
{
	int i;

	i = 0;
	while (file[i] != '.')
	{
		if (!file[i])
		{
			ft_error("Invalid file name", t_pars);
			return ;
		}
		i++;
	}
	if (file[i + 1] == 'c' && file[i + 2] == 'u' && file[i + 3] == 'b')
	{
		if (file[i + 4] == '\0')
			ft_parsing(file, t_pars);
		else
		{
			ft_error("Invalid file name", t_pars);
			return ;
		}
	}
	else
		ft_error("Invalid file name", t_pars);
	return ;
}

int		main(int ac, char **av)
{
	t_pars	t_pars;
	
	ft_init_struct(&t_pars);
	if (ac == 2)
	{
		ft_check_file(av[1], &t_pars);
	}
	else
		printf("Error\nWrong number of arguments\n");
}