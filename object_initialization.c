#include "rtv1.h"

void	instantiating_fentity(t_env *env)
{
	env->cylinder.pos.x = 1200;
	env->cylinder.pos.y = 500;
	env->cylinder.pos.z = -400;
	env->cylinder.rot.x = 0;
	env->cylinder.rot.y = 1;
	env->cylinder.rot.z = 1;
	env->cylinder.radius = 100;
	env->cylinder.radius2 = env->cylinder.radius * env->cylinder.radius;
	env->obj[0].color = BLUE;
	env->obj[0].obj = &env->cylinder;
	env->obj[0].type = 2;
	env->sphere.centre.x = 550;
	env->sphere.centre.y = 500;
	env->sphere.centre.z = 0;
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
	env->cylinder2.pos.x = 500;
	env->cylinder2.pos.y = 500;
	env->cylinder2.pos.z = 0;
	env->cylinder2.rot.x = 1;
	env->cylinder2.rot.y = 0;
	env->cylinder2.rot.z = 1;
	env->cylinder2.radius = 50;
	env->cylinder2.radius2 = env->cylinder2.radius
		* env->cylinder2.radius;
	env->obj[2].color = CYAN;
	env->obj[2].obj = &env->cylinder2;
	env->obj[2].type = 2;
	env->plane.point.x = 400;
	env->plane.point.y = 100;
	env->plane.point.z = 2500;
	env->plane.normal.x = 0;
	env->plane.normal.y = 1;
	env->plane.normal.z = 0;
	env->obj[3].color = GREEN;
	env->obj[3].obj = &env->plane;
	env->obj[3].type = 4;
}

void	instantiating_tentity(t_env *env)
{
	env->plane1.point.x = 400;
	env->plane1.point.y = 100;
	env->plane1.point.z = 2500;
	env->plane1.normal.x = 0;
	env->plane1.normal.y = 0;
	env->plane1.normal.z = 1;
	env->obj[4].color = WHITE;
	env->obj[4].obj = &env->plane1;
	env->obj[4].type = 4;
	env->cone.pos.x = 550;
	env->cone.pos.y = 500;
	env->cone.pos.z = 0;
	env->cone.rot.x = -1;
	env->cone.rot.y = 1;
	env->cone.rot.z = 0;
	env->cone.angle = 10 * (M_PI / 180);
	env->obj[5].color = RED;
	env->obj[5].obj = &env->cone;
	env->obj[5].type = 3;
	env->light.pos.x = 2900;
	env->light.pos.y = 1900;
	env->light.pos.z = -1600;
}