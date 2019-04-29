/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:52:01 by yvasin            #+#    #+#             */
/*   Updated: 2017/01/06 19:01:13 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *kek1;
	const unsigned char *kek2;

	kek1 = s1;
	kek2 = s2;
	if (n == 0)
		return (0);
	while (n-- > 1 && *kek1 == *kek2)
	{
		kek1++;
		kek2++;
	}
	return (*kek1 - *kek2);
}
