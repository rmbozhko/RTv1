/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:39:17 by rbozhko           #+#    #+#             */
/*   Updated: 2019/04/30 11:42:56 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		instantiate_entity(t_matrix *loc, t_matrix *c, int id)
{
	if (id == TDPARALEG)
	{
		loc->ab = 1200;
		loc->ord = 500;
		loc->apl = -400;
		c->ab = 0;
		c->ord = 1;
		c->apl = 1;
	}
	else if (id == TDCIRCLE)
	{
		loc->ab = 550;
		loc->ord = 500;
		loc->apl = 0;
	}
	else if (id == SURFACE)
	{
		loc->ab = 400;
		loc->ord = 100;
		loc->apl = 2500;
		c->ab = 0;
		c->ord = 1;
		c->apl = 0;
	}
}

void		depict_entity(t_env *env, int ent, t_matrix *richt)
{
	t_matrix	mtrx;
	t_paint		dpaint;
	size_t		ent_to_depict;

	ent_to_depict = env->entities_strg[ent].ent_id;
	mtrx = optimization(&(env->entities_strg[ent]), &env->neues_anfang, richt);
	dpaint = env->entities_strg[ent].paint;
	dpaint.clarity = 230 * (1 - calc_angle_matrix(&mtrx, richt));
	if (calc_angle_matrix(&mtrx, richt) >= BOUND)
		update_dpaint(&dpaint, &mtrx, richt);
	insert_pixel(env, X, Y, &dpaint);
}

unsigned	instantiate_div_diameter(int id, t_matrix *loc, t_matrix *coord)
{
	unsigned		ret_code;

	ret_code = 0;
	if (id == TDPARALEG)
	{
		ret_code = 10000;
	}
	else if (id == TDCIRCLE)
	{
		ret_code = 250 * 250;
	}
	else if (id == TRG)
	{
		ret_code = 10 * (M_PI / 180);
		loc->ab = 550;
		loc->ord = 500;
		loc->apl = 0;
		coord->ab = -1;
		coord->ord = 1;
		coord->apl = 0;
	}
	return (ret_code);
}

void		instantiate_glow(t_env *env)
{
	env->glow.location.ab = 2900;
	env->glow.location.ord = 1900;
	env->glow.location.apl = -1600;
}

void		inst_other_entities(int id, t_matrix *loc, t_matrix *coord)
{
	if (id == TDPARALEG)
	{
		loc->ab = 500;
		loc->ord = 500;
		loc->apl = 0;
		coord->ab = 1;
		coord->ord = 0;
		coord->apl = 1;
	}
}
