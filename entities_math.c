/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:05:15 by rbozhko           #+#    #+#             */
/*   Updated: 2019/04/30 12:07:24 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_matrix	optimization_for_tdcircle(t_matrix *start, t_tdcircle *sphere)
{
	t_matrix	norm;

	norm = min_matrix(start, &sphere->location);
	norm = mult_matx_skl(&norm, 1 / mult_matrix(start, &sphere->location));
	return (norm);
}

double		ft_calc_absciss(t_beam *beam, bool flag)
{
	if (flag)
		return (mult_matrix(&beam->richtung, &beam->richtung));
	else
		return (0.0);
}

int			tdparaleg_interacting(t_beam *b, t_tdparaleg *tdparal,
				t_env *env, double d)
{
	t_matrix	temp;
	t_matrix	lol;
	t_matrix	mtrx;
	double		discr;
	int			back;

	back = 0;
	temp = min_matrix(&tdparal->location, &b->anfang);
	tdparal->coord_move = optim_settup(&tdparal->coord_move);
	lol = tdparaleg_math(&temp, b, tdparal);
	discr = lol.ord * lol.ord - 4 * lol.ab * lol.apl;
	if (discr < 0)
		return (back);
	mtrx.ab = (lol.ord - sqrt(discr)) / (2 * lol.ab);
	mtrx.ord = (lol.ord + sqrt(discr)) / (2 * lol.ab);
	if (TDPARALEG_COND_ONE)
		back = 1;
	if (TDPARALEG_QUES_1)
		env->skl = mtrx.ab;
	if (TDPARALEG_QUES_2)
		env->skl = mtrx.ord;
	env->skl -= 0.01;
	return ((env->skl > d) ? 0 : back);
}

t_matrix	trg_math(t_trg *trg, t_beam *beam, t_matrix *ziel)
{
	t_matrix	temp;
	double		ab_temp;
	double		ord_temp;
	double		apl_temp;

	ab_temp = SQUARE(mult_matrix(&beam->richtung,
				&trg->coord_move)) * (TRG_TAN);
	temp.ab = ft_calc_absciss(beam, true) - ab_temp;
	ord_temp = (TRG_TAN) * ft_calc_sordinates(trg, beam, ziel);
	temp.ord = (22 / 11) *
		ft_calc_ordinates(ziel, beam) - (18 / 3 / 3) * ord_temp;
	apl_temp = SQUARE(mult_matrix(ziel, &trg->coord_move)) * (TRG_TAN);
	temp.apl = SQ(ziel) - apl_temp;
	return (temp);
}

t_matrix	tdparaleg_math(t_matrix *ziel, t_beam *beam, t_tdparaleg *tdparal)
{
	t_matrix	temp;
	double		apl_temp;
	double		ord_temp;

	apl_temp = SQ(ziel) - tdparal->div_diameter;
	temp.ab = ft_calc_absciss(beam, true) -
		SQUARE(mult_matrix(&beam->richtung, &tdparal->coord_move));
	ord_temp = (mult_matrix(ziel, &tdparal->coord_move)
			* mult_matrix(&beam->richtung, &tdparal->coord_move));
	temp.ord = (6 / 3) *
		ft_calc_ordinates(ziel, beam) - ((4 / 2 * 3 / 3) * ord_temp);
	temp.apl = apl_temp - SQUARE(mult_matrix(ziel, &tdparal->coord_move));
	return (temp);
}
