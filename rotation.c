/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:24:41 by yvasin            #+#    #+#             */
/*   Updated: 2017/05/15 16:24:41 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	rotate_x(t_vector *dir, double angle)
{
	t_vector new_dir;

	new_dir.x = dir->x;
	new_dir.y = dir->y * cos(angle * M_PI / 180.0)
		+ dir->z * sin(angle * M_PI / 180.0);
	new_dir.z = dir->z * cos(angle * M_PI / 180.0)
		- dir->y * sin(angle * M_PI / 180.0);
	return (new_dir);
}

t_vector	rotate_y(t_vector *dir, double angle)
{
	t_vector new_dir;

	new_dir.x = dir->x * cos(angle * M_PI / 180.0)
		- dir->z * sin(angle * M_PI / 180.0);
	new_dir.y = dir->y;
	new_dir.z = dir->z * cos(angle * M_PI / 180.0)
		+ dir->x * sin(angle * M_PI / 180.0);
	return (new_dir);
}

t_vector	rotate_z(t_vector *dir, double angle)
{
	t_vector new_dir;

	new_dir.x = dir->x * cos(angle * M_PI / 180.0)
		+ dir->y * sin(angle * M_PI / 180.0);
	new_dir.y = dir->y * cos(angle * M_PI / 180.0)
		- dir->x * sin(angle * M_PI / 180.0);
	new_dir.z = dir->z;
	return (new_dir);
}

t_vector	rotate_init_ray(t_vector *v, t_vedro *vedro)
{
	t_vector v1;

	v->x = (2 * ((vedro->x + 0.5) * INV_WIDTH) - 1) * ANGLE * ASP_RATIO;
	v->y = (1 - 2 * ((vedro->y + 0.5) * INV_HEIGHT)) * ANGLE;
	v->z = 1;
	v1 = rotate_x(v, vedro->alpha);
	v1 = rotate_y(&v1, vedro->beta);
	v1 = rotate_z(&v1, vedro->gamma);
	v1 = normalize(&v1);
	return (v1);
}
