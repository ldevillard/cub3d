/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:47:09 by ldevilla          #+#    #+#             */
/*   Updated: 2021/01/19 12:17:58 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *str, t_pars *pars)
{
	int i;

	i = 0;
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
	if (pars->map)
		while (i < pars->m_line)
			free(pars->map[i++]);
	if (pars->map)
		free(pars->map);
	i = 0;
	if (pars->savemap)
		while (i < pars->m_save_line)
			free(pars->savemap[i++]);
	if (pars->savemap)
		free(pars->savemap);
	pars->error++;
	exit(0);
}

void	ft_free(t_pars *pars)
{
	int i;

	i = 0;
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
	if (pars->map)
		while (i < pars->m_line)
			free(pars->map[i++]);
	if (pars->map)
		free(pars->map);
	i = 0;
	if (pars->savemap)
		while (i < pars->m_save_line)
			free(pars->savemap[i++]);
	if (pars->savemap)
		free(pars->savemap);
}
