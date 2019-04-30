/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:47:36 by rbozhko           #+#    #+#             */
/*   Updated: 2019/04/30 11:50:19 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_matrix			optimization_for_tdparaleg(t_matrix *mtrx, t_tdparaleg *td)
{
	t_matrix	temp;
	t_matrix	lol;

	temp = min_matrix(mtrx, &td->location);
	lol = mult_matx_skl(&td->coord_move,
		mult_matrix(&temp, &td->coord_move));
	temp = min_matrix(&temp, &lol);
	temp = optim_settup(&temp);
	return (temp);
}

unsigned char		*ft_get_proper(t_env *env)
{
	unsigned char		*temp;
	size_t				i;
	size_t				j;
	unsigned long		len;

	i = 0;
	j = 0;
	len = env->height * env->sline;
	temp = (unsigned char*)malloc(sizeof(char)
			* env->height * env->width * 3 + 1);
	ft_bzero(temp, sizeof(char) * env->height * env->width * 3 + 1);
	while (i < len && j < len)
	{
		if (((j + 1) % 4) == 0)
			j++;
		temp[i++] = env->data[j + 2];
		temp[i++] = env->data[j + 1];
		temp[i++] = env->data[j];
		j += 3;
	}
	return (temp);
}

t_matrix			xyz_rotation(t_env *env, t_matrix *richtung)
{
	richtung->apl = 1;
	richtung->ord = (1 - 2 * ((Y + 0.5) * get_height_inverse(env))) * CORNER;
	env->skl = MAGIC_NUM;
	richtung->ab = (2 * ((X + 0.5) * get_width_inverse(env)) - 1)
		* CORNER * MIDD_RAT;
	return (optim_settup(richtung));
}

t_matrix			optimization_for_trg(t_matrix *mtrx, t_trg *trg)
{
	t_matrix	norm;
	t_matrix	lol;

	norm = min_matrix(mtrx, &trg->location);
	lol = mult_matx_skl(&trg->coord_move, mult_matrix(&norm, &trg->coord_move));
	lol = mult_matx_skl(&lol, (1 + pow(tan(trg->corner), 2)));
	norm = min_matrix(&norm, &lol);
	norm = optim_settup(&norm);
	return (norm);
}

t_matrix			optimization(t_entity *ent, t_matrix *mtrx, t_matrix *temp)
{
	t_matrix optimized_temp;

	ft_build_mtrx((double)0.0, (double)0.0, (double)0.0, &optimized_temp);
	if (ent->ent_id == TDCIRCLE)
		return (optimization_for_tdcircle(mtrx, (t_tdcircle *)(ent->ent)));
	else if (ent->ent_id == TDPARALEG)
		return (optimization_for_tdparaleg(mtrx, (t_tdparaleg *)(ent->ent)));
	else if (ent->ent_id == TRG)
		return (optimization_for_trg(mtrx, (t_trg *)(ent->ent)));
	else if (ent->ent_id == SURFACE)
		return (optimization_for_surface(temp, (t_surface *)(ent->ent)));
	return (optimized_temp);
}
