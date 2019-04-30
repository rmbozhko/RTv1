#include "rtv1.h"

t_matrix	abscissa_rotation(t_matrix *dir)
{
	t_matrix new_dir;

	new_dir.ab = dir->ab;
	new_dir.ord = dir->ord;
	new_dir.apl = dir->apl;
	return (new_dir);
}

t_matrix	ordinate_rotation(t_matrix *dir)
{
	t_matrix new_dir;

	new_dir.ab = dir->ab;
	new_dir.ord = dir->ord;
	new_dir.apl = dir->apl;
	return (new_dir);
}

t_matrix	aplikata_rotation(t_matrix *dir)
{
	t_matrix new_dir;

	new_dir.ab = dir->ab;
	new_dir.ord = dir->ord;
	new_dir.apl = dir->apl;
	return (new_dir);
}