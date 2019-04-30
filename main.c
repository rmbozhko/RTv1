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

static int	key_binds(int keycode, t_env* env)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == P_LTTR)
		ft_make_printscreen(env);
	return (0);
}

int			main(void)
{
	t_env	env;
	
	ft_init_env(&env, WIDTH, HEIGHT);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	mlx_hook(env.win, 2, 5, key_binds, &env);
	mlx_loop(env.mlx);
	return (0);
}
