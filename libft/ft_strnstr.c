/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 20:27:08 by yvasin            #+#    #+#             */
/*   Updated: 2017/01/08 20:49:11 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*save1;
	const char	*save2;
	const char	*save;
	size_t		len2;

	len2 = ft_strlen(little);
	save2 = little;
	save = big;
	while (*big != '\0' && (size_t)(big - save) < len &&
		len - (big - save) >= len2)
	{
		save1 = big;
		while (*little != '\0' && *big == *little)
		{
			++big;
			++little;
		}
		if (*little == '\0')
			return ((char*)save1);
		big = save1 + 1;
		little = save2;
	}
	return (*little == '\0' ? (char*)big : NULL);
}
