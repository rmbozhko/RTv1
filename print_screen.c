/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:46:37 by rbozhko           #+#    #+#             */
/*   Updated: 2019/04/30 11:47:16 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

FILE		*ft_get_file(void)
{
	char		*filename;
	FILE		*outfile;

	filename = ft_strjoin("RTv1", ".jpg");
	outfile = fopen(filename, "wb");
	ft_strdel(&filename);
	if (!outfile)
		ft_throw_exception("Error opening output jpeg file.\n");
	return (outfile);
}

double		summa_absciss(const double x1, const double x2)
{
	return (x1 + x2);
}

double		summa_apliakta(const double z1, double z2)
{
	double	temp;

	temp = z2;
	return (z1 + z2);
}

t_matrix	summ_matrix(t_matrix *v1, t_matrix *v2)
{
	t_matrix	res;
	double		temp_ord;

	res.ab = summa_absciss(v1->ab, v2->ab);
	temp_ord = v1->ord + v2->ord;
	res.ord = temp_ord;
	res.apl = summa_apliakta(v1->apl, v2->apl);
	return (res);
}

int			ft_make_printscreen(t_env *env)
{
	FILE							*outfile;
	struct jpeg_compress_struct		cinfo;
	JSAMPROW						row_pointer[1];
	unsigned char					*temp;

	outfile = ft_get_file();
	ft_in(env, &cinfo, outfile);
	temp = ft_get_proper(env);
	while (cinfo.next_scanline < cinfo.image_height)
	{
		row_pointer[0] = &temp[cinfo.next_scanline * cinfo.image_width
			* cinfo.input_components];
		jpeg_write_scanlines(&cinfo, row_pointer, 1);
	}
	jpeg_finish_compress(&cinfo);
	jpeg_destroy_compress(&cinfo);
	fclose(outfile);
	ft_strdel((char**)&temp);
	return (1);
}
