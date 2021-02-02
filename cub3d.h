/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:26:19 by ldevilla          #+#    #+#             */
/*   Updated: 2021/02/02 11:05:48 by ldevilla         ###   ########lyon.fr   */
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

typedef struct	s_spcoord
{
	double	x;
	double	y;
	double	d;
}				t_spcoord;

typedef struct	s_sp
{
	int		count;
	int		*order;
	double	*walldist;
	double	spritex;
	double	spritey;
	double	invdet;
	double	transformx;
	double	transformy;
	int		spritescreenx;
	int		spriteheight;
	int		spritewidth;
	int		drawstartx;
	int		drawstarty;
	int		drawendy;
	int		drawendx;
}				t_sp;

typedef struct	s_tex
{
	int		texdir;
	double	wallx;
	int		texx;
	int		texy;
	double	step;
	double	texpos;
}				t_tex;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	int		front;
	int		back;
	int		right;
	int		left;
	int		r_left;
	int		r_right;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	double	movespeed;
	double	rotspeed;
	int		lineheight;
	int		drawstart;
	int		drawend;
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
	int			arg_save;
	t_sp		sp;
	t_spcoord	*spcoord;
	t_tex		tex;
	t_data		texdata[5];
	t_data		data;
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
int				ft_raycasting(t_pars *values);
void			ft_mlx(t_pars *values);
int				ft_key_hook(int keycode, t_pars *pars);
int				ft_exit(t_pars *pars);
void			ft_raycast_start(t_pars *values);
void			ft_raycast_set(t_pars *values, int *x);
void			ft_raycast_set_side(t_pars *pars);
void			ft_detect_wall(t_pars *pars);
void			ft_calculate_ray(t_pars *pars);
void			ft_draw_col(t_pars *pars, int *x);
unsigned long	creatergb(int r, int g, int b);
void			my_mlx_pixel_put(t_pars *values, int x, int y, int color);
int				ft_press(int keycode, t_data *data);
int				ft_release(int keycode, t_data *data);
void			ft_init_player(t_pars *values);
void			ft_move_fb(t_pars *values);
void			ft_move_rl(t_pars *values);
void			ft_rot_right(t_pars *values);
void			ft_rot_left(t_pars *values);
void			ft_raycast_draw(t_pars *values, int *x);
void			ft_set_side(t_pars *values);
void			ft_check_hit(t_pars *values);
void			ft_calc_ray(t_pars *values);
int				ft_check_gnl(t_pars *pars, char *file);
void			ft_check_errors(t_pars *pars, char *file);
void			ft_load_text(t_pars *values);
void			ft_load_tex_addr(t_pars *values);
void			ft_text_print(t_pars *values, int x, int *y);
void			ft_text_init(t_pars *values);
void			ft_set_spcoord(t_pars *values);
void			ft_fill_spcoord(t_pars *values);
void			ft_treat_sprites(t_pars *values);
void			ft_set_sp_order(t_pars *values);
void			ft_sprite(t_pars *values);
void			ft_matrix(t_pars *values, int i);
void			ft_draw_sprite(t_pars *values, int j, int texx, int stripe);
int				ft_check_second_arg(char *str);
void			ft_create_bmp(t_pars *values);
void			ft_header_bmp(t_pars *value, int fd);
void			set_sp_addr(t_pars *values, int j, int texx, int stripe);
void			ft_buf_draw_sp(t_pars *values, int j, int texx, int stripe);
void			ft_matrix_two(t_pars *values);

#endif
