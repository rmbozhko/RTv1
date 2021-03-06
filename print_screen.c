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

void		ft_init_st(t_env *env, struct jpeg_compress_struct *c, FILE *o)
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

unsigned char		*ft_get_proper(t_env *env)
{
	unsigned char		*temp;
	size_t				i;
	size_t				j;
	unsigned long		len;

	i = 0;
	j = 0;
	len = env->height * env->sline;
	temp = (unsigned char*)malloc(sizeof(char) * env->height * env->width * 3 + 1);
	ft_bzero(temp, sizeof(char) * env->height * env->width * 3 + 1);
	while (i < len && j < len)
	{
		if (((j + 1) % 4) == 0)
			j++;
		temp[i++] = env->data[j + 2];
		temp[i++] = env->data[j + 1];
		temp[i++] = env->data[j];
		j += 3;
	}
	return (temp);
}

int			ft_make_printscreen(t_env *env)
{
	FILE							*outfile;
	struct jpeg_compress_struct		cinfo;
	JSAMPROW						row_pointer[1];
	unsigned char					*temp;

	outfile = ft_get_file();
	ft_init_st(env, &cinfo, outfile);
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