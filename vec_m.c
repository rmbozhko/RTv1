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

int			intersect_sphere(t_ray *ray, void *obj, t_vedro *vedro, double d)
{
	t_vector	dist;
	t_vector	ab;
	t_vector	tt;
	t_sphere	*sphere;
	int			ret;

	ret = 0;
	sphere = (t_sphere *)(obj);
	dist = vector_sub(&sphere->centre, &ray->start);
	ab.x = vector_dot(&ray->dir, &dist);
	ab.y = ab.x * ab.x - vector_dot(&dist, &dist) + sphere->radius2;
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

int			intersect_cylinder(t_ray *ray, t_cylinder *cyl,
				t_vedro *vedro, double d)
{
	t_vector	dist;
	t_vector	abc;
	t_vector	t;
	double		discr;
	int			ret;

	ret = 0;
	dist = vector_sub(&cyl->pos, &ray->start);
	cyl->rot = initialize_norm_process(&cyl->rot);
	abc = cyl_abc(ray, cyl, &dist);
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

int			intersect_cone(t_ray *ray, t_cone *cone, t_vedro *vedro, double d)
{
	t_vector	dist;
	t_vector	abc;
	t_vector	t;
	double		discr;
	int			ret;

	ret = 0;
	dist = vector_sub(&cone->pos, &ray->start);
	cone->rot = initialize_norm_process(&cone->rot);
	abc = cone_abc(ray, cone, &dist);
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

int			intersect_plane(t_ray *ray, void *obj, t_vedro *vedro, double d)
{
	double		denom;
	t_vector	pl;
	t_plane		*plane;
	double		t;

	plane = (t_plane *)(obj);
	denom = vector_dot(&plane->normal, &ray->dir);
	if (fabs(denom) > 0.001)
	{
		pl = vector_sub(&plane->point, &ray->start);
		t = vector_dot(&pl, &plane->normal) / denom;
		if (t > 0.001 && t < vedro->t)
		{
			vedro->t = t - 0.1;
			if (vedro->t > d)
				return (0);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

int			intersection(t_obj *obj, t_ray *ray, t_vedro *vedro, double d)
{
	int		ret;

	ret = 0;
	if (obj->type == 1)
		ret = intersect_sphere(ray, obj->obj, vedro, d);
	else if (obj->type == 2)
		ret = intersect_cylinder(ray, obj->obj, vedro, d);
	else if (obj->type == 4)
		ret = intersect_plane(ray, obj->obj, vedro, d);
	else if (obj->type == 3)
		ret = intersect_cone(ray, obj->obj, vedro, d);
	return (ret);
}
