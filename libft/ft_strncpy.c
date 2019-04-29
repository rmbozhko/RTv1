/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 17:43:03 by yvasin            #+#    #+#             */
/*   Updated: 2016/12/28 18:28:19 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *save;

	save = dst;
	while (*src != '\0' && len > 0)
	{
		*(dst++) = *(src++);
		len--;
	}
	while (len-- > 0)
		*(dst++) = '\0';
	return (save);
}
