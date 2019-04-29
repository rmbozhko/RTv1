/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:54:11 by yvasin            #+#    #+#             */
/*   Updated: 2017/04/05 19:54:11 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	create_image(t_vedro *vedro)
{
	vedro->img = mlx_new_image(vedro->mlx, WIDTH, HEIGHT);
	vedro->bpp = 32;
	vedro->e = 0;
	vedro->data = mlx_get_data_addr(vedro->img, &vedro->bpp,
		&vedro->sline, &vedro->e);
}

void	im_pp(t_vedro *vedro, int x, int y, t_color *color)
{
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		vedro->data[((y * vedro->sline) + (x * 4))] = color->r;
		vedro->data[((y * vedro->sline) + (x * 4)) + 1] = color->g;
		vedro->data[((y * vedro->sline) + (x * 4)) + 2] = color->b;
		vedro->data[((y * vedro->sline) + (x * 4)) + 3] = color->tr;
	}
}
