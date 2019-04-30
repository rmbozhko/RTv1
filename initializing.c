/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:01:56 by rbozhko           #+#    #+#             */
/*   Updated: 2019/04/30 12:03:04 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_init_env(t_env *env, unsigned width, unsigned height)
{
	if ((width > 600 && width < 2000) && (height > 600 && height < 2000))
	{
		env->width = width;
		env->height = height;
		env->mlx = mlx_init();
		env->win = mlx_new_window(env->mlx, env->width, env->height, "RTv1");
		X = 0;
		Y = 0;
		env->img = mlx_new_image(env->mlx, env->width, env->height);
		env->bpp = BPP;
		env->e = 0;
		env->data = mlx_get_data_addr(env->img, &env->bpp,
			&env->sline, &env->e);
		env->clarity_coef = MAX_UCHAR;
		audio_setup(env);
		play_main_theme(env);
		instantiating_fentity(env);
		process_beam(env, 0.0);
	}
	else
		ft_throw_exception("Invalid window size parameters");
}

int			tdcircle_inter(t_beam *b, void *ent, t_env *env, double bound)
{
	t_matrix	dist;
	t_matrix	miss;
	t_matrix	calc;
	t_tdcircle	*sphere;
	int			ret;

	ret = 0;
	sphere = (t_tdcircle *)(ent);
	dist = min_matrix(&sphere->location, &b->anfang);
	miss.ab = mult_matrix(&b->richtung, &dist);
	miss.ord = miss.ab * miss.ab - mult_matrix(&dist, &dist) + sphere->div_diameter;
	if (miss.ord < 0.0)
		return (0);
	calc.ab = miss.ab - sqrt(miss.ord);
	calc.ord = miss.ab + sqrt(miss.ord);
	(calc.ab > 0.001) && (calc.ab < env->skl) ? ret = 1 : 0;
	(calc.ab > 0.001) && (calc.ab < env->skl) ? env->skl = calc.ab : 0;
	(calc.ord > 0.001) && (calc.ord < env->skl) ? ret = 1 : 0;
	(calc.ord > 0.001) && (calc.ord < env->skl) ? env->skl = calc.ord : 0;
	env->skl -= 0.01;
	return ((env->skl > bound) ? 0 : ret);
}

t_matrix	optimization_for_surface(t_matrix *lol, t_surface *surface)
{
	t_matrix temp;

	temp = surface->optimize_rate;
	if (calc_angle_matrix(&temp, lol) < 0)
		temp = mult_matx_skl(&temp, -1);
	return (temp);
}

void		clean_up(t_env *env)
{
	Mix_FreeMusic(env->main_theme);
	Mix_CloseAudio();
	SDL_Quit();
}

void		insert_pixel(t_env *env, int x, int y, t_paint *color)
{
	if ((x >= 0 && x < (int)env->width) && (y >= 0 && y < (int)env->height))
	{
		env->data[((y * env->sline) + (x * 4))] = color->red;
		env->data[((y * env->sline) + (x * 4)) + 1] = color->green;
		env->data[((y * env->sline) + (x * 4)) + 2] = color->blue;
		env->data[((y * env->sline) + (x * 4)) + 3] = color->clarity;
	}
}
