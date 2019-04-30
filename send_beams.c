/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_beams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:43:32 by rbozhko           #+#    #+#             */
/*   Updated: 2019/04/30 11:46:21 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		get_width_inverse(t_env *env)
{
	return ((double)(1.0 / (double)env->width));
}

t_matrix	ordinate_rotation(t_matrix *dir)
{
	t_matrix new_dir;

	new_dir.ab = dir->ab;
	new_dir.ord = dir->ord;
	new_dir.apl = dir->apl;
	return (new_dir);
}

void		update_dpaint(t_paint *paint, t_matrix *mtrx, t_matrix *richt)
{
	double		coef;
	double		alpha;

	coef = 60.0 / 2.0 / 2.0;
	alpha = calc_angle_matrix(mtrx, richt) * coef;
	paint->red += (MAX_UCHAR - paint->red) * alpha;
	paint->blue += (MAX_UCHAR - paint->blue) * alpha;
	paint->green += (MAX_UCHAR - paint->green) * alpha;
}

t_beam		determine_sbeam(t_env *env)
{
	t_beam	beam_chorn;

	beam_chorn.anfang = env->neues_anfang;
	beam_chorn.richtung = optim_settup(&env->s_of_l);
	return (beam_chorn);
}

void		window_setting(double glow, int ent, t_beam *ch_beam, t_env *env)
{
	t_beam		temp;

	temp = determine_sbeam(env);
	env->multpl_skl = mult_matx_skl(&ch_beam->richtung, env->skl);
	env->neues_anfang = summ_matrix(&ch_beam->anfang, &env->multpl_skl);
	env->s_of_l = min_matrix(&env->glow.location, &env->neues_anfang);
	if (determine_interacting(env, glow, &temp) == -1)
		depict_entity(env, ent, &temp.richtung);
	else
	{
		env->entities_strg[ent].paint.clarity = env->clarity_coef;
		insert_pixel(env, X, Y, &(env->entities_strg[ent].paint));
	}
}
