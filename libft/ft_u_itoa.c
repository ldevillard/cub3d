/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevilla <ldevilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:02:33 by ldevilla          #+#    #+#             */
/*   Updated: 2020/12/16 10:05:56 by ldevilla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_n(long n)
{
	int i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void		check_n(long int *nb, int *neg, int *count)
{
	*nb *= -1;
	*neg += 1;
	*count += 1;
}

char			*ft_u_itoa(unsigned int n)
{
	int		count;
	int		neg;
	char	*str;
	int		i;
	long	nb;

	nb = (long)n;
	count = 0;
	neg = 0;
	if (nb < 0)
		check_n(&nb, &neg, &count);
	count += count_n(nb);
	i = 0;
	if (!(str = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	if (neg > 0)
		str[count - 1] = '-';
	while (nb > 9)
	{
		str[i++] = nb % 10 + '0';
		nb /= 10;
	}
	str[i] = nb % 10 + '0';
	str[count] = '\0';
	return (ft_strrev(str));
}
