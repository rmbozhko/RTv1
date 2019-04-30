#include "rtv1.h"

void	instantiating_fentity(t_env *env)
{
	env->tdparaleg_f.location.ab = 1200;
	env->tdparaleg_f.location.ord = 500;
	env->tdparaleg_f.location.apl = -400;
	env->tdparaleg_f.coord_move.ab = 0;
	env->tdparaleg_f.coord_move.ord = 1;
	env->tdparaleg_f.coord_move.apl = 1;
	env->tdparaleg_f.div_diameter = 100 * 100;
	env->entities_strg[0].paint = BLUE;
	env->entities_strg[0].ent = &env->tdparaleg_f;
	env->entities_strg[0].ent_id = 2;
	env->tdcircle.centre.ab = 550;
	env->tdcircle.centre.ord = 500;
	env->tdcircle.centre.apl = 0;
	env->tdcircle.div_diameter = 250 * 250;
	env->entities_strg[1].paint = MAGENTA;
	env->entities_strg[1].ent = &env->tdcircle;
	env->entities_strg[1].ent_id = 1;
	instantiating_sentity(env);
	instantiating_tentity(env);
}

void	instantiating_sentity(t_env *env)
{
	env->tdparaleg_s.location.ab = 500;
	env->tdparaleg_s.location.ord = 500;
	env->tdparaleg_s.location.apl = 0;
	env->tdparaleg_s.coord_move.ab = 1;
	env->tdparaleg_s.coord_move.ord = 0;
	env->tdparaleg_s.coord_move.apl = 1;
	env->tdparaleg_s.div_diameter = 50 * 50;
	env->entities_strg[2].paint = CYAN;
	env->entities_strg[2].ent = &env->tdparaleg_s;
	env->entities_strg[2].ent_id = 2;
	env->surface_f.dot.ab = 400;
	env->surface_f.dot.ord = 100;
	env->surface_f.dot.apl = 2500;
	env->surface_f.optimize_rate.ab = 0;
	env->surface_f.optimize_rate.ord = 1;
	env->surface_f.optimize_rate.apl = 0;
	env->entities_strg[3].paint = GREEN;
	env->entities_strg[3].ent = &env->surface_f;
	env->entities_strg[3].ent_id = 4;
}

void	instantiating_tentity(t_env *env)
{
	env->surface_s.dot.ab = 400;
	env->surface_s.dot.ord = 100;
	env->surface_s.dot.apl = 2500;
	env->surface_s.optimize_rate.ab = 0;
	env->surface_s.optimize_rate.ord = 0;
	env->surface_s.optimize_rate.apl = 1;
	env->entities_strg[4].paint = WHITE;
	env->entities_strg[4].ent = &env->surface_s;
	env->entities_strg[4].ent_id = 4;
	env->trg.location.ab = 550;
	env->trg.location.ord = 500;
	env->trg.location.apl = 0;
	env->trg.coord_move.ab = -1;
	env->trg.coord_move.ord = 1;
	env->trg.coord_move.apl = 0;
	env->trg.corner = 10 * (M_PI / 180);
	env->entities_strg[5].paint = RED;
	env->entities_strg[5].ent = &env->trg;
	env->entities_strg[5].ent_id = 3;
	env->glow.location.ab = 2900;
	env->glow.location.ord = 1900;
	env->glow.location.apl = -1600;
}