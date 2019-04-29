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

# define SPHERE 1
# define CYLINDER 2
# define CONUS 3
# define PLANE 4

# define INV_WIDTH (1 / (double)WIDTH)
# define INV_HEIGHT (1 / (double)HEIGHT)
# define FOV 60
# define ASP_RATIO (WIDTH / (double)HEIGHT)
# define ANGLE (tan((FOV / 2 * M_PI / 180.0)))

# define RED (t_color){0, 0, 255, 0}
# define GREEN (t_color){0, 255, 0, 0}
# define BLUE (t_color){255, 0, 0, 0}
# define CYAN (t_color){255, 255, 0, 0}
# define YELLOW (t_color){0, 255, 255, 0}
# define MAGENTA (t_color){255, 0, 255, 0}
# define WHITE (t_color){255, 255, 255, 0}
# define BLACK (t_color){10, 10, 10, 0}

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
	double		tr;
}				t_color;

typedef struct	s_ray
{
	t_vector	start;
	t_vector	dir;
}				t_ray;

typedef struct	s_light
{
	t_vector	pos;
	t_color		intensity;
}				t_light;

typedef struct	s_plane
{
	t_vector	point;
	t_vector	normal;
	t_color		color;
}				t_plane;

typedef struct	s_sphere
{
	double		radius;
	double		radius2;
	t_color		color;
	t_vector	centre;
}				t_sphere;

typedef struct	s_cylinder
{
	double		radius;
	double		radius2;
	t_vector	pos;
	t_vector	rot;

	t_color		color;
}				t_cylinder;

typedef struct	s_cone
{
	t_vector	pos;
	t_vector	rot;
	double		angle;

	t_color		color;
}				t_cone;

typedef struct	s_obj
{
	void		*obj;
	int			type;
	t_color		color;
}				t_obj;

typedef struct	s_vedro
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

	t_light		light;
	t_cylinder	cylinder;
	t_cylinder	cylinder2;
	t_sphere	sphere;
	t_plane		plane;
	t_plane		plane1;
	t_cone		cone;
	t_obj		obj[6];

	t_vector	scaled;
	t_vector	new_start;
	t_vector	dist_to_light;

	double		t;
}				t_vedro;


void		ft_init_env(t_vedro *vedro);

void		instantiating_fentity(t_vedro *vedro);
void		instantiating_sentity(t_vedro *vedro);
void		instantiating_tentity(t_vedro *vedro);
void		insert_pixel(t_vedro *vedro, int x, int y, t_color *color);
int			objects_hinteracting(t_obj *obj, t_ray *ray,
						t_vedro *vedro, double d);

t_vector	abscissa_rotation(t_vector *dir, double angle);
t_vector	ordinate_rotation(t_vector *dir, double angle);
t_vector	aplikata_rotation(t_vector *dir, double angle);
t_vector	rotate(t_vector *v, double alpha, double beta, double gamma);

t_vector	min_matrix(t_vector *v1, t_vector *v2);
t_vector	mult_matx_skl(t_vector *v, double scale);
t_vector	summ_matrix(t_vector *v1, t_vector *v2);
t_vector	optim_settup(t_vector *vector);
double		mult_matrix(t_vector *v1, t_vector *v2);

t_vector	optimization(t_obj *obj, t_vector *start, t_vector *lil);

void		window_setting(t_vedro *vedro, t_ray *shadow_ray,
						double light_d, int cur_obj);
double		calc_angle_matrix(t_vector *v1, t_vector *v2);

t_vector	trg_math(t_ray *ray, t_cone *cone, t_vector *dist);
t_vector	tdrect_math(t_ray *ray, t_cylinder *cyl, t_vector *dist);
t_vector	xyz_rotation(t_vector *v, t_vedro *vedro);
void		depict_entity(t_vedro *vedro, int cur_obj, t_vector *dir);

int			determine_interacting(t_vedro *vedro, t_ray *ray, double light_d);
t_ray		determine_sbeam(t_vedro *vedro, t_ray *ray);
void		pull_beam(t_vedro *vedro);


#endif
