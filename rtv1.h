/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:14:57 by rbozhko           #+#    #+#             */
/*   Updated: 2019/04/30 12:16:59 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <mlx.h>
# include "jpeglib/jpeglib.h"
# include <SDL.h>
# include "SDL_mixer.h"

# define USAGE "./rtv1 -w [uint] -h [uint]"
# define BPP 32
# define ESC 53
# define P_LTTR 35
# define PLUS 69
# define MINUS 78
# define MAGIC_NUM 200000.0
# define ITS_MAGIC 8000000
# define MAX_OBJ_NUM 6
# define MAX_UCHAR 255
# define BOUND 0.94
# define MULT_HELPER(X) X->ab * X->ab + X->ord * X->ord + X->apl * X->apl
# define TRG_TAN 1 + pow(tan(trg->corner), 2)
# define SQUARE(X) pow(X, 2)

# define TDCIRCLE 1
# define TDPARALEG 2
# define TRG 3
# define SURFACE 4

# define SQ(X) mult_matrix(X, X)
# define X env->x
# define Y env->y

# define FOV 60
# define ASP_RATIO (env->width / (double)env->height)
# define ANGLE (tan((FOV / 2 * M_PI / 180.0)))

# define RED (t_paint){0, 0, 255, env->clarity_coef}
# define GREEN (t_paint){0, 255, 0, env->clarity_coef}
# define BLUE (t_paint){255, 0, 0, env->clarity_coef}
# define CYAN (t_paint){255, 255, 0, env->clarity_coef}
# define YELLOW (t_paint){0, 255, 255, env->clarity_coef}
# define MAGENTA (t_paint){255, 0, 255, env->clarity_coef}
# define WHITE (t_paint){255, 255, 255, env->clarity_coef}
# define BLACK (t_paint){10, 10, 10, env->clarity_coef}

typedef struct		s_matrix
{
	double			ab;
	double			ord;
	double			apl;
}					t_matrix;

typedef struct	s_paint
{
	double		red;
	double		green;
	double		blue;
	double		clarity;
}				t_paint;

typedef struct	s_beam
{
	t_matrix	anfang;
	t_matrix	richtung;
}				t_beam;

typedef struct	s_glow
{
	t_matrix	location;
}				t_glow;

typedef struct	s_plane
{
	t_matrix	dot;
	t_matrix	optimize_rate;
	t_paint		paint;
}				t_surface;

typedef struct	s_tdcircle
{
	double		div_diameter;
	t_paint		paint;
	t_matrix	location;
}				t_tdcircle;

typedef struct	s_tdparaleg
{
	double		div_diameter;
	t_matrix	location;
	t_matrix	coord_move;

	t_paint		paint;
}				t_tdparaleg;

typedef struct	s_trg
{
	t_matrix	location;
	t_matrix	coord_move;
	double		corner;
	t_paint		paint;
}				t_trg;

typedef struct	s_entity
{
	void				*ent;
	int					ent_id;
	t_paint				paint;
	struct s_entity		*entity;
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
	unsigned	width;
	unsigned	height;
	unsigned	clarity_coef;

	int			x;
	int			y;

	t_glow		glow;
	t_tdparaleg	tdparaleg_f;
	t_tdparaleg	tdparaleg_s;
	t_tdcircle	tdcircle;
	t_surface	surface_f;
	t_surface	surface_s;
	t_trg		trg;
	t_entity	entities_strg[7];
	t_matrix	multpl_skl;
	t_matrix	neues_anfang;
	t_matrix	s_of_l;
	double		skl;
	Mix_Music	*main_theme;
}				t_env;

int			objects_hinter(t_entity *ent, t_beam *b, t_env *env, double d);
t_beam		determine_sbeam(t_env *env);
t_matrix	optimization_for_tdcircle(t_matrix *start, t_tdcircle *sphere);
int			tdcircle_inter(t_beam *b, void *ent, t_env *env, double bound);
t_matrix	optimization_for_tdparaleg(t_matrix *mtrx, t_tdparaleg *td);
unsigned char		*ft_get_proper(t_env *env);
t_matrix			xyz_rotation(t_env *env, t_matrix *richtung);
t_matrix			optimization_for_trg(t_matrix *mtrx, t_trg *trg);
t_matrix			optimization(t_entity *ent, t_matrix *mtrx, t_matrix *temp);
FILE		*ft_get_file(void);
double		summa_absciss(const double x1, const double x2);
double		summa_apliakta(const double z1, double z2);
t_matrix	summ_matrix(t_matrix *v1, t_matrix *v2);
int			ft_make_printscreen(t_env *env);
void		audio_setup(t_env *env);
void		play_main_theme(t_env *env);
void		ft_build_mtrx(int abs, int ord, int apl, t_matrix *mtrx);
double		ft_calc_ordinates(t_matrix *ziel, t_beam *beam);
double		ft_calc_sordinates(t_trg *trg, t_beam *beam, t_matrix *ziel);
double		ft_calc_absciss(t_beam *beam, bool flag);
t_matrix	trg_math(t_trg *trg, t_beam *beam, t_matrix *ziel);
t_matrix	tdparaleg_math(t_matrix *ziel, t_beam *beam, t_tdparaleg *tdparal);
int			surface_inter(t_beam *b, void *ent, t_env *env, double bound);
t_matrix	optim_settup(t_matrix *mtrx);
double		mult_matrix(t_matrix *v1, t_matrix *v2);
void		ft_init_env(t_env *env, unsigned width, unsigned height);
int			tdcircle_inter(t_beam *b, void *ent, t_env *env, double bound);
t_matrix	optimization_for_surface(t_matrix *lol, t_surface *surface);
void		clean_up(t_env *env);
void		insert_pixel(t_env *env, int x, int y, t_paint *color);
void		ft_init_env(t_env *env, unsigned width, unsigned height);
int			tdcircle_inter(t_beam *b, void *ent, t_env *env, double bound);
t_matrix	optimization_for_surface(t_matrix *lol, t_surface *surface);
void		clean_up(t_env *env);
void		insert_pixel(t_env *env, int x, int y, t_paint *color);
int			display_menu(t_env *env);
int			key_binds(int keycode, t_env *env);
double		angle_calculation_helper(t_matrix *v);
double		calc_angle_matrix(t_matrix *v1, t_matrix *v2);
double		aplikata_substraction(const double z1, double z2);
double		aplikata_multi(const double z1, double z2);
void		ft_init_st(t_env *env, struct jpeg_compress_struct *c, FILE *o);
double		ordinat_substraction(const double y1, const double y2);
t_matrix	aplikata_rotation(t_matrix *dir);
t_matrix	min_matrix(t_matrix *v1, t_matrix *v2);
double		ordinat_multi(const double y1, const double y2);
t_matrix	mult_matx_skl(t_matrix *v, double scale);
void		instantiate_attributes(t_env *env);
void		instantiating_fentity(t_env *env);
void		instantiate_entity(t_matrix *loc, t_matrix *c, int id);
void		depict_entity(t_env *env, int ent, t_matrix *richt);
unsigned	instantiate_div_diameter(int id, t_matrix *loc, t_matrix *coord);
void		instantiate_glow(t_env *env);
void		instantiating_other_entities(int id, t_matrix *loc, t_matrix *coord);
double		get_width_inverse(t_env *env);
double		get_height_inverse(t_env *env);
t_matrix	ordinate_rotation(t_matrix *dir);
void		update_dpaint(t_paint *paint, t_matrix *mtrx, t_matrix *richt);
void		window_setting(double glow, int ent, t_beam *ch_beam, t_env *env);
t_matrix	abscissa_rotation(t_matrix *dir);
int			determine_interacting(t_env *env, double glow_dist, t_beam *beam);
int			trg_interacting(t_beam *beam, t_trg *trg, t_env *env, double bound);
void		process_beam(t_env *env, int entity);
int			tdparaleg_interacting(t_beam *b, t_tdparaleg *tdparal,
				t_env *env, double d);

#endif
