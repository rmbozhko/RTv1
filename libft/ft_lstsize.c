/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 17:39:42 by yvasin            #+#    #+#             */
/*   Updated: 2017/01/15 17:42:06 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *list)
{
	unsigned int	i;

	i = 0;
	if (!list)
		return (i);
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
