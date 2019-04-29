/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:36:41 by yvasin            #+#    #+#             */
/*   Updated: 2017/01/03 15:41:55 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ans;

	if (!(ans = malloc(size)))
		return (NULL);
	while (size-- > 0)
		*((unsigned char*)(ans + size)) = 0;
	return (ans);
}
