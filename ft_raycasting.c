/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:05:18 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/21 15:01:52 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_raycast_set_side(t_pars *pars)
{
	if (pars->ray.raydirx < 0)
	{
		pars->ray.stepx = -1;
		pars->ray.sidedistx = (pars->ray.posx - pars->ray.mapx) * pars->ray.deltadistx;
	}
	else
	{
		pars->ray.stepx = 1;
		pars->ray.sidedistx = (pars->ray.mapx + 1.0 - pars->ray.posx) * pars->ray.deltadistx;
	}
	if (pars->ray.raydiry < 0)
	{
		pars->ray.stepy = -1;
		pars->ray.sidedisty = (pars->ray.posy - pars->ray.mapy) * pars->ray.deltadisty;
	}
	else
	{
		pars->ray.stepy = 1;
		pars->ray.sidedisty = (pars->ray.mapy + 1.0 - pars->ray.posy) * pars->ray.deltadisty;
	}
	ft_detect_wall(pars);
}

void	ft_detect_wall(t_pars *pars)
{
	while (pars->ray.hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (pars->ray.sidedistx < pars->ray.sidedisty)
		{
			pars->ray.sidedistx += pars->ray.deltadistx;
			pars->ray.mapx += pars->ray.stepx;
			pars->ray.side = 0;
		}
		else
		{
			pars->ray.sidedisty += pars->ray.deltadisty;
			pars->ray.mapy += pars->ray.stepy;
			pars->ray.side = 1;
		}
		//Check if ray has hit a wall
		if (pars->map[pars->ray.mapx][pars->ray.mapy] == '1')
			pars->ray.hit = 1;
	}
	ft_calculate_ray(pars);
}

void	ft_calculate_ray(t_pars *pars)
{
	if (pars->ray.side == 0)
		pars->ray.perpwalldist = ((double)pars->ray.mapx - \
				pars->ray.posx + (1 - (double)pars->ray.
				stepx) / 2) / pars->ray.raydirx;
	else
		pars->ray.perpwalldist = ((double)pars->ray.mapy - \
				pars->ray.posy + (1 - (double)pars->ray.
				stepy) / 2) / pars->ray.raydiry;
	pars->ray.lineheight = (int)(pars->resy / pars->ray.perpwalldist);
	pars->ray.drawstart = -pars->ray.lineheight / 2 + pars->resy / 2;
	if (pars->ray.drawstart < 0)
		pars->ray.drawstart = 0;
	pars->ray.drawend = pars->ray.lineheight / 2 + pars->resy / 2;
	if (pars->ray.drawend >= pars->resy || pars->ray.drawend < 0)
		pars->ray.drawend = pars->resy - 1;
}

int		ft_raycasting(t_pars *pars)
{
	int x;

	x = 0;
	ft_init_raycast(pars);
	while (x < pars->resx)
	{
		ft_raycast_start(pars, &x);
		ft_raycast_set_ray(pars);
		ft_raycast_set_side(pars);
		ft_draw_col(pars, &x);
		//printf("CAM %f\n", pars->ray.camerax);
		//printf("%f\n", pars->ray.raydirx);
		//printf("%f\n", pars->ray.raydiry);
		x++;
	}
	mlx_put_image_to_window(pars->data.mlx_ptr, pars->data.mlx_win, pars->data.img, 0, 0);
	return (0);
}

void	ft_mlx(t_pars *pars)
{
	pars->data.mlx_ptr = mlx_init();
	pars->data.img = mlx_new_image(pars->data.mlx_ptr, pars->resx, pars->resy);
	pars->data.addr = mlx_get_data_addr(pars->data.img, &pars->data.bits_per_pixel, &pars->data.line_length, &pars->data.endian);
	pars->data.mlx_win = mlx_new_window(pars->data.mlx_ptr, pars->resx, pars->resy, "cub3d");
	mlx_hook(pars->data.mlx_win, 17, 1L << 0, ft_exit, pars);
	mlx_hook(pars->data.mlx_win, 2, 1L << 0, ft_key_hook, pars);
	//mlx_hook(pars->data.mlx_win, 2, 1L << 0, ft_raycasting, pars);
	mlx_loop_hook(pars->data.mlx_ptr, ft_raycasting, pars);
	mlx_loop(pars->data.mlx_ptr);
}