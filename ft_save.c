/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:07:35 by ldevilla          #+#    #+#             */
/*   Updated: 2021/02/02 10:46:14 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_header_bmp(t_pars *values, int fd)
{
	int	tmp;
	int i;

	i = 0;
	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * values->resx * values->resy;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &values->resx, 4);
	write(fd, &values->resy, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &values->data.bits_per_pixel, 2);
	tmp = 0;
	while (i++ < 28)
		write(fd, &tmp, 1);
}

void	ft_create_bmp(t_pars *values)
{
	int	fd;
	int	x;
	int	y;

	y = values->resy - 1;
	if ((fd = open("./pic.bmp", O_CREAT | O_RDWR, S_IWUSR | S_IRUSR)) == -1)
		ft_error("Can't create .bmp file", values);
	ft_header_bmp(values, fd);
	while (y >= 0)
	{
		x = 0;
		while (x < values->resx)
		{
			write(fd, &values->data.addr[y * values->data.line_length + x\
					* (values->data.bits_per_pixel / 8)], 4);
			x++;
		}
		y--;
	}
	ft_exit(values);
}

int		ft_check_second_arg(char *str)
{
	if (ft_strlen(str) == 6 && str[0] == '-'
			&& str[1] == '-' && str[2] == 's'
			&& str[3] == 'a' && str[4] == 'v'
			&& str[5] == 'e')
		return (1);
	else
		return (0);
}
