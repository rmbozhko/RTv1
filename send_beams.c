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

inline double		get_width_inverse(t_env *env)
{
	return ((double)(1.0 / (double)env->width));
}

inline double		get_height_inverse(t_env *env)
{
	return ((double)(1.0 / (double)env->height));
}

t_matrix	xyz_rotation(t_matrix *richtung, t_env *env)
{
	richtung->ab = (2 * ((env->x + 0.5) * INV_WIDTH) - 1) * ANGLE * ASP_RATIO;
	richtung->ord = (1 - 2 * ((env->y + 0.5) * INV_HEIGHT)) * ANGLE;
	richtung->apl = 1;

	return (optim_settup(richtung));
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
				light_d = sqrt(mult_matrix(&env->strecke_zur_licht,
					&env->strecke_zur_licht));
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

	env->skl = MAGIC_NUM;
	counter = -1;
	id = -1;

	while (++id < 6)
		counter = (objects_hinteracting(&env->entities_strg[id], beam, env, light_d) == 1) ? id : counter;
	return (counter);
}

t_beam	determine_sbeam(t_env *env, t_beam *beam)
{
	t_beam	beam_chorn;

	env->multpl_skl = mult_matx_skl(&beam->richtung, env->skl);
	env->neues_anfang = summ_matrix(&beam->anfang, &env->multpl_skl);
	env->strecke_zur_licht = min_matrix(&env->glow.location, &env->neues_anfang);
	beam_chorn.anfang = env->neues_anfang;
	beam_chorn.richtung = optim_settup(&env->strecke_zur_licht);
	return (beam_chorn);
}

void	depict_entity(t_env *env, int cur_obj, t_matrix *dir)
{
	t_matrix	norm;
	t_paint		color_dark;

	norm = optimization(&(env->entities_strg[cur_obj]), &env->neues_anfang, dir);
	color_dark = env->entities_strg[cur_obj].paint;
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
		env->entities_strg[cur_obj].paint.clarity = 255;
		insert_pixel(env, env->x, env->y, &(env->entities_strg[cur_obj].paint));
	}
}
