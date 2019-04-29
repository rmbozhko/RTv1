/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 15:27:19 by yvasin            #+#    #+#             */
/*   Updated: 2017/02/25 15:33:29 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hex_to_int(char *s)
{
	int hex;
	int index;
	int i;
	int n;

	i = 0;
	if (ft_strchr(s, 'x'))
		s = ft_strchr(s, 'x');
	s++;
	n = 0;
	index = 1;
	while (index == 1)
	{
		if (s[i] >= '0' && s[i] <= '9')
			hex = s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			hex = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			hex = s[i] - 'A' + 10;
		else
			index = 0;
		index == 1 ? n = 16 * n + hex : 0;
		i++;
	}
	return (n);
}
