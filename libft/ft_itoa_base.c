/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:14:36 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/21 10:36:35 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*set_base(unsigned int hexa, int base, char *str, int i)
{
	while (hexa != 0)
	{
		if ((hexa % base) < 10)
			str[i - 1] = (hexa % base) + '0';
		else
			str[i - 1] = (hexa % base) + 55;
		hexa /= base;
		i--;
	}
	return (str);
}

char		*ft_itoa_base(unsigned int nbr, int base)
{
	char			*str;
	unsigned int	hexa;
	int				i;

	str = NULL;
	i = 0;
	hexa = nbr;
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr)
	{
		nbr /= base;
		i++;
	}
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	str = set_base(hexa, base, str, i);
	return (str);
}
