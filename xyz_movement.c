#include "rtv1.h"

t_matrix	abscissa_rotation(t_matrix *dir)
{
	t_matrix new_dir;

	new_dir.ab = dir->ab;
	new_dir.ord = dir->ord * cos(0) + dir->apl * sin(0);
	new_dir.apl = dir->apl * cos(0) - dir->ord * sin(0);
	return (new_dir);
}

t_matrix	ordinate_rotation(t_matrix *dir)
{
	t_matrix new_dir;

	new_dir.ab = dir->ab * cos(0) - dir->apl * sin(0);
	new_dir.ord = dir->ord;
	new_dir.apl = dir->apl * cos(0) + dir->ab * sin(0);
	return (new_dir);
}

t_matrix	aplikata_rotation(t_matrix *dir)
{
	t_matrix new_dir;

	new_dir.ab = dir->ab * cos(0) + dir->ord * sin(0);
	new_dir.ord = dir->ord * cos(0)	- dir->ab * sin(0);
	new_dir.apl = dir->apl;
	return (new_dir);
}