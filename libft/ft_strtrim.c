/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:14:29 by yvasin            #+#    #+#             */
/*   Updated: 2017/01/12 20:08:40 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	length;
	char	*res;

	i = 0;
	length = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == ft_strlen(s) || ft_strlen(s) == 0)
		return (ft_strnew(0));
	length = ft_strlen(s) - 1;
	while (s[length] == ' ' || s[length] == '\t' ||
		s[length] == '\n')
		length--;
	res = ft_strsub(s, i, length - i + 1);
	return (res);
}
