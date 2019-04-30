/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_initialization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:51:11 by rbozhko           #+#    #+#             */
/*   Updated: 2019/04/30 11:52:03 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	instantiate_attributes(t_env *env)
{
	env->entities_strg[0].paint = BLAUE;
	env->entities_strg[0].ent = &env->tdparaleg_f;
	env->entities_strg[0].ent_id = TDPARALEG;
	env->entities_strg[1].paint = MAGG;
	env->entities_strg[1].ent = &env->tdcircle;
	env->entities_strg[1].ent_id = TDCIRCLE;
	env->entities_strg[2].paint = PINK;
	env->entities_strg[2].ent = &env->tdparaleg_s;
	env->entities_strg[2].ent_id = TDPARALEG;
	env->entities_strg[3].paint = WEISS;
	env->entities_strg[3].ent = &env->surface_f;
	env->entities_strg[3].ent_id = SURFACE;
	env->entities_strg[4].paint = WEISS;
	env->entities_strg[4].ent = &env->surface_s;
	env->entities_strg[4].ent_id = SURFACE;
	env->entities_strg[5].paint = ROT;
	env->entities_strg[5].ent = &env->trg;
	env->entities_strg[5].ent_id = TRG;
}

void	instantiating_fentity(t_env *env)
{
	instantiate_entity(&env->tdparaleg_f.location,
		&env->tdparaleg_f.coord_move, TDPARALEG);
	env->tdparaleg_f.div_diameter =
		instantiate_div_diameter(TDPARALEG, NULL, NULL);
	instantiate_entity(&env->tdcircle.location, NULL, TDCIRCLE);
	env->tdcircle.div_diameter =
		instantiate_div_diameter(TDCIRCLE, NULL, NULL);
	instantiating_other_entities(TDPARALEG,
			&env->tdparaleg_s.location, &env->tdparaleg_s.coord_move);
	env->tdparaleg_s.div_diameter = 10000 / 4;
	instantiate_entity(&env->surface_f.dot,
			&env->surface_s.optimize_rate, SURFACE);
	env->surface_s.optimize_rate.ord = 0;
	env->surface_s.optimize_rate.ab = 0;
	env->surface_s.optimize_rate.apl = 1;
	env->surface_s.dot.ab = 400;
	env->surface_s.dot.ord = 100;
	env->surface_s.dot.apl = 2500;
	env->trg.corner =
		instantiate_div_diameter(TRG, &env->trg.location, &env->trg.coord_move);
	instantiate_attributes(env);
	instantiate_glow(env);
}
