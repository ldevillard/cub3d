/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:15:13 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/26 10:27:45 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned long    createRGB(int r, int g, int b)
{
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void            my_mlx_pixel_put(t_pars *values, int x, int y, int color)
{
    char    *dst;

    dst = values->data.addr + (y * values->data.line_length + x * (values->data.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
    //printf("%s\n", dst);
    //data->addr[y * data->line_length + x * (data->bits_per_pixel / 8)] = color;
}

int		ft_press(int keycode, t_data *data)
{
  if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	else if (keycode == W)
		data->front = 1;
	else if (keycode == S)
		data->back = 1;
  else if (keycode == A)
		data->left = 1;
	else if (keycode == D)
		data->right = 1;
	else if (keycode == LEFT_ARROW)
		data->r_left = 1;
	else if (keycode == RIGHT_ARROW)
		data->r_right = 1;
  printf("PRESS %d\n", keycode);
	return (1);
}

int		ft_release(int keycode, t_data *data)
{
	if (keycode == W)
		data->front = 0;
	else if (keycode == S)
		data->back = 0;
  else if (keycode == A)
		data->left = 0;
	else if (keycode == D)
		data->right = 0;
	else if (keycode == LEFT_ARROW)
		data->r_left = 0;
	else if (keycode == RIGHT_ARROW)
		data->r_right = 0;
  //printf("RELEASE %d\n", keycode);
	return (1);
}

int ft_raycasting(t_pars *values)
{  //x and y start position

 //double time = 0; //time of current frame
  //double oldTime = 0; //time of previous frame
  double moveSpeed = 0.05; //the constant value is in squares/second
  double rotSpeed = 0.033 * 1.8; //the constant value is in radians/second
    for(int x = 0; x < values->resx; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)values->resx - 1; //x-coordinate in camera space
      double rayDirX = values->data.dirx + values->data.planex * cameraX;
      double rayDirY = values->data.diry + values->data.planey * cameraX;
      //which box of the map we're in
      int mapX = (int)values->data.posx;
      int mapY = (int)values->data.posy;

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

       //length of ray from one x or y-side to next x or y-side
      double deltaDistX = fabs(1 / rayDirX);
      double deltaDistY = fabs(1 / rayDirY);
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
      //calculate step and initial sideDist
      if(rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (values->data.posx - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - values->data.posx) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (values->data.posy - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - values->data.posy) * deltaDistY;
      }
      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if(values->map[mapX][mapY] == '1') hit = 1;
      }
      //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
      if(side == 0) perpWallDist = (mapX - values->data.posx + (1 - stepX) / 2) / rayDirX;
      else          perpWallDist = (mapY - values->data.posy + (1 - stepY) / 2) / rayDirY;

      //Calculate height of line to draw on screen
      int lineHeight = (int)(values->resy / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + values->resy / 2;
      if(drawStart < 0)drawStart = 0;
      int drawEnd = lineHeight / 2 + values->resy / 2;
      if(drawEnd >= values->resy)drawEnd = values->resy - 1;

      //choose wall color
      int color = createRGB(200, 200, 0);

      //give x and y sides different brightness
      if(side == 1) {color = color / 2;}

      //draw the pixels of the stripe as a vertical line


		int j;

	
		j = 0;
	 	if (side == 1)
			color = color / 2;
		while (j++ <= drawStart)
			my_mlx_pixel_put(values, x, j, createRGB(0,200,200));
		while (j++ <= drawEnd)
			my_mlx_pixel_put(values, x, j, color);
		while (j++ < values->resy)
			my_mlx_pixel_put(values, x, j, createRGB(100,100,100));


    }
    /*//timing for input and FPS counter
    oldTime = time;
    time = getTicks();
    double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
    print(1.0 / frameTime); //FPS counter
    redraw();
    cls();
    */
    //speed modifiers
    
    
    //move forward if no wall in front of you
    if(values->data.front) 
    {
      if(values->map[(int)(values->data.posx + values->data.dirx * moveSpeed)][(int)(values->data.posy)] == '0') values->data.posx += values->data.dirx * moveSpeed;
      if(values->map[(int)(values->data.posx)][(int)(values->data.posy + values->data.diry * moveSpeed)] == '0') values->data.posy += values->data.diry * moveSpeed;
    }
    //move backwards if no wall behind you
    if(values->data.back)
    {
      if(values->map[(int)(values->data.posx - values->data.dirx * moveSpeed)][(int)(values->data.posy)] == '0') values->data.posx -= values->data.dirx * moveSpeed;
      if(values->map[(int)(values->data.posx)][(int)(values->data.posy - values->data.diry * moveSpeed)] == '0') values->data.posy -= values->data.diry * moveSpeed;
    }
    if(values->data.left)
    {
      if(values->map[(int)(values->data.posx + values->data.dirx * moveSpeed)][(int)(values->data.posy)] == '0') values->data.posx -= values->data.diry * moveSpeed;
      if(values->map[(int)(values->data.posx)][(int)(values->data.posy + values->data.diry * moveSpeed)] == '0') values->data.posy += values->data.dirx * moveSpeed;
    }
    //move backwards if no wall behind you
    if(values->data.right)
    {
      if(values->map[(int)(values->data.posx - values->data.dirx * moveSpeed)][(int)(values->data.posy)] == '0') values->data.posx += values->data.diry * moveSpeed;
      if(values->map[(int)(values->data.posx)][(int)(values->data.posy - values->data.diry * moveSpeed)] == '0') values->data.posy -= values->data.dirx * moveSpeed;
    }
    //rotate to the right
    if(values->data.r_right)
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = values->data.dirx;
      values->data.dirx = values->data.dirx * cos(-rotSpeed) - values->data.diry * sin(-rotSpeed);
      values->data.diry = oldDirX * sin(-rotSpeed) + values->data.diry * cos(-rotSpeed);
      double oldPlaneX = values->data.planex;
      values->data.planex = values->data.planex * cos(-rotSpeed) - values->data.planey * sin(-rotSpeed);
      values->data.planey = oldPlaneX * sin(-rotSpeed) + values->data.planey * cos(-rotSpeed);
    }
    //rotate to the left
    if(values->data.r_left)
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = values->data.dirx;
      values->data.dirx = values->data.dirx * cos(rotSpeed) - values->data.diry * sin(rotSpeed);
      values->data.diry = oldDirX * sin(rotSpeed) + values->data.diry * cos(rotSpeed);
      double oldPlaneX = values->data.planex;
      values->data.planex = values->data.planex * cos(rotSpeed) - values->data.planey * sin(rotSpeed);
      values->data.planey = oldPlaneX * sin(rotSpeed) + values->data.planey * cos(rotSpeed);
    }
    mlx_put_image_to_window(values->data.mlx, values->data.mlx_win, values->data.img, 0, 0);
    
	return (0);
}

