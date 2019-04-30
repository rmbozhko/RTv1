#include "rtv1.h"

inline double		get_width_inverse(t_env *env)
{
	return ((double)(1.0 / (double)env->width));
}

inline double		get_height_inverse(t_env *env)
{
	return ((double)(1.0 / (double)env->height));
}

t_matrix	xyz_rotation(t_env *env, t_matrix *richtung)
{
	richtung->apl = 1;
	richtung->ord = (1 - 2 * ((Y + 0.5) * get_height_inverse(env))) * ANGLE;
	env->skl = MAGIC_NUM;
	richtung->ab = (2 * ((X + 0.5) * get_width_inverse(env)) - 1) * ANGLE * ASP_RATIO;
	return (optim_settup(richtung));
}

void		ft_build_mtrx(int abscissa, int ordinata, int aplikanta, t_matrix *mtrx)
{
	mtrx->ab = abscissa;
	mtrx->ord = ordinata;
	mtrx->apl = aplikanta;
}

void	process_beam(t_env *env, int cho_entity)
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
				ft_build_mtrx(1600 / 4 * 2, 15 % 10 * 100, 3 * -7 * cos(0) * 100, &beam.anfang);
				flag = false;
			}
			((cho_entity = determine_interacting(env, ITS_MAGIC, &beam)) != -1) ? 
				window_setting(sqrt(SQ(&env->s_of_l)), cho_entity, &beam, env) : 0;
			X++;
		}
		X = 0;
		Y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

int		determine_interacting(t_env *env, double glow_dist, t_beam *beam)
{
	int		counter;
	int		id;

	counter = -1;
	id = -1;
	while (++id < MAX_OBJ_NUM)
		counter = (objects_hinteracting(&env->entities_strg[id],
			beam, env, glow_dist) == 1) ? id : counter;
	return (counter);
}

t_beam	determine_sbeam(t_env *env)
{
	t_beam	beam_chorn;

	beam_chorn.richtung = optim_settup(&env->s_of_l);
	beam_chorn.anfang = env->neues_anfang;
	return (beam_chorn);
}

void	update_dpaint(t_paint *paint, t_matrix *mtrx, t_matrix *richt)
{
	double		coef;
	double		alpha;

	coef = 60.0 / 2.0 / 2.0;
	alpha = calc_angle_matrix(mtrx, richt) * coef;
	
	paint->red += (MAX_UCHAR - paint->red) * alpha;
	paint->blue += (MAX_UCHAR - paint->blue) * alpha;
	paint->green += (MAX_UCHAR - paint->green) * alpha;
}

void	depict_entity(t_env *env, int cho_entity, t_matrix *richt)
{
	t_matrix	mtrx;
	t_paint		dpaint;

	mtrx = optimization(&(env->entities_strg[cho_entity]), &env->neues_anfang, richt);
	dpaint = env->entities_strg[cho_entity].paint;
	dpaint.clarity = 230 * (1 - calc_angle_matrix(&mtrx, richt));
	if (calc_angle_matrix(&mtrx, richt) >= BOUND)
		update_dpaint(&dpaint, &mtrx, richt);
	insert_pixel(env, X, Y, &dpaint);
}

void	window_setting(double glow_dist, int cho_entity, t_beam *ch_beam, t_env *env)
{
	t_beam		temp;

	temp = determine_sbeam(env);
	env->multpl_skl = mult_matx_skl(&ch_beam->richtung, env->skl);
	env->neues_anfang = summ_matrix(&ch_beam->anfang, &env->multpl_skl);
	env->s_of_l = min_matrix(&env->glow.location, &env->neues_anfang);
	if (determine_interacting(env, glow_dist, &temp) == -1)
		depict_entity(env, cho_entity, &temp.richtung);
	else
	{
		env->entities_strg[cho_entity].paint.clarity = env->clarity_coef;
		insert_pixel(env, X, Y, &(env->entities_strg[cho_entity].paint));
	}
}
