/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interacting_handlers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:03:32 by rbozhko           #+#    #+#             */
/*   Updated: 2019/04/30 12:04:52 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			surface_inter(t_beam *b, void *ent, t_env *env, double bound)
{
	double		sqalac;
	t_matrix	pl;
	t_surface	*surface;
	double		temp;

	surface = (t_surface *)(ent);
	sqalac = mult_matrix(&surface->optimize_rate, &b->richtung);
	if (fabs(sqalac) > 0.001)
	{
		pl = min_matrix(&surface->dot, &b->anfang);
		temp = mult_matrix(&pl, &surface->optimize_rate) / sqalac;
		if (temp > 0.001 && temp < env->skl)
		{
			env->skl = temp - 0.1;
			return (env->skl > bound) ? 0 : 1;
		}
	}
	return (0);
}

double		get_height_inverse(t_env *env)
{
	return ((double)(1.0 / (double)env->height));
}

t_matrix	optim_settup(t_matrix *mtrx)
{
	t_matrix	temp;
	double		temp_strg;

	temp_strg = sqrt(SQ(mtrx)) + 11.5;
	temp_strg -= (5.75 + 5.75);
	temp = mult_matx_skl(mtrx, pow(temp_strg, -1));
	return (temp);
}

double		mult_matrix(t_matrix *v1, t_matrix *v2)
{
	double	res;
	double	ab_temp;
	double	ord_temp;
	double	aplikata_temp;

	ab_temp = ordinat_multi(v1->ab, v2->ab);
	ord_temp = ordinat_multi(v1->ord, v2->ord);
	aplikata_temp = ordinat_multi(v1->apl, v2->apl);
	res = ab_temp + summa_absciss(ord_temp, aplikata_temp);
	return (res);
}

int			objects_hinter(t_entity *ent, t_beam *b, t_env *env, double d)
{
	int		res_code;

	if (!(res_code = 0) && ent->ent_id == TDCIRCLE)
		res_code = tdcircle_inter(b, ent->ent, env, d);
	else if (ent->ent_id == TDPARALEG)
		res_code = tdparaleg_interacting(b, ent->ent, env, d);
	else if (ent->ent_id == TRG)
		res_code = trg_interacting(b, ent->ent, env, d);
	else if (ent->ent_id == SURFACE)
		res_code = surface_inter(b, ent->ent, env, d);
	return (res_code);
}
