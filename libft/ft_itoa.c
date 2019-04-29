/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 19:25:44 by yvasin            #+#    #+#             */
/*   Updated: 2017/01/05 20:46:45 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(int n)
{
	if (n < 0)
		return (1 + ft_nblen(-n));
	if (n < 10)
		return (1);
	return (1 + ft_nblen(n / 10));
}

char		*ft_itoa(int n)
{
	int		neg;
	int		length;
	int		i;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = (n < 0 ? 1 : 0);
	length = ft_nblen(n);
	res = (char*)malloc(sizeof(char) * (length + 1));
	if (res)
	{
		n = (n < 0 ? -n : n);
		i = length - 1;
		while (i >= neg)
		{
			res[i] = (n % 10) + '0';
			n = n / 10;
			i--;
		}
		if (neg)
			res[0] = '-';
		res[length] = '\0';
	}
	return (res);
}
