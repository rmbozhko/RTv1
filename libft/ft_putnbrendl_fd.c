/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrendl_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:34:08 by rbozhko           #+#    #+#             */
/*   Updated: 2017/11/12 18:34:09 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbrendl_fd(int num, int fd)
{
	if (fd >= 0 && fd <= 4096)
	{
		ft_putnbr_fd(num, fd);
		ft_putchar_fd('\n', fd);
	}
}