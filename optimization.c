#include "rtv1.h"

t_matrix	optimization_for_tdparaleg(t_matrix *start, t_tdparaleg *cyl)
{
	t_matrix	norm;
	t_matrix	c;
	double		temp;

	norm = min_matrix(start, &cyl->location);
	temp = mult_matrix(&norm, &cyl->coord_move);
	c = mult_matx_skl(&cyl->coord_move, temp);
	norm = min_matrix(&norm, &c);
	norm = optim_settup(&norm);
	return (norm);
}

t_matrix	optimization_for_tdcircle(t_matrix *start, t_tdcircle *sphere)
{
	t_matrix	norm;
	double		h;

	norm = min_matrix(start, &sphere->location);
	h = mult_matrix(start, &sphere->location);
	norm = mult_matx_skl(&norm, 1 / h);
	return (norm);
}

t_matrix	optimization_for_surface(t_surface *plane, t_matrix *lil)
{
	t_matrix norm;

	norm = plane->optimize_rate;
	if (calc_angle_matrix(&norm, lil) < 0)
		norm = mult_matx_skl(&norm, -1);
	return (norm);
}

t_matrix	optimization_for_trg(t_matrix *start, t_trg *cone)
{
	t_matrix	norm;
	t_matrix	c;
	double		temp;

	norm = min_matrix(start, &cone->location);
	temp = mult_matrix(&norm, &cone->coord_move);
	c = mult_matx_skl(&cone->coord_move, temp);
	c = mult_matx_skl(&c, (1 + pow(tan(cone->corner), 2)));
	norm = min_matrix(&norm, &c);
	norm = optim_settup(&norm);
	return (norm);
}

t_matrix	optimization(t_entity *entity, t_matrix *start, t_matrix *lil)
{
	t_matrix norm;

	norm.ab = 0;
	norm.ord = 0;
	norm.apl = 0;
	if (entity->ent_id == SPHERE)
		return (optimization_for_tdcircle(start, (t_tdcircle *)(entity->ent)));
	else if (entity->ent_id == CYLINDER)
		return (optimization_for_tdparaleg(start, (t_tdparaleg *)(entity->ent)));
	else if (entity->ent_id == CONUS)
		return (optimization_for_trg(start, (t_trg *)(entity->ent)));
	else if (entity->ent_id == PLANE)
		return (optimization_for_surface((t_surface *)(entity->ent), lil));
	return (norm);
}
