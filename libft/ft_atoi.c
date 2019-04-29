/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 21:22:11 by yvasin            #+#    #+#             */
/*   Updated: 2017/01/08 21:26:17 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int number;
	int negative;

	while (ft_isspace(*str))
		++str;
	negative = *str == '-' ? -1 : 1;
	if (*str == '+' || *str == '-')
		++str;
	number = 0;
	while (ft_isdigit(*str))
		number = 10 * number + negative * (*str++ - '0');
	return (number);
}
