/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:47:09 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/15 10:37:06 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *str, t_pars *pars)
{
	printf("Error\n%s\n", str);
	if (pars->north)
		free(pars->north);
	if (pars->south)
		free(pars->south);
	if (pars->east)
		free(pars->east);
	if (pars->west)
		free(pars->west);
	if (pars->sprite)
		free(pars->sprite);
	pars->error++;
}

void	ft_free(t_pars *pars)
{
	if (pars->north)
		free(pars->north);
	if (pars->south)
		free(pars->south);
	if (pars->east)
		free(pars->east);
	if (pars->west)
		free(pars->west);
	if (pars->sprite)
		free(pars->sprite);
}
