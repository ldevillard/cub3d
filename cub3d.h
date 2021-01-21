/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:26:19 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/21 11:00:59 by ldevilla         ###   ########lyon.fr   */
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

# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct	s_raycast
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planx;
	double	plany;
	double	raydirx;
	double	raydiry;
	double	camerax;
}				t_raycast;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_pars
{
	int			resx;
	int			resy;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	int			f_color[3];
	int			c_color[3];
	bool		f_fill;
	bool		c_fill;
	int			error;
	int			nbrline;
	int			sizeline;
	char		**map;
	bool		is_map;
	int			m_line;
	int			map_finished;
	int			player;
	int			px;
	int			py;
	char		po;
	char		**savemap;
	int			m_save_line;
	t_data		data;
	t_raycast	raycast;
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
int				ft_check_wall(t_pars *pars, int x, int y);
void			ft_print_map(t_pars *pars);
void			ft_strsdup(char **sstr, t_pars *pars);
void			ft_init_raycast(t_pars *pars);
void			ft_raycasting(t_pars *pars);
void			ft_mlx(t_pars *pars);
int				ft_key_hook(int keycode, t_pars *pars);
int				ft_exit(t_pars *pars);

#endif
