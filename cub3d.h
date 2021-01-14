/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:26:19 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/14 12:00:46 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct	s_pars
{
	int		resx;
	int		resy;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	int		f_color[3];
	int		c_color[3];
	bool	miss_element;
	bool	dup_element;
	bool	wrong_char;
	bool	player;
	char	pl_o;
	int		error;
	int		nbrline;
	int		sizeline;
	char	**map;
}				t_pars;

void	ft_init_struct(t_pars *t_pars);
void	ft_check_file(char *file, t_pars *t_pars);
void	ft_error(char *str, t_pars *t_pars);
void	ft_parsing(char *file, t_pars *t_pars);
void	ft_pars_res(char *str, t_pars *t_pars);
int		ft_check_line(char *str);
int		ft_pass(char *str, int i);
void	ft_load_pars(char *str, t_pars *t_pars);
void	ft_pars_text(char *str, t_pars *t_pars);
void	ft_set_text(char *str, char **text, t_pars *t_pars);
void	ft_pars_color(char *str, t_pars *t_pars);

#endif