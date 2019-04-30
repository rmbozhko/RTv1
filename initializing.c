/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:54:11 by yvasin            #+#    #+#             */
/*   Updated: 2017/04/05 19:54:11 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_init_env(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "RTv1");
	env->x = 0;
	env->y = 0;
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->bpp = BPP;
	env->e = 0;
	env->data = mlx_get_data_addr(env->img, &env->bpp,
		&env->sline, &env->e);
	instantiating_fentity(env);
	pull_beam(env);
}

void	insert_pixel(t_env *env, int x, int y, t_paint *color)
{
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		env->data[((y * env->sline) + (x * 4))] = color->red;
		env->data[((y * env->sline) + (x * 4)) + 1] = color->green;
		env->data[((y * env->sline) + (x * 4)) + 2] = color->blue;
		env->data[((y * env->sline) + (x * 4)) + 3] = color->clarity;
	}
}
