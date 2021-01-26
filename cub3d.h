/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:26:19 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/26 09:47:55 by ldevilla         ###   ########lyon.fr   */
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

typedef struct	s_ray
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
	int		mapx; // coordonée x du carré dans lequel est pos
	int		mapy; // coordonnée y du carré dans lequel est pos
	double	sidedistx; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double	sidedisty; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double	deltadistx; //distance que rayon parcours entre chaque point d'intersection vertical
	double	deltadisty; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int		stepx; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int		stepy; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int		hit; // 1 si un mur a ete touche, 0 sinon
	int		side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double	perpwalldist;
	int		lineheight; //hauteur de la ligne a dessiner
	int		drawstart; //position de debut ou il faut dessiner
	int		drawend; //position de fin ou il faut dessiner
	int		front;
	int		back;
    int		right;
    int		left;
    int		r_left;
    int		r_right;
	double	movespeed; //the constant value is in squares/second
  	double	rotspeed;
}				t_raycast;

typedef struct  s_data {
    void        *img;
    char        *addr;
	char		**map;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    void        *mlx;
    void        *mlx_win;
    int         front;
    int         back;
    int         right;
    int         left;
    int         r_left;
    int         r_right;
    double         posX;
    double         posY;
    double dirX; 
    double dirY; //initial direction vector
    double planeX; 
    double planeY;

}               t_data;

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
	t_raycast	ray;
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
int				ft_raycasting(t_data *pars, t_pars *values);
void			ft_mlx(t_pars *values);
int				ft_key_hook(int keycode, t_pars *pars);
int				ft_exit(t_pars *pars);
void			ft_raycast_start(t_pars *pars, int *x);
void			ft_raycast_set_ray(t_pars *pars);
void			ft_raycast_set_side(t_pars *pars);
void			ft_detect_wall(t_pars *pars);
void			ft_calculate_ray(t_pars *pars);
void			ft_draw_col(t_pars *pars, int *x);
unsigned long	createRGB(int r, int g, int b);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				ft_press(int keycode, t_data *data);
int				ft_release(int keycode, t_data *data);

#endif
