/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_normals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 20:22:28 by yvasin            #+#    #+#             */
/*   Updated: 2017/05/07 20:22:29 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	cylinder_normal(t_vector *start, t_cylinder *cyl)
{
	t_vector	norm;
	t_vector	c;
	double		temp;

	norm = vector_sub(start, &cyl->pos);
	temp = vector_dot(&norm, &cyl->rot);
	c = multiply_vector_with_skalar(&cyl->rot, temp);
	norm = vector_sub(&norm, &c);
	norm = initialize_norm_process(&norm);
	return (norm);
}

t_vector	sphere_normal(t_vector *start, t_sphere *sphere)
{
	t_vector	norm;
	double		h;

	norm = vector_sub(start, &sphere->centre);
	h = vector_dot(start, &sphere->centre);
	norm = multiply_vector_with_skalar(&norm, 1 / h);
	return (norm);
}

t_vector	plane_normal(t_plane *plane, t_vector *lil)
{
	t_vector norm;

	norm = plane->normal;
	if (find_cos_vectors(&norm, lil) < 0)
		norm = multiply_vector_with_skalar(&norm, -1);
	return (norm);
}

t_vector	cone_normal(t_vector *start, t_cone *cone)
{
	t_vector	norm;
	t_vector	c;
	double		temp;

	norm = vector_sub(start, &cone->pos);
	temp = vector_dot(&norm, &cone->rot);
	c = multiply_vector_with_skalar(&cone->rot, temp);
	c = multiply_vector_with_skalar(&c, (1 + pow(tan(cone->angle), 2)));
	norm = vector_sub(&norm, &c);
	norm = initialize_norm_process(&norm);
	return (norm);
}

t_vector	normal(t_obj *obj, t_vector *start, t_vector *lil)
{
	t_vector norm;

	norm.x = 0;
	norm.y = 0;
	norm.z = 0;
	if (obj->type == 1)
		return (sphere_normal(start, (t_sphere *)(obj->obj)));
	else if (obj->type == 2)
		return (cylinder_normal(start, (t_cylinder *)(obj->obj)));
	else if (obj->type == 4)
		return (plane_normal((t_plane *)(obj->obj), lil));
	else if (obj->type == 3)
		return (cone_normal(start, (t_cone *)(obj->obj)));
	return (norm);
}
