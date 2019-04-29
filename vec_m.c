/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_m.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 19:11:01 by yvasin            #+#    #+#             */
/*   Updated: 2017/04/08 19:11:02 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			tdcircle_interacting(t_ray *ray, void *obj, t_vedro *vedro, double d)
{
	t_vector	dist;
	t_vector	ab;
	t_vector	tt;
	t_sphere	*sphere;
	int			ret;

	ret = 0;
	sphere = (t_sphere *)(obj);
	dist = min_matrix(&sphere->centre, &ray->start);
	ab.x = mult_matrix(&ray->dir, &dist);
	ab.y = ab.x * ab.x - mult_matrix(&dist, &dist) + sphere->radius2;
	if (ab.y < 0.0)
		return (0);
	tt.x = ab.x - sqrt(ab.y);
	tt.y = ab.x + sqrt(ab.y);
	(tt.x > 0.001) && (tt.x < vedro->t) ? ret = 1 : 0;
	(tt.x > 0.001) && (tt.x < vedro->t) ? vedro->t = tt.x : 0;
	(tt.y > 0.001) && (tt.y < vedro->t) ? ret = 1 : 0;
	(tt.y > 0.001) && (tt.y < vedro->t) ? vedro->t = tt.y : 0;
	vedro->t -= 0.01;
	if (vedro->t > d)
		return (0);
	return (ret);
}

int			tdparaleg_interacting(t_ray *ray, t_cylinder *cyl,
				t_vedro *vedro, double d)
{
	t_vector	dist;
	t_vector	abc;
	t_vector	t;
	double		discr;
	int			ret;

	ret = 0;
	dist = min_matrix(&cyl->pos, &ray->start);
	cyl->rot = optim_settup(&cyl->rot);
	abc = tdrect_math(ray, cyl, &dist);
	discr = abc.y * abc.y - 4 * abc.x * abc.z;
	if (discr < 0)
		return (ret);
	t.x = (abc.y - sqrt(discr)) / (2 * abc.x);
	t.y = (abc.y + sqrt(discr)) / (2 * abc.x);
	(t.x > 0.001) && (t.x < vedro->t) ? ret = 1 : 0;
	(t.x > 0.001) && (t.x < vedro->t) ? vedro->t = t.x : 0;
	(t.y > 0.001) && (t.y < vedro->t) ? ret = 1 : 0;
	(t.y > 0.001) && (t.y < vedro->t) ? vedro->t = t.y : 0;
	vedro->t -= 0.01;
	if (vedro->t > d)
		return (0);
	return (ret);
}

int			trg_interacting(t_ray *ray, t_cone *cone, t_vedro *vedro, double d)
{
	t_vector	dist;
	t_vector	abc;
	t_vector	t;
	double		discr;
	int			ret;

	ret = 0;
	dist = min_matrix(&cone->pos, &ray->start);
	cone->rot = optim_settup(&cone->rot);
	abc = trg_math(ray, cone, &dist);
	discr = abc.y * abc.y - 4 * abc.x * abc.z;
	if (discr < 0)
		return (ret);
	t.x = (abc.y - sqrt(discr)) / (2 * abc.x);
	t.y = (abc.y + sqrt(discr)) / (2 * abc.x);
	(t.x > 0.001) && (t.x < vedro->t) ? ret = 1 : 0;
	(t.x > 0.001) && (t.x < vedro->t) ? vedro->t = t.x : 0;
	(t.y > 0.001) && (t.y < vedro->t) ? ret = 1 : 0;
	(t.y > 0.001) && (t.y < vedro->t) ? vedro->t = t.y : 0;
	vedro->t -= 0.01;
	if (vedro->t > d)
		return (0);
	return (ret);
}

int			surface_interacting(t_ray *ray, void *obj, t_vedro *vedro, double d)
{
	double		denom;
	t_vector	pl;
	t_plane		*plane;
	double		t;

	plane = (t_plane *)(obj);
	denom = mult_matrix(&plane->normal, &ray->dir);
	if (fabs(denom) > 0.001)
	{
		pl = min_matrix(&plane->point, &ray->start);
		t = mult_matrix(&pl, &plane->normal) / denom;
		if (t > 0.001 && t < vedro->t)
		{
			vedro->t = t - 0.1;
			return (vedro->t > d) ? 0 : 1;
		}
		else
			return (0);
	}
	return (0);
}

int			objects_hinteracting(t_obj *obj, t_ray *ray, t_vedro *vedro, double d)
{
	int		res_code;

	res_code = 0;
	if (obj->type == SPHERE)
		res_code = tdcircle_interacting(ray, obj->obj, vedro, d);
	else if (obj->type == CYLINDER)
		res_code = tdparaleg_interacting(ray, obj->obj, vedro, d);
	else if (obj->type == CONUS)
		res_code = trg_interacting(ray, obj->obj, vedro, d);
	else if (obj->type == PLANE)
		res_code = surface_interacting(ray, obj->obj, vedro, d);
	return (res_code);
}
