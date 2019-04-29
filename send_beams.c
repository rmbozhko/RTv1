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

t_matrix	xyz_rotation(t_matrix *v, t_env *env)
{
	t_matrix v1;

	v->x = (2 * ((env->x + 0.5) * INV_WIDTH) - 1) * ANGLE * ASP_RATIO;
	v->y = (1 - 2 * ((env->y + 0.5) * INV_HEIGHT)) * ANGLE;
	v->z = 1;
	v1 = abscissa_rotation(v, env->alpha);
	v1 = ordinate_rotation(&v1, env->beta);
	v1 = aplikata_rotation(&v1, env->gamma);
	v1 = optim_settup(&v1);
	return (v1);
}

void	pull_beam(t_env *env)
{
	t_beam		ray;
	t_beam		shadow_ray;
	double		light_d;
	int			cur_obj;

	ray.start.x = 800;
	ray.start.y = 500;
	ray.start.z = -2100;
	while (env->y < HEIGHT)
	{
		while (env->x < WIDTH)
		{
			ray.dir = xyz_rotation(&ray.dir, env);
			if ((cur_obj = determine_interacting(env, &ray, 800000)) != -1)
			{
				shadow_ray = determine_sbeam(env, &ray);
				light_d = sqrt(mult_matrix(&env->dist_to_light,
					&env->dist_to_light));
				window_setting(env, &shadow_ray, light_d, cur_obj);
			}
			env->x++;
		}
		env->x = 0;
		env->y++;
	}
}

int		determine_interacting(t_env *env, t_beam *ray, double light_d)
{
	int		cur_obj;
	int		i;

	env->t = 200000.0;
	cur_obj = -1;
	i = 0;
	while (i < 6)
	{
		if (objects_hinteracting(&env->obj[i], ray, env, light_d) == 1)
			cur_obj = i;
		i++;
	}
	return (cur_obj);
}

t_beam	determine_sbeam(t_env *env, t_beam *ray)
{
	t_beam	shadow_ray;

	env->scaled = mult_matx_skl(&ray->dir, env->t);
	env->new_start = summ_matrix(&ray->start, &env->scaled);
	env->dist_to_light = min_matrix(&env->light.pos, &env->new_start);
	shadow_ray.start = env->new_start;
	shadow_ray.dir = optim_settup(&env->dist_to_light);
	return (shadow_ray);
}

void	depict_entity(t_env *env, int cur_obj, t_matrix *dir)
{
	t_matrix	norm;
	t_paint		color_dark;

	norm = optimization(&(env->obj[cur_obj]), &env->new_start, dir);
	color_dark = env->obj[cur_obj].color;
	color_dark.tr = 230 * (1 - calc_angle_matrix(&norm, dir));
	if (calc_angle_matrix(&norm, dir) >= 0.94)
	{
		color_dark.r += (255 - color_dark.r)
			* calc_angle_matrix(&norm, dir) * 15;
		color_dark.g += (255 - color_dark.g)
			* calc_angle_matrix(&norm, dir) * 15;
		color_dark.b += (255 - color_dark.b)
			* calc_angle_matrix(&norm, dir) * 15;
	}
	insert_pixel(env, env->x, env->y, &color_dark);
}

void	window_setting(t_env *env, t_beam *shadow_ray,
			double light_d, int cur_obj)
{
	if (determine_interacting(env, shadow_ray, light_d) == -1)
		depict_entity(env, cur_obj, &shadow_ray->dir);
	else
	{
		env->obj[cur_obj].color.tr = 230;
		insert_pixel(env, env->x, env->y, &(env->obj[cur_obj].color));
	}
}
