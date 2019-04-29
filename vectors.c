/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 20:48:55 by yvasin            #+#    #+#             */
/*   Updated: 2017/04/08 20:48:56 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	vector_sub(t_vector *v1, t_vector *v2)
{
	t_vector res;

	res.x = v1->x - v2->x;
	res.y = v1->y - v2->y;
	res.z = v1->z - v2->z;
	return (res);
}

t_vector	multiply_vector_with_skalar(t_vector *v, double scale)
{
	t_vector res;

	res.x = v->x * scale;
	res.y = v->y * scale;
	res.z = v->z * scale;
	return (res);
}

t_vector	vector_add(t_vector *v1, t_vector *v2)
{
	t_vector res;

	res.x = v1->x + v2->x;
	res.y = v1->y + v2->y;
	res.z = v1->z + v2->z;
	return (res);
}

t_vector	initialize_norm_process(t_vector *vector)
{
	t_vector	norm;
	double		length;

	length = sqrt(vector_dot(vector, vector));
	norm = multiply_vector_with_skalar(vector, 1 / length);
	return (norm);
}

double		vector_dot(t_vector *v1, t_vector *v2)
{
	double res;

	res = (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
	return (res);
}
