/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:27:10 by yvasin            #+#    #+#             */
/*   Updated: 2017/01/06 18:33:31 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *res;

	res = s;
	while (n-- > 0)
	{
		if (*res++ == (unsigned char)c)
			return ((void *)(res - 1));
	}
	return (NULL);
}
