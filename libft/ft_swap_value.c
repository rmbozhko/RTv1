/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:37:26 by yvasin            #+#    #+#             */
/*   Updated: 2017/03/06 16:37:28 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_swap_value(int *value1, int *value2)
{
	int temp_swap;

	temp_swap = *value1;
	*value1 = *value2;
	*value2 = temp_swap;
}

void		ft_swap_value_d(double *value1, double *value2)
{
	double temp_swap;

	temp_swap = *value1;
	*value1 = *value2;
	*value2 = temp_swap;
}