void	ft_init_player(t_pars *values)
{
	if (values->po == 'N')
	{
		values->data.dirx = -1;
		values->data.planey = 0.66;
	}
	else if (values->po == 'S')
	{
		values->data.dirx = 1;
		values->data.planey = -0.66;
	}
	else if (values->po == 'W')
	{
		values->data.diry = -1;
		values->data.planex = -0.66;
	}
	else if (values->po == 'E')
	{
		values->data.diry = 1;
		values->data.planex = 0.66;
	}
}

void    ft_mlx(t_pars *values)
{
  values->data.front = 0;
  values->data.back = 0;
  values->data.right = 0;
  values->data.left = 0;
  values->data.r_left = 0;
  values->data.r_right = 0;
  values->data.posx = (double)values->py + 0.5;
  values->data.posy = (double)values->px + 0.5;
  values->data.dirx = 0;
  values->data.diry = 0;
  values->data.planex = 0;
  values->data.planey = 0;
  values->resx = (values->resx > 5120) ? 5120 : values->resx;
  values->resy = (values->resy > 2880) ? 2880 : values->resy; 
  ft_init_player(values);
  //values->data.planex = 0;
  //values->data.planey = 0.66;
	values->data.mlx = mlx_init();
  values->data.mlx_win = mlx_new_window(values->data.mlx, values->resx, values->resy, "cub3d");
	values->data.img = mlx_new_image(values->data.mlx, values->resx, values->resy);
	values->data.addr = mlx_get_data_addr(values->data.img, &values->data.bits_per_pixel, &values->data.line_length, &values->data.endian);
  mlx_hook(values->data.mlx_win, 17, 1L << 0, ft_exit, values);
	mlx_hook(values->data.mlx_win, 2, 1L << 0, ft_press, &values->data);
	mlx_loop_hook(values->data.mlx, ft_raycasting, values);
  mlx_hook(values->data.mlx_win, 3, 1L << 1, ft_release, &values->data);
	mlx_loop(values->data.mlx);

}