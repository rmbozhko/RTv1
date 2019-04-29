#include "rtv1.h"

t_matrix	abscissa_rotation(t_matrix *dir, double angle)
{
	t_matrix new_dir;

	new_dir.ab = dir->ab;
	new_dir.ord = dir->ord * cos(angle * M_PI / 180.0)
		+ dir->apl * sin(angle * M_PI / 180.0);
	new_dir.apl = dir->apl * cos(angle * M_PI / 180.0)
		- dir->ord * sin(angle * M_PI / 180.0);
	return (new_dir);
}

t_matrix	ordinate_rotation(t_matrix *dir, double angle)
{
	t_matrix new_dir;

	new_dir.ab = dir->ab * cos(angle * M_PI / 180.0)
		- dir->apl * sin(angle * M_PI / 180.0);
	new_dir.ord = dir->ord;
	new_dir.apl = dir->apl * cos(angle * M_PI / 180.0)
		+ dir->ab * sin(angle * M_PI / 180.0);
	return (new_dir);
}

t_matrix	aplikata_rotation(t_matrix *dir, double angle)
{
	t_matrix new_dir;

	new_dir.ab = dir->ab * cos(angle * M_PI / 180.0)
		+ dir->ord * sin(angle * M_PI / 180.0);
	new_dir.ord = dir->ord * cos(angle * M_PI / 180.0)
		- dir->ab * sin(angle * M_PI / 180.0);
	new_dir.apl = dir->apl;
	return (new_dir);
}