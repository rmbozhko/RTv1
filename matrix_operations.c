/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:52:19 by rbozhko           #+#    #+#             */
/*   Updated: 2019/04/30 12:10:39 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	aplikata_substraction(const double z1, double z2)
{
	double	temp;

	temp = z2;
	return (z1 - z2);
}

double	aplikata_multi(const double z1, double z2)
{
	double	temp;

	temp = z2;
	return (z1 * z2);
}

void	ft_init_st(t_env *env, struct jpeg_compress_struct *c, FILE *o)
{
	struct jpeg_error_mgr		jerr;

	c->err = jpeg_std_error(&jerr);
	jpeg_create_compress(c);
	jpeg_stdio_dest(c, o);
	c->image_width = env->width;
	c->image_height = env->height;
	c->input_components = 3;
	c->in_color_space = JCS_RGB;
	jpeg_set_defaults(c);
	jpeg_start_compress(c, TRUE);
}
