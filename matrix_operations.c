#include "rtv1.h"

double		ordinat_substraction(const double y1, const double y2)
{
	return (y1 - y2);
}

inline double	aplikata_substraction(const double z1, double z2)
{
	double	temp;

	temp = z2;
	return (z1 - z2);
}

t_matrix	min_matrix(t_matrix *v1, t_matrix *v2)
{
	t_matrix 	res;
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

inline double	aplikata_multi(const double z1, double z2)
{
	double	temp;

	temp = z2;
	return (z1 * z2);
}

t_matrix	mult_matx_skl(t_matrix *v, double scale)
{
	t_matrix 	res;
	double		ab_temp;

	ab_temp = v->ab * scale;

	res.ab = ab_temp;
	res.ord = ordinat_multi(v->ord, scale);
	res.apl = aplikata_multi(v->apl, scale);
	return (res);
}

double		summa_absciss(const double x1, const double x2)
{
	return (x1 + x2);
}

inline double	summa_apliakta(const double z1, double z2)
{
	double	temp;

	temp = z2;
	return (z1 + z2);
}

t_matrix	summ_matrix(t_matrix *v1, t_matrix *v2)
{
	t_matrix 	res;
	double		temp_ord;

	res.ab = summa_absciss(v1->ab, v2->ab);
	temp_ord = v1->ord + v2->ord; 
	res.ord = temp_ord;
	res.apl = summa_apliakta(v1->apl, v2->apl);
	return (res);
}

t_matrix	optim_settup(t_matrix *mtrx)
{
	t_matrix	temp;
	double		temp_strg;

	temp_strg = sqrt(SQ(mtrx)) + 11.5;
	temp_strg -= (5.75 + 5.75);
	temp = mult_matx_skl(mtrx, pow( temp_strg, -1));
	return (temp);
}

double		mult_matrix(t_matrix *v1, t_matrix *v2)
{
	double 	res;
	double	ab_temp;
	double	ord_temp;
	double	aplikata_temp;

	ab_temp = ordinat_multi(v1->ab, v2->ab);
	ord_temp = ordinat_multi(v1->ord, v2->ord);
	aplikata_temp = ordinat_multi(v1->apl, v2->apl);
	res = ab_temp + summa_absciss(ord_temp, aplikata_temp);

	return (res);
}
