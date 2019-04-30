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

	v->ab = (2 * ((env->x + 0.5) * INV_WIDTH) - 1) * ANGLE * ASP_RATIO;
	v->ord = (1 - 2 * ((env->y + 0.5) * INV_HEIGHT)) * ANGLE;
	v->apl = 1;
	v1 = abscissa_rotation(v);
	v1 = ordinate_rotation(&v1);
	v1 = aplikata_rotation(&v1);
	v1 = optim_settup(&v1);
	return (v1);
}

void	pull_beam(t_env *env)
{
	t_beam		beam;
	t_beam		beam_chorn;
	double		light_d;
	int			cur_obj;

	beam.anfang.ab = 800;
	beam.anfang.ord = 500;
	beam.anfang.apl = -2100;
	while (env->y < HEIGHT)
	{
		while (env->x < WIDTH)
		{
			beam.richtung = xyz_rotation(&beam.richtung, env);
			if ((cur_obj = determine_interacting(env, &beam, 800000)) != -1)
			{
				beam_chorn = determine_sbeam(env, &beam);
				light_d = sqrt(mult_matrix(&env->dist_to_light,
					&env->dist_to_light));
				window_setting(env, &beam_chorn, light_d, cur_obj);
			}
			env->x++;
		}
		env->x = 0;
		env->y++;
	}
}

int		determine_interacting(t_env *env, t_beam *beam, double light_d)
{
	int		counter;
	int		id;

	env->t = MAGIC_NUM;
	counter = -1;
	id = -1;

	while (++id < 6)
		counter = (objects_hinteracting(&env->obj[id], beam, env, light_d) == 1) ? id : counter;
	return (counter);
}

t_beam	determine_sbeam(t_env *env, t_beam *beam)
{
	t_beam	beam_chorn;

	env->scaled = mult_matx_skl(&beam->richtung, env->t);
	env->new_start = summ_matrix(&beam->anfang, &env->scaled);
	env->dist_to_light = min_matrix(&env->light.location, &env->new_start);
	beam_chorn.anfang = env->new_start;
	beam_chorn.richtung = optim_settup(&env->dist_to_light);
	return (beam_chorn);
}

void	depict_entity(t_env *env, int cur_obj, t_matrix *dir)
{
	t_matrix	norm;
	t_paint		color_dark;

	norm = optimization(&(env->obj[cur_obj]), &env->new_start, dir);
	color_dark = env->obj[cur_obj].paint;
	color_dark.clarity = 230 * (1 - calc_angle_matrix(&norm, dir));
	if (calc_angle_matrix(&norm, dir) >= 0.94)
	{
		color_dark.red += (255 - color_dark.red)
			* calc_angle_matrix(&norm, dir) * 15;
		color_dark.green += (255 - color_dark.green)
			* calc_angle_matrix(&norm, dir) * 15;
		color_dark.blue += (255 - color_dark.blue)
			* calc_angle_matrix(&norm, dir) * 15;
	}
	insert_pixel(env, env->x, env->y, &color_dark);
}

void	window_setting(t_env *env, t_beam *shadow_ray,
			double light_d, int cur_obj)
{
	if (determine_interacting(env, shadow_ray, light_d) < 0)
		depict_entity(env, cur_obj, &shadow_ray->richtung);
	else
	{
		env->obj[cur_obj].paint.clarity = 255;
		insert_pixel(env, env->x, env->y, &(env->obj[cur_obj].paint));
	}
}
