/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:38:25 by rbozhko           #+#    #+#             */
/*   Updated: 2019/04/30 11:39:07 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		ordinat_substraction(const double y1, const double y2)
{
	return (y1 - y2);
}

t_matrix	aplikata_rotation(t_matrix *dir)
{
	t_matrix new_dir;

	new_dir.ab = dir->ab;
	new_dir.ord = dir->ord;
	new_dir.apl = dir->apl;
	return (new_dir);
}

t_matrix	min_matrix(t_matrix *v1, t_matrix *v2)
{
	t_matrix	res;
	double		ab_temp;

	ab_temp = v1->ab - v2->ab;
	res.ab = ab_temp;
	res.ord = ordinat_substraction(v1->ord, v2->ord);
	res.apl = aplikata_substraction(v1->apl, v2->apl);
	return (res);
}

double		ordinat_multi(const double y1, const double y2)
{
	return (y1 * y2);
}

t_matrix	mult_matx_skl(t_matrix *v, double scale)
{
	t_matrix	res;
	double		ab_temp;

	ab_temp = v->ab * scale;
	res.ab = ab_temp;
	res.ord = ordinat_multi(v->ord, scale);
	res.apl = aplikata_multi(v->apl, scale);
	return (res);
}
