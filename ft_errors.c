/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:47:09 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/14 13:27:04 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *str, t_pars *t_pars)
{
	printf("Error\n%s\n", str);
	if (t_pars->north)
		free(t_pars->north);
	if (t_pars->south)
		free(t_pars->south);
	if (t_pars->east)
		free(t_pars->east);
	if (t_pars->west)
		free(t_pars->west);
	if (t_pars->sprite)
		free(t_pars->sprite);
}

void	ft_free(t_pars *t_pars)
{
	if (t_pars->north)
		free(t_pars->north);
	if (t_pars->south)
		free(t_pars->south);
	if (t_pars->east)
		free(t_pars->east);
	if (t_pars->west)
		free(t_pars->west);
	if (t_pars->sprite)
		free(t_pars->sprite);
}