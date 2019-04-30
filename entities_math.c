#include "rtv1.h"

inline

t_matrix	trg_math(t_beam *beam, t_trg *trg, t_matrix *ziel)
{
	t_matrix temp;

	temp.ab = mult_matrix(&beam->richtung, &beam->richtung)	- (1 + pow(tan(trg->corner), 2)) * pow(mult_matrix(&beam->richtung, &trg->coord_move), 2);
	temp.ord = 2 * (mult_matrix(&beam->richtung, ziel) - (1 + pow(tan(trg->corner), 2)) * (mult_matrix(&beam->richtung, &trg->coord_move) * mult_matrix(ziel, &trg->coord_move)));
	temp.apl = SQ(ziel)- (1 + pow(tan(trg->corner), 2))	* pow(mult_matrix(ziel, &trg->coord_move), 2);
	return (temp);
}

t_matrix	tdrect_math(t_beam *beam, t_tdparaleg *tdparal, t_matrix *ziel)
{
	t_matrix temp;

	temp.ab = mult_matrix(&beam->richtung, &beam->richtung) - pow(mult_matrix(&beam->richtung, &tdparal->coord_move), 2);
	temp.ord = 2 * (mult_matrix(&beam->richtung, ziel) - (mult_matrix(&beam->richtung, &tdparal->coord_move) * mult_matrix(ziel, &tdparal->coord_move)));
	temp.apl = SQ(ziel) - pow(mult_matrix(ziel, &tdparal->coord_move), 2) - tdparal->div_diameter;
	return (temp);
}

double		angle_calculation_helper(t_matrix *v)
{
	return (sqrt(v->ab * v->ab + v->ord * v->ord + v->apl * v->apl));
}

double		calc_angle_matrix(t_matrix *v1, t_matrix *v2)
{
	double cos;

	cos = (v1->ab * v2->ab + v1->ord * v2->ord + v1->apl * v2->apl) / 
		(angle_calculation_helper(v1) * angle_calculation_helper(v2));
	return (cos);
}