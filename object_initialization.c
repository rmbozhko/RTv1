#include "rtv1.h"

void	instantiating_fentity(t_env *env)
{
	env->cylinder.location.ab = 1200;
	env->cylinder.location.ord = 500;
	env->cylinder.location.apl = -400;
	env->cylinder.coord_move.ab = 0;
	env->cylinder.coord_move.ord = 1;
	env->cylinder.coord_move.apl = 1;
	env->cylinder.div_diameter = 100 * 100;
	env->obj[0].paint = BLUE;
	env->obj[0].ent = &env->cylinder;
	env->obj[0].ent_id = 2;
	env->sphere.centre.ab = 550;
	env->sphere.centre.ord = 500;
	env->sphere.centre.apl = 0;
	env->sphere.div_diameter = 250 * 250;
	env->obj[1].paint = MAGENTA;
	env->obj[1].ent = &env->sphere;
	env->obj[1].ent_id = 1;
	instantiating_sentity(env);
	instantiating_tentity(env);
}

void	instantiating_sentity(t_env *env)
{
	env->cylinder2.location.ab = 500;
	env->cylinder2.location.ord = 500;
	env->cylinder2.location.apl = 0;
	env->cylinder2.coord_move.ab = 1;
	env->cylinder2.coord_move.ord = 0;
	env->cylinder2.coord_move.apl = 1;
	env->cylinder2.div_diameter = 50 * 50;
	env->obj[2].paint = CYAN;
	env->obj[2].ent = &env->cylinder2;
	env->obj[2].ent_id = 2;
	env->plane.dot.ab = 400;
	env->plane.dot.ord = 100;
	env->plane.dot.apl = 2500;
	env->plane.optimize_rate.ab = 0;
	env->plane.optimize_rate.ord = 1;
	env->plane.optimize_rate.apl = 0;
	env->obj[3].paint = GREEN;
	env->obj[3].ent = &env->plane;
	env->obj[3].ent_id = 4;
}

void	instantiating_tentity(t_env *env)
{
	env->plane1.dot.ab = 400;
	env->plane1.dot.ord = 100;
	env->plane1.dot.apl = 2500;
	env->plane1.optimize_rate.ab = 0;
	env->plane1.optimize_rate.ord = 0;
	env->plane1.optimize_rate.apl = 1;
	env->obj[4].paint = WHITE;
	env->obj[4].ent = &env->plane1;
	env->obj[4].ent_id = 4;
	env->cone.location.ab = 550;
	env->cone.location.ord = 500;
	env->cone.location.apl = 0;
	env->cone.coord_move.ab = -1;
	env->cone.coord_move.ord = 1;
	env->cone.coord_move.apl = 0;
	env->cone.corner = 10 * (M_PI / 180);
	env->obj[5].paint = RED;
	env->obj[5].ent = &env->cone;
	env->obj[5].ent_id = 3;
	env->light.location.ab = 2900;
	env->light.location.ord = 1900;
	env->light.location.apl = -1600;
}