/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xyz_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:34:39 by rbozhko           #+#    #+#             */
/*   Updated: 2019/04/30 11:38:02 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_matrix	abscissa_rotation(t_matrix *dir)
{
	t_matrix new_dir;

	new_dir.ab = dir->ab;
	new_dir.ord = dir->ord;
	new_dir.apl = dir->apl;
	return (new_dir);
}

int			determine_interacting(t_env *env, double glow_dist, t_beam *beam)
{
	int		counter;
	int		id;

	counter = -1;
	id = -1;
	while (++id < MAX_OBJ_NUM)
	{
		counter = (objects_hinter(&env->entities_strg[id],
			beam, env, glow_dist) == 1) ? id : counter;
	}
	return (counter);
}

int			trg_interacting(t_beam *beam, t_trg *trg, t_env *env, double bound)
{
	t_matrix	rec;
	t_matrix	temp;
	t_matrix	miss;
	double		discr;
	int			ret;

	ret = 0;
	rec = min_matrix(&trg->location, &beam->anfang);
	trg->coord_move = optim_settup(&trg->coord_move);
	temp = trg_math(trg, beam, &rec);
	discr = temp.ord * temp.ord - 4 * temp.ab * temp.apl;
	if (discr < 0)
		return (ret);
	miss.ab = (temp.ord - sqrt(discr)) / (2 * temp.ab);
	miss.ord = (temp.ord + sqrt(discr)) / (2 * temp.ab);
	(miss.ab > 0.001) && (miss.ab < env->skl) ? ret = 1 : 0;
	(miss.ab > 0.001) && (miss.ab < env->skl) ? env->skl = miss.ab : 0;
	(miss.ord > 0.001) && (miss.ord < env->skl) ? ret = 1 : 0;
	(miss.ord > 0.001) && (miss.ord < env->skl) ? env->skl = miss.ord : 0;
	env->skl -= 0.01;
	return ((env->skl > bound) ? 0 : ret);
}

void		process_beam(t_env *env, int entity)
{
	t_beam		beam;
	bool		flag;

	flag = true;
	while (Y < (int)env->height)
	{
		while (X < (int)env->width)
		{
			beam.richtung = xyz_rotation(env, &beam.richtung);
			if (flag)
			{
				ft_build_mtrx(1600 / 4 * 2, 15 % 10 * 100,
						3 * -7 * cos(0) * 100, &beam.anfang);
				flag = false;
			}
			((entity = determine_interacting(env, ITS_MAGIC, &beam)) != -1) ?
			window_setting(sqrt(SQ(&env->s_of_l)), entity, &beam, env) : 0;
			X++;
		}
		X = 0;
		Y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
