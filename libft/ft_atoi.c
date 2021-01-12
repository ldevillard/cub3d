/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:09:37 by ldevilla          #+#    #+#             */
/*   Updated: 2020/11/25 11:00:23 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		check_ws(const char *str, unsigned int i)
{
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

int						ft_atoi(const char *str)
{
	unsigned int i;
	unsigned int neg;
	unsigned int sign;
	unsigned int result;

	i = check_ws(str, 0);
	neg = 0;
	sign = 0;
	result = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg++;
		sign++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	if (sign <= 1 && neg == 1)
		return (-result);
	else if (sign <= 1 && neg == 0)
		return (result);
	return (0);
}
