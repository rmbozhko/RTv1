/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 17:35:04 by yvasin            #+#    #+#             */
/*   Updated: 2017/01/04 17:57:17 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char const		*new;
	char			*res;
	unsigned int	i;

	new = s;
	i = 0;
	if (!s)
		return (NULL);
	while (*new != '\0')
		++new;
	if (!(res = (char*)malloc(sizeof(char) * (new - s + 1))))
		return (NULL);
	new = s;
	while (*new)
	{
		res[new - s] = f(i, *new);
		new++;
		i++;
	}
	res[new - s] = '\0';
	return (res);
}
