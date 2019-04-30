#include "rtv1.h"

t_matrix	optimization_for_tdparaleg(t_matrix *mtrx, t_tdparaleg *tdparaleg)
{
	t_matrix	norm;
	t_matrix	c;

	norm = min_matrix(mtrx, &tdparaleg->location);
	c = mult_matx_skl(&tdparaleg->coord_move, mult_matrix(&norm, &tdparaleg->coord_move));
	norm = min_matrix(&norm, &c);
	norm = optim_settup(&norm);
	return (norm);
}

t_matrix	optimization_for_tdcircle(t_matrix *mtrx, t_tdcircle *tdcircle)
{
	t_matrix	norm;
	double		h;

	norm = min_matrix(mtrx, &tdcircle->location);
	h = mult_matrix(mtrx, &tdcircle->location);
	norm = mult_matx_skl(&norm, 1 / h);
	return (norm);
}

t_matrix	optimization_for_surface(t_matrix *temp, t_surface *surface)
{
	t_matrix norm;

	norm = surface->optimize_rate;
	if (calc_angle_matrix(&norm, temp) < 0)
		norm = mult_matx_skl(&norm, -1);
	return (norm);
}

t_matrix	optimization_for_trg(t_matrix *mtrx, t_trg *trg)
{
	t_matrix	norm;
	t_matrix	c;
	double		temp;

	norm = min_matrix(mtrx, &trg->location);
	temp = mult_matrix(&norm, &trg->coord_move);
	c = mult_matx_skl(&trg->coord_move, temp);
	c = mult_matx_skl(&c, (1 + pow(tan(trg->corner), 2)));
	norm = min_matrix(&norm, &c);
	norm = optim_settup(&norm);
	return (norm);
}

t_matrix	optimization(t_entity *entity, t_matrix *mtrx, t_matrix *temp)
{
	t_matrix optimized_temp;

	ft_build_mtrx((double)0.0, (double)0.0, (double)0.0, &optimized_temp);
	if (entity->ent_id == SPHERE)
		return (optimization_for_tdcircle(mtrx, (t_tdcircle *)(entity->ent)));
	else if (entity->ent_id == CYLINDER)
		return (optimization_for_tdparaleg(mtrx, (t_tdparaleg *)(entity->ent)));
	else if (entity->ent_id == CONUS)
		return (optimization_for_trg(mtrx, (t_trg *)(entity->ent)));
	else if (entity->ent_id == PLANE)
		return (optimization_for_surface(temp, (t_surface *)(entity->ent)));
	return (optimized_temp);
}
