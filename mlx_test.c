/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:57:20 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/21 14:31:52 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    void        *mlx;
    void        *mlx_win;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

unsigned long    createRGB(int r, int g, int b)
{
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void    draw(t_data *img, int i, int j)
{
    int x;
    int y;

    x = i;
    y = j;
    while (y < j + 50)
    {
        x = i;
        while (x < i + 50)
            my_mlx_pixel_put(img, x++, y, createRGB(255, 255, 0));
        y++;
    }
}

int             key_hook(int keycode, t_data *img)
{
    printf("%d\n", keycode);
    if (keycode == 53)
    {
        mlx_destroy_window(img->mlx, img->mlx_win);
        exit(0);
    }
    return (0);
}

int         ft_exit(void)
{
    exit(0);
    return (0);
}

int		main(void)
{
    t_data  img;
    int x;
    int y;

    x = 0;
    y = 0;
    img.mlx = mlx_init();
    img.mlx_win = mlx_new_window(img.mlx, 500, 500, "cub3d");
    img.img = mlx_new_image(img.mlx, 500, 500);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                           &img.endian);
    draw(&img, 10, 10);
    draw(&img, 440, 440);
    mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
    mlx_hook(img.mlx_win, 2, 1L << 0, key_hook, &img);
    mlx_hook(img.mlx_win, 17, 1L << 0, ft_exit, &img);
    mlx_loop(img.mlx);
}

//mlx_clear_window