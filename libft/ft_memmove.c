/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:05:07 by yvasin            #+#    #+#             */
/*   Updated: 2017/01/06 18:43:50 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	void *save;

	save = dst;
	if (dst > src)
	{
		while (n-- > 0)
			*((unsigned char*)(dst + n)) = *((unsigned char*)(src + n));
	}
	else if (dst < src)
	{
		while (n-- > 0)
			*((unsigned char*)(dst++)) = *((unsigned char*)(src++));
	}
	return (save);
}
