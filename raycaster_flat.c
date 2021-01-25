

# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"


typedef struct  s_data {
    void        *img;
    char        *addr;
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
/*
g++ *.cpp -lSDL -O3 -W -Wall -ansi -pedantic
g++ *.cpp -lSDL
*/

//place the example code below here:

#define screenWidth 1000
#define screenHeight 600
#define mapWidth 100
#define mapHeight 100
# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define W 13
# define A 0
# define S 1
# define D 2

char worldMap[mapWidth][mapHeight]=
{
"        1111111111111111111111111",
"        1000000000110000000000001",
"        1011000001110000000000001",
"        1001000000000000000000001",
"111111111011000001110000000000001",
"100000000011000001110111111111111",
"11110111111111011100000010001",
"11110111111111011101010010001",
"11000000110101011100000000001",
"10000000000000001100000010001",
"10000000000000001101010010001",
"1100000111010101111101111000111",
"11110111 1110101 101111010001",
"11111111 1111111 111111111111"
};

unsigned long    createRGB(int r, int g, int b)
{
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
    //printf("%s\n", dst);
    //data->addr[y * data->line_length + x * (data->bits_per_pixel / 8)] = color;
}

int		ft_press(int keycode, t_data *data)
{
	if (keycode == W)
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

int ft_raycasting(t_data *pars)
{  //x and y start position

 //double time = 0; //time of current frame
  //double oldTime = 0; //time of previous frame

  double moveSpeed = 0.05; //the constant value is in squares/second
  double rotSpeed = 0.033 * 1.8; //the constant value is in radians/second
  
    for(int x = 0; x < screenWidth; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
      double rayDirX = pars->dirX + pars->planeX * cameraX;
      double rayDirY = pars->dirY + pars->planeY * cameraX;
      //which box of the map we're in
      int mapX = (int)pars->posX;
      int mapY = (int)pars->posY;

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
        sideDistX = (pars->posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - pars->posX) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (pars->posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - pars->posY) * deltaDistY;
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
        if(worldMap[mapX][mapY] == '1') hit = 1;
      }
      //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
      if(side == 0) perpWallDist = (mapX - pars->posX + (1 - stepX) / 2) / rayDirX;
      else          perpWallDist = (mapY - pars->posY + (1 - stepY) / 2) / rayDirY;

      //Calculate height of line to draw on screen
      int lineHeight = (int)(screenHeight / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + screenHeight / 2;
      if(drawStart < 0)drawStart = 0;
      int drawEnd = lineHeight / 2 + screenHeight / 2;
      if(drawEnd >= screenHeight)drawEnd = screenHeight - 1;

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
			my_mlx_pixel_put(pars, x, j, createRGB(0,200,200));
		while (j++ <= drawEnd)
			my_mlx_pixel_put(pars, x, j, color);
		while (j++ < screenHeight)
			my_mlx_pixel_put(pars, x, j, createRGB(100,100,100));


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
    if(pars->front)
    {
      if(worldMap[(int)(pars->posX + pars->dirX * moveSpeed)][(int)(pars->posY)] == '0') pars->posX += pars->dirX * moveSpeed;
      if(worldMap[(int)(pars->posX)][(int)(pars->posY + pars->dirY * moveSpeed)] == '0') pars->posY += pars->dirY * moveSpeed;
    }
    //move backwards if no wall behind you
    if(pars->back)
    {
      if(worldMap[(int)(pars->posX - pars->dirX * moveSpeed)][(int)(pars->posY)] == '0') pars->posX -= pars->dirX * moveSpeed;
      if(worldMap[(int)(pars->posX)][(int)(pars->posY - pars->dirY * moveSpeed)] == '0') pars->posY -= pars->dirY * moveSpeed;
    }
    if(pars->left)
    {
      if(worldMap[(int)(pars->posX + pars->dirX * moveSpeed)][(int)(pars->posY)] == '0') pars->posX -= pars->dirY * moveSpeed;
      if(worldMap[(int)(pars->posX)][(int)(pars->posY + pars->dirY * moveSpeed)] == '0') pars->posY += pars->dirX * moveSpeed;
    }
    //move backwards if no wall behind you
    if(pars->right)
    {
      if(worldMap[(int)(pars->posX - pars->dirX * moveSpeed)][(int)(pars->posY)] == '0') pars->posX += pars->dirY * moveSpeed;
      if(worldMap[(int)(pars->posX)][(int)(pars->posY - pars->dirY * moveSpeed)] == '0') pars->posY -= pars->dirX * moveSpeed;
    }
    //rotate to the right
    if(pars->r_right)
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = pars->dirX;
      pars->dirX = pars->dirX * cos(-rotSpeed) - pars->dirY * sin(-rotSpeed);
      pars->dirY = oldDirX * sin(-rotSpeed) + pars->dirY * cos(-rotSpeed);
      double oldPlaneX = pars->planeX;
      pars->planeX = pars->planeX * cos(-rotSpeed) - pars->planeY * sin(-rotSpeed);
      pars->planeY = oldPlaneX * sin(-rotSpeed) + pars->planeY * cos(-rotSpeed);
    }
    //rotate to the left
    if(pars->r_left)
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = pars->dirX;
      pars->dirX = pars->dirX * cos(rotSpeed) - pars->dirY * sin(rotSpeed);
      pars->dirY = oldDirX * sin(rotSpeed) + pars->dirY * cos(rotSpeed);
      double oldPlaneX = pars->planeX;
      pars->planeX = pars->planeX * cos(rotSpeed) - pars->planeY * sin(rotSpeed);
      pars->planeY = oldPlaneX * sin(rotSpeed) + pars->planeY * cos(rotSpeed);
    }
  mlx_put_image_to_window(pars->mlx, pars->mlx_win, pars->img, 0, 0);
	return (0);
}



int main()
{
  t_data pars;
  pars.front = 0;
  pars.back = 0;
  pars.right = 0;
  pars.left = 0;
  pars.r_left = 0;
  pars.r_right = 0;
  pars.posX = 6;
  pars.posY = 5;
  pars.dirX = -1;
  pars.dirY = 0;
  pars.planeX = 0;
  pars.planeY = 0.66;
	pars.mlx = mlx_init();
  pars.mlx_win = mlx_new_window(pars.mlx, screenWidth, screenHeight, "cub3d");
	pars.img = mlx_new_image(pars.mlx, screenWidth, screenHeight);
	pars.addr = mlx_get_data_addr(pars.img, &pars.bits_per_pixel, &pars.line_length, &pars.endian);
  //mlx_hook(pars->data.mlx_win, 17, 1L << 0, ft_exit, pars);
	//mlx_hook(pars->data.mlx_win, 2, 1L << 0, ft_key_hook, pars);
	mlx_hook(pars.mlx_win, 2, 1L << 0, ft_press, &pars);
	mlx_loop_hook(pars.mlx, ft_raycasting, &pars);
  mlx_hook(pars.mlx_win, 3, 1L << 1, ft_release, &pars);
	mlx_loop(pars.mlx);
  return (0);
}