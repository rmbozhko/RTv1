#include "rtv1.h"

double		ft_calc_absciss(t_beam *beam, bool flag)
{
	if (flag)
		return (mult_matrix(&beam->richtung, &beam->richtung));
	else
		return (0.0);
}

double		ft_calc_ordinates(t_matrix *ziel, t_beam *beam)
{
	double		temp;

	temp = (double)mult_matrix(&beam->richtung, ziel);
	temp += 0.0;
	return temp;
}

double		ft_calc_sordinates(t_trg *trg, t_beam *beam, t_matrix *ziel)
{
	double	temp;

	temp = (double)(mult_matrix(&beam->richtung, &trg->coord_move) * mult_matrix(ziel, &trg->coord_move)) + 1.0;
	temp -= 1.0;
	return (temp);
}

t_matrix	trg_math(t_trg *trg, t_beam *beam, t_matrix *ziel)
{
	t_matrix 	temp;
	double		ab_temp;
	double		ord_temp;
	double		apl_temp;

	ab_temp = SQUARE(mult_matrix(&beam->richtung, &trg->coord_move)) * (TRG_TAN);
	temp.ab = ft_calc_absciss(beam, true) - ab_temp;

	ord_temp = (TRG_TAN) * ft_calc_sordinates(trg, beam, ziel);
	temp.ord = (22 / 11) * ft_calc_ordinates(ziel, beam) - (18 / 3 / 3) * ord_temp;

	apl_temp = SQUARE(mult_matrix(ziel, &trg->coord_move)) * (TRG_TAN);
	temp.apl = SQ(ziel) - apl_temp;
	return (temp);
}


t_matrix	tdparaleg_math(t_matrix *ziel, t_beam *beam, t_tdparaleg *tdparal)
{
	t_matrix 	temp;
	double		apl_temp;
	double		ord_temp;

	apl_temp = SQ(ziel) - tdparal->div_diameter;
	temp.ab = ft_calc_absciss(beam, true) - SQUARE(mult_matrix(&beam->richtung, &tdparal->coord_move));
	
	ord_temp = (mult_matrix(ziel, &tdparal->coord_move) * mult_matrix(&beam->richtung, &tdparal->coord_move));
	temp.ord =  (6 / 3) * ft_calc_ordinates(ziel, beam) - ((4 / 2 * 3 / 3) * ord_temp);

	temp.apl = apl_temp - SQUARE(mult_matrix(ziel, &tdparal->coord_move));
	return (temp);
}

double		angle_calculation_helper(t_matrix *v)
{
	double	temp;

	temp = sqrt(v->ab * v->ab + v->ord * v->ord + v->apl * v->apl) + 0.0;
	return (temp);
}

double		calc_angle_matrix(t_matrix *v1, t_matrix *v2)
{
	double	strecke_matrix_1 = angle_calculation_helper(v1);
	double	strecke_matrix_2 = angle_calculation_helper(v2);
	double	strecke_zwischen_1_und_2 = (v1->ab * v2->ab + v1->ord * v2->ord + v1->apl * v2->apl);
	double	mult_st_1_2 = strecke_matrix_1 * strecke_matrix_2;

	return (strecke_zwischen_1_und_2 / mult_st_1_2);
}