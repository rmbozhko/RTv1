/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:41:18 by yvasin            #+#    #+#             */
/*   Updated: 2017/04/05 19:41:19 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft/libft.h"
# include <mlx.h>

# define WIDTH 1900
# define HEIGHT 1200
# define BPP 32
# define ESC 53
# define P_LTTR 35

# define SPHERE 1
# define CYLINDER 2
# define CONUS 3
# define PLANE 4

# define INV_WIDTH (1 / (double)WIDTH)
# define INV_HEIGHT (1 / (double)HEIGHT)
# define FOV 60
# define ASP_RATIO (WIDTH / (double)HEIGHT)
# define ANGLE (tan((FOV / 2 * M_PI / 180.0)))

# define RED (t_paint){0, 0, 255, 0}
# define GREEN (t_paint){0, 255, 0, 0}
# define BLUE (t_paint){255, 0, 0, 0}
# define CYAN (t_paint){255, 255, 0, 0}
# define YELLOW (t_paint){0, 255, 255, 0}
# define MAGENTA (t_paint){255, 0, 255, 0}
# define WHITE (t_paint){255, 255, 255, 0}
# define BLACK (t_paint){10, 10, 10, 0}

typedef struct		s_matrix
{
	double			x;
	double			y;
	double			z;
}					t_matrix;

typedef struct	s_paint
{
	double		r;
	double		g;
	double		b;
	double		tr;
}				t_paint;

typedef struct	s_beam
{
	t_matrix	start;
	t_matrix	dir;
}				t_beam;

typedef struct	s_glow
{
	t_matrix	pos;
	t_paint		intensity;
}				t_glow;

typedef struct	s_plane
{
	t_matrix	point;
	t_matrix	normal;
	t_paint		color;
}				t_surface;

typedef struct	s_tdcircle
{
	double		radius;
	double		radius2;
	t_paint		color;
	t_matrix	centre;
}				t_tdcircle;

typedef struct	s_tdparaleg
{
	double		radius;
	double		radius2;
	t_matrix	pos;
	t_matrix	rot;

	t_paint		color;
}				t_tdparaleg;

typedef struct	s_trg
{
	t_matrix	pos;
	t_matrix	rot;
	double		angle;

	t_paint		color;
}				t_trg;

typedef struct	s_entity
{
	void		*obj;
	int			type;
	t_paint		color;
}				t_entity;

typedef struct	s_env
{
	void		*mlx;
	void		*win;

	void		*img;
	int			bpp;
	int			sline;
	int			e;
	char		*data;

	int			x;
	int			y;
	double		alpha;
	double		beta;
	double		gamma;

	t_glow		light;
	t_tdparaleg	cylinder;
	t_tdparaleg	cylinder2;
	t_tdcircle	sphere;
	t_surface	plane;
	t_surface	plane1;
	t_trg		cone;
	t_entity	obj[6];

	t_matrix	scaled;
	t_matrix	new_start;
	t_matrix	dist_to_light;

	double		t;
}				t_env;


void		ft_init_env(t_env *env);

void		instantiating_fentity(t_env *env);
void		instantiating_sentity(t_env *env);
void		instantiating_tentity(t_env *env);
void		insert_pixel(t_env *env, int x, int y, t_paint *color);
int			objects_hinteracting(t_entity *obj, t_beam *ray,
						t_env *env, double d);

t_matrix	abscissa_rotation(t_matrix *dir, double angle);
t_matrix	ordinate_rotation(t_matrix *dir, double angle);
t_matrix	aplikata_rotation(t_matrix *dir, double angle);
t_matrix	rotate(t_matrix *v, double alpha, double beta, double gamma);

t_matrix	min_matrix(t_matrix *v1, t_matrix *v2);
t_matrix	mult_matx_skl(t_matrix *v, double scale);
t_matrix	summ_matrix(t_matrix *v1, t_matrix *v2);
t_matrix	optim_settup(t_matrix *vector);
double		mult_matrix(t_matrix *v1, t_matrix *v2);

t_matrix	optimization(t_entity *obj, t_matrix *start, t_matrix *lil);

void		window_setting(t_env *env, t_beam *shadow_ray,
						double light_d, int cur_obj);
double		calc_angle_matrix(t_matrix *v1, t_matrix *v2);

t_matrix	trg_math(t_beam *ray, t_trg *cone, t_matrix *dist);
t_matrix	tdrect_math(t_beam *ray, t_tdparaleg *cyl, t_matrix *dist);
t_matrix	xyz_rotation(t_matrix *v, t_env *env);
void		depict_entity(t_env *env, int cur_obj, t_matrix *dir);

int			determine_interacting(t_env *env, t_beam *ray, double light_d);
t_beam		determine_sbeam(t_env *env, t_beam *ray);
void		pull_beam(t_env *env);


int			ft_make_printscreen(t_env *env);

#endif
