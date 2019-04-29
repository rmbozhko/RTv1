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

t_matrix	optimization_for_tdparaleg(t_matrix *start, t_tdparaleg *cyl)
{
	t_matrix	norm;
	t_matrix	c;
	double		temp;

	norm = min_matrix(start, &cyl->pos);
	temp = mult_matrix(&norm, &cyl->rot);
	c = mult_matx_skl(&cyl->rot, temp);
	norm = min_matrix(&norm, &c);
	norm = optim_settup(&norm);
	return (norm);
}

t_matrix	optimization_for_tdcircle(t_matrix *start, t_tdcircle *sphere)
{
	t_matrix	norm;
	double		h;

	norm = min_matrix(start, &sphere->centre);
	h = mult_matrix(start, &sphere->centre);
	norm = mult_matx_skl(&norm, 1 / h);
	return (norm);
}

t_matrix	optimization_for_surface(t_surface *plane, t_matrix *lil)
{
	t_matrix norm;

	norm = plane->normal;
	if (calc_angle_matrix(&norm, lil) < 0)
		norm = mult_matx_skl(&norm, -1);
	return (norm);
}

t_matrix	optimization_for_trg(t_matrix *start, t_trg *cone)
{
	t_matrix	norm;
	t_matrix	c;
	double		temp;

	norm = min_matrix(start, &cone->pos);
	temp = mult_matrix(&norm, &cone->rot);
	c = mult_matx_skl(&cone->rot, temp);
	c = mult_matx_skl(&c, (1 + pow(tan(cone->angle), 2)));
	norm = min_matrix(&norm, &c);
	norm = optim_settup(&norm);
	return (norm);
}

t_matrix	optimization(t_entity *obj, t_matrix *start, t_matrix *lil)
{
	t_matrix norm;

	norm.ab = 0;
	norm.ord = 0;
	norm.apl = 0;
	if (obj->type == SPHERE)
		return (optimization_for_tdcircle(start, (t_tdcircle *)(obj->obj)));
	else if (obj->type == CYLINDER)
		return (optimization_for_tdparaleg(start, (t_tdparaleg *)(obj->obj)));
	else if (obj->type == CONUS)
		return (optimization_for_trg(start, (t_trg *)(obj->obj)));
	else if (obj->type == PLANE)
		return (optimization_for_surface((t_surface *)(obj->obj), lil));
	return (norm);
}
