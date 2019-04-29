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

t_matrix	min_matrix(t_matrix *v1, t_matrix *v2)
{
	t_matrix res;

	res.x = v1->x - v2->x;
	res.y = v1->y - v2->y;
	res.z = v1->z - v2->z;
	return (res);
}

t_matrix	mult_matx_skl(t_matrix *v, double scale)
{
	t_matrix res;

	res.x = v->x * scale;
	res.y = v->y * scale;
	res.z = v->z * scale;
	return (res);
}

t_matrix	summ_matrix(t_matrix *v1, t_matrix *v2)
{
	t_matrix res;

	res.x = v1->x + v2->x;
	res.y = v1->y + v2->y;
	res.z = v1->z + v2->z;
	return (res);
}

t_matrix	optim_settup(t_matrix *vector)
{
	t_matrix	norm;
	double		length;

	length = sqrt(mult_matrix(vector, vector));
	norm = mult_matx_skl(vector, 1 / length);
	return (norm);
}

double		mult_matrix(t_matrix *v1, t_matrix *v2)
{
	double res;

	res = (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
	return (res);
}
