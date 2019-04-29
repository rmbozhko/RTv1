/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:19:34 by yvasin            #+#    #+#             */
/*   Updated: 2017/01/08 22:03:06 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_size;
	size_t ret;

	dst_size = ft_strlen(dst);
	ret = ft_strlen(src) + (size < dst_size ? size : dst_size);
	dst += dst_size;
	while ((++dst_size) < size && *src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (ret);
}
