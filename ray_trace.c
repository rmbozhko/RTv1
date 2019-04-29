/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:52:18 by yvasin            #+#    #+#             */
/*   Updated: 2017/05/15 18:52:19 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ray_trace(t_vedro *vedro)
{
	t_ray		ray;
	t_ray		shadow_ray;
	double		light_d;
	int			cur_obj;

	ray.start.x = 800;
	ray.start.y = 500;
	ray.start.z = -2100;
	while (vedro->y < HEIGHT)
	{
		while (vedro->x < WIDTH)
		{
			ray.dir = rotate_init_ray(&ray.dir, vedro);
			if ((cur_obj = find_intersection(vedro, &ray, 800000)) != -1)
			{
				shadow_ray = find_shadow_ray(vedro, &ray);
				light_d = sqrt(vector_dot(&vedro->dist_to_light,
					&vedro->dist_to_light));
				fill_screen(vedro, &shadow_ray, light_d, cur_obj);
			}
			vedro->x++;
		}
		vedro->x = 0;
		vedro->y++;
	}
}

int		find_intersection(t_vedro *vedro, t_ray *ray, double light_d)
{
	int		cur_obj;
	int		i;

	vedro->t = 200000.0;
	cur_obj = -1;
	i = 0;
	while (i < 6)
	{
		if (intersection(&vedro->obj[i], ray, vedro, light_d) == 1)
			cur_obj = i;
		i++;
	}
	return (cur_obj);
}

t_ray	find_shadow_ray(t_vedro *vedro, t_ray *ray)
{
	t_ray	shadow_ray;

	vedro->scaled = vector_scale(&ray->dir, vedro->t);
	vedro->new_start = vector_add(&ray->start, &vedro->scaled);
	vedro->dist_to_light = vector_sub(&vedro->light.pos, &vedro->new_start);
	shadow_ray.start = vedro->new_start;
	shadow_ray.dir = normalize(&vedro->dist_to_light);
	return (shadow_ray);
}

void	draw_object(t_vedro *vedro, int cur_obj, t_vector *dir)
{
	t_vector	norm;
	t_color		color_dark;

	norm = normal(&(vedro->obj[cur_obj]), &vedro->new_start, dir);
	color_dark = vedro->obj[cur_obj].color;
	color_dark.tr = 230 * (1 - find_cos_vectors(&norm, dir));
	if (find_cos_vectors(&norm, dir) >= 0.94)
	{
		color_dark.r += (255 - color_dark.r)
			* find_cos_vectors(&norm, dir) * 15;
		color_dark.g += (255 - color_dark.g)
			* find_cos_vectors(&norm, dir) * 15;
		color_dark.b += (255 - color_dark.b)
			* find_cos_vectors(&norm, dir) * 15;
	}
	im_pp(vedro, vedro->x, vedro->y, &color_dark);
}

void	fill_screen(t_vedro *vedro, t_ray *shadow_ray,
			double light_d, int cur_obj)
{
	if (find_intersection(vedro, shadow_ray, light_d) == -1)
		draw_object(vedro, cur_obj, &shadow_ray->dir);
	else
	{
		vedro->obj[cur_obj].color.tr = 230;
		im_pp(vedro, vedro->x, vedro->y, &(vedro->obj[cur_obj].color));
	}
}
