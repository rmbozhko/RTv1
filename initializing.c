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
		env->clarity_coef = 255;
		audio_setup(env);
		play_main_theme(env);
		instantiating_fentity(env);
		process_beam(env, 0.0);
	}
	else
		ft_throw_exception("Invalid window size parameters");
	
}

void	insert_pixel(t_env *env, int x, int y, t_paint *color)
{
	if ((x >= 0 && x < (int)env->width) && (y >= 0 && y < (int)env->height))
	{
		env->data[((y * env->sline) + (x * 4))] = color->red;
		env->data[((y * env->sline) + (x * 4)) + 1] = color->green;
		env->data[((y * env->sline) + (x * 4)) + 2] = color->blue;
		env->data[((y * env->sline) + (x * 4)) + 3] = color->clarity;
	}
}
