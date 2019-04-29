/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 18:55:40 by yvasin            #+#    #+#             */
/*   Updated: 2017/01/07 19:01:07 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *save1;
	const char *save2;

	save2 = little;
	while (*big != '\0')
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
