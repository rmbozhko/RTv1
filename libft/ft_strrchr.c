/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:48:14 by yvasin            #+#    #+#             */
/*   Updated: 2017/01/06 20:58:09 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *res;

	res = s;
	while (*res != '\0')
		res++;
	while (*res != (char)c && res >= s)
		res--;
	return (*res == (char)c ? (char*)res : NULL);
}
