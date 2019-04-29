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

t_vector	cone_abc(t_ray *ray, t_cone *cone, t_vector *dist)
{
	t_vector abc;

	abc.x = vector_dot(&ray->dir, &ray->dir)
	- (1 + pow(tan(cone->angle), 2))
	* pow(vector_dot(&ray->dir, &cone->rot), 2);
	abc.y = 2 * (vector_dot(&ray->dir, dist)
	- (1 + pow(tan(cone->angle), 2)) * (vector_dot(&ray->dir, &cone->rot)
	* vector_dot(dist, &cone->rot)));
	abc.z = vector_dot(dist, dist)
	- (1 + pow(tan(cone->angle), 2)) * pow(vector_dot(dist, &cone->rot), 2);
	return (abc);
}

t_vector	cyl_abc(t_ray *ray, t_cylinder *cyl, t_vector *dist)
{
	t_vector abc;

	abc.x = vector_dot(&ray->dir, &ray->dir)
		- pow(vector_dot(&ray->dir, &cyl->rot), 2);
	abc.y = 2 * (vector_dot(&ray->dir, dist)
	- (vector_dot(&ray->dir, &cyl->rot) * vector_dot(dist, &cyl->rot)));
	abc.z = vector_dot(dist, dist) - pow(vector_dot(dist, &cyl->rot), 2)
		- cyl->radius2;
	return (abc);
}
