#include "rtv1.h"

t_vector	abscissa_rotation(t_vector *dir, double angle)
{
	t_vector new_dir;

	new_dir.x = dir->x;
	new_dir.y = dir->y * cos(angle * M_PI / 180.0)
		+ dir->z * sin(angle * M_PI / 180.0);
	new_dir.z = dir->z * cos(angle * M_PI / 180.0)
		- dir->y * sin(angle * M_PI / 180.0);
	return (new_dir);
}

t_vector	ordinate_rotation(t_vector *dir, double angle)
{
	t_vector new_dir;

	new_dir.x = dir->x * cos(angle * M_PI / 180.0)
		- dir->z * sin(angle * M_PI / 180.0);
	new_dir.y = dir->y;
	new_dir.z = dir->z * cos(angle * M_PI / 180.0)
		+ dir->x * sin(angle * M_PI / 180.0);
	return (new_dir);
}

t_vector	aplikata_rotation(t_vector *dir, double angle)
{
	t_vector new_dir;

	new_dir.x = dir->x * cos(angle * M_PI / 180.0)
		+ dir->y * sin(angle * M_PI / 180.0);
	new_dir.y = dir->y * cos(angle * M_PI / 180.0)
		- dir->x * sin(angle * M_PI / 180.0);
	new_dir.z = dir->z;
	return (new_dir);
}