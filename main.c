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
	if (keycode == 53)
		exit(1);
	return (0);
}

static void	init_objs1(t_vedro *vedro)
{
	vedro->cylinder.pos.x = 1200;
	vedro->cylinder.pos.y = 500;
	vedro->cylinder.pos.z = -400;
	vedro->cylinder.rot.x = 0;
	vedro->cylinder.rot.y = 1;
	vedro->cylinder.rot.z = 1;
	vedro->cylinder.radius = 100;
	vedro->cylinder.radius2 = vedro->cylinder.radius * vedro->cylinder.radius;
	vedro->obj[0].color = BLUE;
	vedro->obj[0].obj = &vedro->cylinder;
	vedro->obj[0].type = 2;
	vedro->sphere.centre.x = 550;
	vedro->sphere.centre.y = 500;
	vedro->sphere.centre.z = 0;
	vedro->sphere.radius = 250;
	vedro->sphere.radius2 = vedro->sphere.radius * vedro->sphere.radius;
	vedro->obj[1].color = MAGENTA;
	vedro->obj[1].obj = &vedro->sphere;
	vedro->obj[1].type = 1;
}

static void	init_objs2(t_vedro *vedro)
{
	vedro->cylinder2.pos.x = 500;
	vedro->cylinder2.pos.y = 500;
	vedro->cylinder2.pos.z = 0;
	vedro->cylinder2.rot.x = 1;
	vedro->cylinder2.rot.y = 0;
	vedro->cylinder2.rot.z = 1;
	vedro->cylinder2.radius = 50;
	vedro->cylinder2.radius2 = vedro->cylinder2.radius
		* vedro->cylinder2.radius;
	vedro->obj[2].color = CYAN;
	vedro->obj[2].obj = &vedro->cylinder2;
	vedro->obj[2].type = 2;
	vedro->plane.point.x = 400;
	vedro->plane.point.y = 100;
	vedro->plane.point.z = 2500;
	vedro->plane.normal.x = 0;
	vedro->plane.normal.y = 1;
	vedro->plane.normal.z = 0;
	vedro->obj[3].color = GREEN;
	vedro->obj[3].obj = &vedro->plane;
	vedro->obj[3].type = 4;
}

static void	init_objs3(t_vedro *vedro)
{
	vedro->plane1.point.x = 400;
	vedro->plane1.point.y = 100;
	vedro->plane1.point.z = 2500;
	vedro->plane1.normal.x = 0;
	vedro->plane1.normal.y = 0;
	vedro->plane1.normal.z = 1;
	vedro->obj[4].color = WHITE;
	vedro->obj[4].obj = &vedro->plane1;
	vedro->obj[4].type = 4;
	vedro->cone.pos.x = 550;
	vedro->cone.pos.y = 500;
	vedro->cone.pos.z = 0;
	vedro->cone.rot.x = -1;
	vedro->cone.rot.y = 1;
	vedro->cone.rot.z = 0;
	vedro->cone.angle = 10 * (M_PI / 180);
	vedro->obj[5].color = RED;
	vedro->obj[5].obj = &vedro->cone;
	vedro->obj[5].type = 3;
	vedro->light.pos.x = 2900;
	vedro->light.pos.y = 1900;
	vedro->light.pos.z = -1600;
}

int			main(void)
{
	t_vedro	vedro;
	
	ft_init_env(&vedro);
	init_objs1(&vedro);
	init_objs2(&vedro);
	init_objs3(&vedro);
	ray_trace(&vedro);
	mlx_put_image_to_window(vedro.mlx, vedro.win, vedro.img, 0, 0);
	mlx_hook(vedro.win, 2, 5, key_control, &vedro);
	mlx_loop(vedro.mlx);
	return (0);
}
