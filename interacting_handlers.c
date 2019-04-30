#include "rtv1.h"

void		determine_ret_value()
{
	
}

int			tdcircle_interacting(t_beam *ray, void *obj, t_env *env, double d)
{
	t_matrix	dist;
	t_matrix	ab;
	t_matrix	tt;
	t_tdcircle	*sphere;
	int			ret;

	ret = 0;
	sphere = (t_tdcircle *)(obj);
	dist = min_matrix(&sphere->location, &ray->anfang);
	ab.ab = mult_matrix(&ray->richtung, &dist);
	ab.ord = ab.ab * ab.ab - mult_matrix(&dist, &dist) + sphere->div_diameter;
	if (ab.ord < 0.0)
		return (0);
	tt.ab = ab.ab - sqrt(ab.ord);
	tt.ord = ab.ab + sqrt(ab.ord);
	(tt.ab > 0.001) && (tt.ab < env->skl) ? ret = 1 : 0;
	(tt.ab > 0.001) && (tt.ab < env->skl) ? env->skl = tt.ab : 0;
	(tt.ord > 0.001) && (tt.ord < env->skl) ? ret = 1 : 0;
	(tt.ord > 0.001) && (tt.ord < env->skl) ? env->skl = tt.ord : 0;
	env->skl -= 0.01;
	return ((env->skl > d) ? 0 : ret);
}

int			tdparaleg_interacting(t_beam *ray, t_tdparaleg *cyl,
				t_env *env, double d)
{
	t_matrix	dist;
	t_matrix	abc;
	t_matrix	t;
	double		discr;
	int			ret;

	ret = 0;
	dist = min_matrix(&cyl->location, &ray->anfang);
	cyl->coord_move = optim_settup(&cyl->coord_move);
	abc = tdrect_math(ray, cyl, &dist);
	discr = abc.ord * abc.ord - 4 * abc.ab * abc.apl;
	if (discr < 0)
		return (ret);
	t.ab = (abc.ord - sqrt(discr)) / (2 * abc.ab);
	t.ord = (abc.ord + sqrt(discr)) / (2 * abc.ab);
	(t.ab > 0.001) && (t.ab < env->skl) ? ret = 1 : 0;
	(t.ab > 0.001) && (t.ab < env->skl) ? env->skl = t.ab : 0;
	(t.ord > 0.001) && (t.ord < env->skl) ? ret = 1 : 0;
	(t.ord > 0.001) && (t.ord < env->skl) ? env->skl = t.ord : 0;
	env->skl -= 0.01;
	return ((env->skl > d) ? 0 : ret);
}

int			trg_interacting(t_beam *ray, t_trg *cone, t_env *env, double d)
{
	t_matrix	dist;
	t_matrix	abc;
	t_matrix	t;
	double		discr;
	int			ret;

	ret = 0;
	dist = min_matrix(&cone->location, &ray->anfang);
	cone->coord_move = optim_settup(&cone->coord_move);
	abc = trg_math(ray, cone, &dist);
	discr = abc.ord * abc.ord - 4 * abc.ab * abc.apl;
	if (discr < 0)
		return (ret);
	t.ab = (abc.ord - sqrt(discr)) / (2 * abc.ab);
	t.ord = (abc.ord + sqrt(discr)) / (2 * abc.ab);
	(t.ab > 0.001) && (t.ab < env->skl) ? ret = 1 : 0;
	(t.ab > 0.001) && (t.ab < env->skl) ? env->skl = t.ab : 0;
	(t.ord > 0.001) && (t.ord < env->skl) ? ret = 1 : 0;
	(t.ord > 0.001) && (t.ord < env->skl) ? env->skl = t.ord : 0;
	env->skl -= 0.01;
	return ((env->skl > d) ? 0 : ret);
}

int			surface_interacting(t_beam *ray, void *entity, t_env *env, double d)
{
	double		denom;
	t_matrix	pl;
	t_surface	*plane;
	double		t;

	plane = (t_surface *)(entity);
	denom = mult_matrix(&plane->optimize_rate, &ray->richtung);
	if (fabs(denom) > 0.001)
	{
		pl = min_matrix(&plane->dot, &ray->anfang);
		t = mult_matrix(&pl, &plane->optimize_rate) / denom;
		if (t > 0.001 && t < env->skl)
		{
			env->skl = t - 0.1;
			return (env->skl > d) ? 0 : 1;
		}
	}
	return (0);
}

int			objects_hinteracting(t_entity *entity, t_beam *ray, t_env *env, double d)
{
	int		res_code;

	if (!(res_code = 0) && entity->ent_id == SPHERE)
		res_code = tdcircle_interacting(ray, entity->ent, env, d);
	else if (entity->ent_id == CYLINDER)
		res_code = tdparaleg_interacting(ray, entity->ent, env, d);
	else if (entity->ent_id == CONUS)
		res_code = trg_interacting(ray, entity->ent, env, d);
	else if (entity->ent_id == PLANE)
		res_code = surface_interacting(ray, entity->ent, env, d);
	return (res_code);
}
