# CUB3D

## Subject : 
- EN : https://cdn.intra.42.fr/pdf/pdf/17279/en.subject.pdf
- FR : https://cdn.intra.42.fr/pdf/pdf/17280/fr.subject.pdf
#
## Testing :
  ```
make && ./cub3D test.cub
  ```
  - to test the launch the window with the game
 ```
make && ./cub3D test.cub --save && open pic.bmp
  ```
- to create a .bmp file who's the first render of the game
#
## Tips :
- 
### For parsing :
- Floodfill : https://en.wikipedia.org/wiki/Flood_fill
```
int		ft_check_wall(t_pars *pars, int x, int y)
{
	int ret;

	ret = 0;
	if (pars->savemap[y][x] == '1' || pars->savemap[y][x] == '+')
		return (1);
	if (pars->savemap[y][x] == ' ')
		return (0);
	if (x < 1 || y < 1 || x + 1 >= pars->sizeline || y + 1 >= pars->nbrline)
		return (0);
	pars->savemap[y][x] = '+';
	ret = ft_check_wall(pars, x, y + 1) &&
		ft_check_wall(pars, x + 1, y) &&
		ft_check_wall(pars, x, y - 1) &&
		ft_check_wall(pars, x - 1, y);
	return (ret);
}
```
- Like the paint pot tool, this recursive algorythm will help you to check if the map is entoured by walls.
- A lot of GNL and treat line per line to check every error cases.
#
### For Raycast :
- Make searches about vectors and trigonometry
- Good course to learn the theory + history + vectors + trigo : https://courses.pikuma.com/courses/raycasting
- Good article to learn how it works : https://lodev.org/cgtutor/raycasting.html
# 
### For bitmap / --save
- https://en.wikipedia.org/wiki/BMP_file_format
- Very usefull article in french : https://www.commentcamarche.net/contents/1200-bmp-format-bmp#:~:text=BMP%20est%20un%20fichier%20bitmap,gr%C3%A2ce%20%C3%A0%20une%20palette%20index%C3%A9e
