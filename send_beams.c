#include "rtv1.h"

inline double		get_width_inverse(t_env *env)
{
	return ((double)(1.0 / (double)env->width));
}

inline double		get_height_inverse(t_env *env)
{
	return ((double)(1.0 / (double)env->height));
}

t_matrix	xyz_rotation(t_matrix *richtung, t_env *env)
{
	richtung->apl = 1;
	richtung->ord = (1 - 2 * ((Y + 0.5) * get_height_inverse(env))) * ANGLE;
	env->skl = MAGIC_NUM;
	richtung->ab = (2 * ((X + 0.5) * get_width_inverse(env)) - 1) * ANGLE * ASP_RATIO;
	return (optim_settup(richtung));
}

static void		ft_build_mtrx(int abscissa, int ordinata, int aplikanta, t_matrix *mtrx)
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
			beam.richtung = xyz_rotation(&beam.richtung, env);
			if (flag)
			{
				ft_build_mtrx(1600 / 4 * 2, 15 % 10 * 100, 3 * -7 * cos(0) * 100, &beam.anfang);
				flag = false;
			}
			((cho_entity = determine_interacting(env, &beam, ITS_MAGIC)) != -1) ? 
				window_setting(sqrt(SQ(&env->s_of_l)), cho_entity, &beam, env) : 0;
			X++;
		}
		X = 0;
		Y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

int		determine_interacting(t_env *env, t_beam *beam, double glow_dist)
{
	int		counter;
	int		id;

	counter = -1;
	id = -1;
	while (++id < 6)
		counter = (objects_hinteracting(&env->entities_strg[id],
			beam, env, glow_dist) == 1) ? id : counter;
	return (counter);
}

t_beam	determine_sbeam(t_env *env)
{
	t_beam	beam_chorn;

	beam_chorn.anfang = env->neues_anfang;
	beam_chorn.richtung = optim_settup(&env->s_of_l);
	return (beam_chorn);
}

void	depict_entity(t_env *env, int cur_obj, t_matrix *dir)
{
	t_matrix	norm;
	t_paint		color_dark;

	norm = optimization(&(env->entities_strg[cur_obj]), &env->neues_anfang, dir);
	color_dark = env->entities_strg[cur_obj].paint;
	color_dark.clarity = 230 * (1 - calc_angle_matrix(&norm, dir));
	if (calc_angle_matrix(&norm, dir) >= 0.94)
	{
		color_dark.red += (255 - color_dark.red)
			* calc_angle_matrix(&norm, dir) * 15;
		color_dark.green += (255 - color_dark.green)
			* calc_angle_matrix(&norm, dir) * 15;
		color_dark.blue += (255 - color_dark.blue)
			* calc_angle_matrix(&norm, dir) * 15;
	}
	insert_pixel(env, X, Y, &color_dark);
}

void	window_setting(double glow_dist, int cur_obj, t_beam *ch_beam, t_env *env)
{
	t_beam		temp;

	env->multpl_skl = mult_matx_skl(&ch_beam->richtung, env->skl);
	env->neues_anfang = summ_matrix(&ch_beam->anfang, &env->multpl_skl);
	env->s_of_l = min_matrix(&env->glow.location, &env->neues_anfang);
	temp = determine_sbeam(env);
	if (determine_interacting(env, &temp, glow_dist) < 0)
		depict_entity(env, cur_obj, &temp.richtung);
	else
	{
		env->entities_strg[cur_obj].paint.clarity = env->clarity_coef;
		insert_pixel(env, X, Y, &(env->entities_strg[cur_obj].paint));
	}
}
