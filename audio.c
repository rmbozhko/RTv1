/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 13:41:42 by rbozhko           #+#    #+#             */
/*   Updated: 2019/04/28 13:42:49 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			audio_setup(t_env *env)
{
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	env->main_theme = Mix_LoadMUS("/audio/main_theme.wav");
	Mix_VolumeMusic(100);
}

void			play_main_theme(t_env *env)
{
	if (Mix_PlayingMusic() == 0)
		Mix_PlayMusic(env->main_theme, -1);
}

void			clean_up(t_env *env)
{
	Mix_FreeMusic(env->main_theme);
	Mix_CloseAudio();
	SDL_Quit();
}
