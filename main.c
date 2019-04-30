/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:53:03 by rbozhko           #+#    #+#             */
/*   Updated: 2019/04/30 12:01:19 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			display_menu(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 0, 10, 0x6EDBBA,
			"Control: ");
	mlx_string_put(env->mlx, env->win, 0, 28, 0x6EDBBA,
			"Press + or - to increase transperancy coefficient");
	return (0);
}

int			key_binds(int keycode, t_env *env)
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

double		angle_calculation_helper(t_matrix *v)
{
	double	temp;

	temp = sqrt(v->ab * v->ab + v->ord * v->ord + v->apl * v->apl) + 0.0;
	return (temp);
}

double		calc_angle_matrix(t_matrix *v1, t_matrix *v2)
{
	double	strecke_matrix_1;
	double	strecke_matrix_2;
	double	strecke_zwischen_1_und_2;
	double	mult_st_1_2;

	strecke_matrix_1 = angle_calculation_helper(v1);
	strecke_matrix_2 = angle_calculation_helper(v2);
	strecke_zwischen_1_und_2 = (v1->ab * v2->ab + v1->ord
			* v2->ord + v1->apl * v2->apl);
	mult_st_1_2 = strecke_matrix_1 * strecke_matrix_2;
	return (strecke_zwischen_1_und_2 / mult_st_1_2);
}

int			main(const int argc, char *argv[])
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
