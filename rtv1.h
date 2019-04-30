#ifndef RTV1_H
# define RTV1_H

# include <stdlib.h>
# include <stdio.h> 
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

# define SPHERE 1
# define CYLINDER 2
# define CONUS 3
# define PLANE 4

# define SQ(X) mult_matrix(X, X)
# define X env->x
# define Y env->y

# define FOV 60
# define ASP_RATIO (env->width / (double)env->height)
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
	void				*ent; //entity
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


void		ft_init_env(t_env *env, unsigned widht, unsigned height);

void		instantiating_fentity(t_env *env);
void		instantiating_sentity(t_env *env);
void		instantiating_tentity(t_env *env);
void		insert_pixel(t_env *env, int x, int y, t_paint *color);
int			objects_hinteracting(t_entity *obj, t_beam *ray,
						t_env *env, double d);

t_matrix	abscissa_rotation(t_matrix *dir);
t_matrix	ordinate_rotation(t_matrix *dir);
t_matrix	aplikata_rotation(t_matrix *dir);
t_matrix	rotate(t_matrix *v, double alpha, double beta, double gamma);

t_matrix	min_matrix(t_matrix *v1, t_matrix *v2);
t_matrix	mult_matx_skl(t_matrix *v, double scale);
t_matrix	summ_matrix(t_matrix *v1, t_matrix *v2);
t_matrix	optim_settup(t_matrix *vector);
double		mult_matrix(t_matrix *v1, t_matrix *v2);

t_matrix	optimization(t_entity *obj, t_matrix *start, t_matrix *lil);

void		window_setting(double glow_dist, int cur_obj, t_beam *ch_beam,
				t_env *env);

double		calc_angle_matrix(t_matrix *v1, t_matrix *v2);

t_matrix	trg_math(t_beam *ray, t_trg *cone, t_matrix *dist);
t_matrix	tdrect_math(t_beam *ray, t_tdparaleg *cyl, t_matrix *dist);
t_matrix	xyz_rotation(t_matrix *v, t_env *env);
void		depict_entity(t_env *env, int cur_obj, t_matrix *dir);

int			determine_interacting(t_env *env, t_beam *ray, double light_d);
t_beam		determine_sbeam(t_env *env);
void		process_beam(t_env *env, int cho_entity);

FILE			*ft_get_file(void);
void			ft_init_st(t_env *env, struct jpeg_compress_struct *c, FILE *o);
unsigned char	*ft_get_proper(t_env *env);
int				ft_make_printscreen(t_env *env);

void			clean_up(t_env *env);
void			play_main_theme(t_env *env);
void			audio_setup(t_env *env);

#endif
