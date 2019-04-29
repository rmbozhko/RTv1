/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 17:06:29 by yvasin            #+#    #+#             */
/*   Updated: 2017/01/04 17:57:55 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char const	*new;
	char		*res;

	new = s;
	if (!s)
		return (NULL);
	while (*new != '\0')
		++new;
	if (!(res = (char*)malloc(sizeof(char) * (new - s + 1))))
		return (NULL);
	new = s;
	while (*new)
	{
		res[new - s] = f(*new);
		new++;
	}
	res[new - s] = '\0';
	return (res);
}
