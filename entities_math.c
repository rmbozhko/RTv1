/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 20:04:12 by yvasin            #+#    #+#             */
/*   Updated: 2017/05/07 20:04:13 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_matrix	trg_math(t_beam *ray, t_trg *cone, t_matrix *dist)
{
	t_matrix abc;

	abc.x = mult_matrix(&ray->dir, &ray->dir)
	- (1 + pow(tan(cone->angle), 2))
	* pow(mult_matrix(&ray->dir, &cone->rot), 2);
	abc.y = 2 * (mult_matrix(&ray->dir, dist)
	- (1 + pow(tan(cone->angle), 2)) * (mult_matrix(&ray->dir, &cone->rot)
	* mult_matrix(dist, &cone->rot)));
	abc.z = mult_matrix(dist, dist)
	- (1 + pow(tan(cone->angle), 2)) * pow(mult_matrix(dist, &cone->rot), 2);
	return (abc);
}

t_matrix	tdrect_math(t_beam *ray, t_tdparaleg *cyl, t_matrix *dist)
{
	t_matrix abc;

	abc.x = mult_matrix(&ray->dir, &ray->dir)
		- pow(mult_matrix(&ray->dir, &cyl->rot), 2);
	abc.y = 2 * (mult_matrix(&ray->dir, dist)
	- (mult_matrix(&ray->dir, &cyl->rot) * mult_matrix(dist, &cyl->rot)));
	abc.z = mult_matrix(dist, dist) - pow(mult_matrix(dist, &cyl->rot), 2)
		- cyl->radius2;
	return (abc);
}

double		calc_angle_matrix(t_matrix *v1, t_matrix *v2)
{
	double cos;

	cos = (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z) /
		(sqrt(v1->x * v1->x + v1->y * v1->y + v1->z * v1->z)
			* sqrt(v2->x * v2->x + v2->y * v2->y + v2->z * v2->z));
	return (cos);
}