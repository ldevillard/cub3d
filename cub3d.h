/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:26:19 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/18 12:48:15 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"

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
	bool	f_fill;
	bool	c_fill;
	//bool	miss_element;
	//bool	dup_element;
	//bool	wrong_char;
	//bool	player;
	//char	pl_o;
	int		error;
	int		nbrline;
	int		sizeline;
	char	**map;
	bool	is_map;
	int		m_line;
	int		map_finished;
}				t_pars;

void			ft_init_struct(t_pars *pars);
void			ft_check_file(char *file, t_pars *pars);
void			ft_error(char *str, t_pars *pars);
void			ft_parsing(char *file, t_pars *pars);
void			ft_pars_res(char *str, t_pars *pars);
int				ft_check_line(char *str);
int				ft_pass(char *str, int i);
void			ft_load_pars(char *str, t_pars *pars);
void			ft_pars_text(char *str, t_pars *pars);
void			ft_set_text(char *str, char **text, t_pars *pars);
void			ft_pars_color(char *str, t_pars *pars);
void			ft_free(t_pars *pars);
int				ft_is_map(char *str);
void			ft_check_map(char *str, t_pars *pars);
void			ft_pars_map(char *file, t_pars *pars);
int				ft_void_line(char *str);
void			ft_valid_map(char *str, t_pars *pars);
void			ft_fill_map(char *str, t_pars *pars);

#endif
