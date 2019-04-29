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

t_vector	optimization_for_tdparaleg(t_vector *start, t_cylinder *cyl)
{
	t_vector	norm;
	t_vector	c;
	double		temp;

	norm = min_matrix(start, &cyl->pos);
	temp = mult_matrix(&norm, &cyl->rot);
	c = mult_matx_skl(&cyl->rot, temp);
	norm = min_matrix(&norm, &c);
	norm = optim_settup(&norm);
	return (norm);
}

t_vector	optimization_for_tdcircle(t_vector *start, t_sphere *sphere)
{
	t_vector	norm;
	double		h;

	norm = min_matrix(start, &sphere->centre);
	h = mult_matrix(start, &sphere->centre);
	norm = mult_matx_skl(&norm, 1 / h);
	return (norm);
}

t_vector	optimization_for_surface(t_plane *plane, t_vector *lil)
{
	t_vector norm;

	norm = plane->normal;
	if (calc_angle_matrix(&norm, lil) < 0)
		norm = mult_matx_skl(&norm, -1);
	return (norm);
}

t_vector	optimization_for_trg(t_vector *start, t_cone *cone)
{
	t_vector	norm;
	t_vector	c;
	double		temp;

	norm = min_matrix(start, &cone->pos);
	temp = mult_matrix(&norm, &cone->rot);
	c = mult_matx_skl(&cone->rot, temp);
	c = mult_matx_skl(&c, (1 + pow(tan(cone->angle), 2)));
	norm = min_matrix(&norm, &c);
	norm = optim_settup(&norm);
	return (norm);
}

t_vector	optimization(t_obj *obj, t_vector *start, t_vector *lil)
{
	t_vector norm;

	norm.x = 0;
	norm.y = 0;
	norm.z = 0;
	if (obj->type == SPHERE)
		return (optimization_for_tdcircle(start, (t_sphere *)(obj->obj)));
	else if (obj->type == CYLINDER)
		return (optimization_for_tdparaleg(start, (t_cylinder *)(obj->obj)));
	else if (obj->type == CONUS)
		return (optimization_for_trg(start, (t_cone *)(obj->obj)));
	else if (obj->type == PLANE)
		return (optimization_for_surface((t_plane *)(obj->obj), lil));
	return (norm);
}
