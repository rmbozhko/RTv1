/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:46:17 by yvasin            #+#    #+#             */
/*   Updated: 2017/04/05 19:46:18 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	key_control(int keycode)
{
	if (keycode == ESC)
		exit(0);
	return (0);
}

int			main(void)
{
	t_vedro	vedro;
	
	ft_init_env(&vedro);
	ray_trace(&vedro);
	mlx_put_image_to_window(vedro.mlx, vedro.win, vedro.img, 0, 0);
	mlx_hook(vedro.win, 2, 5, key_control, &vedro);
	mlx_loop(vedro.mlx);
	return (0);
}
