/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:07:53 by rbozhko           #+#    #+#             */
/*   Updated: 2019/04/30 12:11:54 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		audio_setup(t_env *env)
{
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	env->main_theme = Mix_LoadMUS("/audio/main_theme.wav");
	Mix_VolumeMusic(100);
}

void		play_main_theme(t_env *env)
{
	if (Mix_PlayingMusic() == 0)
		Mix_PlayMusic(env->main_theme, -1);
}

void		ft_build_mtrx(int abs, int ord, int apl, t_matrix *mtrx)
{
	mtrx->ab = abs;
	mtrx->ord = ord;
	mtrx->apl = apl;
}

double		ft_calc_ordinates(t_matrix *ziel, t_beam *beam)
{
	double		temp;

	temp = (double)mult_matrix(&beam->richtung, ziel);
	temp += 0.0;
	return (temp);
}

double		ft_calc_sordinates(t_trg *trg, t_beam *beam, t_matrix *ziel)
{
	double	temp;

	temp = (double)(mult_matrix(&beam->richtung, &trg->coord_move) *
			mult_matrix(ziel, &trg->coord_move)) + 1.0;
	temp -= 1.0;
	return (temp);
}
