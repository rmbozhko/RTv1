#include "rtv1.h"

static	int		display_menu(t_env* env)
{
	mlx_string_put(env->mlx, env->win, 0, 10, 0x6EDBBA,
			"Control: ");
	mlx_string_put(env->mlx, env->win, 0, 28, 0x6EDBBA,
			"Press + or - to increase transperancy coefficient");
	return (0);
}

static int	key_binds(int keycode, t_env* env)
{
	if (keycode == ESC)
	{
		clean_up(env);
		exit(0);
	}
	else if (keycode == P_LTTR)
		ft_make_printscreen(env);
	else if (keycode == PLUS || keycode == MINUS)
	{
		if (keycode == MINUS)
		{
			if (env->clarity_coef > 0 && env->clarity_coef < 300)
				env->clarity_coef -= 5;
		}
		else
		{
			if (env->clarity_coef > 0 && env->clarity_coef < 300)
				env->clarity_coef += 5;
		}
		X = 0;
		Y = 0;
		mlx_clear_window(env->mlx, env->win); 
		process_beam(env, 0.0);
	}
	return (0);
}

int			main(const int argc, char* argv[])
{
	t_env	env;
	
	if (argc == 5 && ft_strlen(argv[2]) && ft_strlen(argv[4]))
	{
		ft_init_env(&env, ft_atoi(argv[2]), ft_atoi(argv[4]));	
	}
	else
		ft_throw_exception(USAGE);
	mlx_hook(env.win, 2, 5, key_binds, &env);
	mlx_expose_hook(env.win, display_menu, &env);
	mlx_loop(env.mlx);
	return (0);
}
