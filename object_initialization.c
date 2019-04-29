#include "rtv1.h"

void	instantiating_fentity(t_env *env)
{
	env->cylinder.pos.ab = 1200;
	env->cylinder.pos.ord = 500;
	env->cylinder.pos.apl = -400;
	env->cylinder.rot.ab = 0;
	env->cylinder.rot.ord = 1;
	env->cylinder.rot.apl = 1;
	env->cylinder.radius = 100;
	env->cylinder.radius2 = env->cylinder.radius * env->cylinder.radius;
	env->obj[0].color = BLUE;
	env->obj[0].obj = &env->cylinder;
	env->obj[0].type = 2;
	env->sphere.centre.ab = 550;
	env->sphere.centre.ord = 500;
	env->sphere.centre.apl = 0;
	env->sphere.radius = 250;
	env->sphere.radius2 = env->sphere.radius * env->sphere.radius;
	env->obj[1].color = MAGENTA;
	env->obj[1].obj = &env->sphere;
	env->obj[1].type = 1;
	instantiating_sentity(env);
	instantiating_tentity(env);
}

void	instantiating_sentity(t_env *env)
{
	env->cylinder2.pos.ab = 500;
	env->cylinder2.pos.ord = 500;
	env->cylinder2.pos.apl = 0;
	env->cylinder2.rot.ab = 1;
	env->cylinder2.rot.ord = 0;
	env->cylinder2.rot.apl = 1;
	env->cylinder2.radius = 50;
	env->cylinder2.radius2 = env->cylinder2.radius
		* env->cylinder2.radius;
	env->obj[2].color = CYAN;
	env->obj[2].obj = &env->cylinder2;
	env->obj[2].type = 2;
	env->plane.point.ab = 400;
	env->plane.point.ord = 100;
	env->plane.point.apl = 2500;
	env->plane.normal.ab = 0;
	env->plane.normal.ord = 1;
	env->plane.normal.apl = 0;
	env->obj[3].color = GREEN;
	env->obj[3].obj = &env->plane;
	env->obj[3].type = 4;
}

void	instantiating_tentity(t_env *env)
{
	env->plane1.point.ab = 400;
	env->plane1.point.ord = 100;
	env->plane1.point.apl = 2500;
	env->plane1.normal.ab = 0;
	env->plane1.normal.ord = 0;
	env->plane1.normal.apl = 1;
	env->obj[4].color = WHITE;
	env->obj[4].obj = &env->plane1;
	env->obj[4].type = 4;
	env->cone.pos.ab = 550;
	env->cone.pos.ord = 500;
	env->cone.pos.apl = 0;
	env->cone.rot.ab = -1;
	env->cone.rot.ord = 1;
	env->cone.rot.apl = 0;
	env->cone.angle = 10 * (M_PI / 180);
	env->obj[5].color = RED;
	env->obj[5].obj = &env->cone;
	env->obj[5].type = 3;
	env->light.pos.ab = 2900;
	env->light.pos.ord = 1900;
	env->light.pos.apl = -1600;
}