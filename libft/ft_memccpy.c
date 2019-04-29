/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:43:24 by yvasin            #+#    #+#             */
/*   Updated: 2017/01/08 22:06:34 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*to;
	unsigned char const	*from;

	from = src;
	to = dst;
	while (n-- > 0)
	{
		*to = *from;
		if (*to == (unsigned char)c)
			return (to + 1);
		to++;
		from++;
	}
	return (NULL);
}
