#include "minirt.h"

int		planeid(t_scene *scene, char *str)
{
	int			i;
	t_object	*object;

	i = 0;
	last_object(scene)->next = object;
	if (!object_init(object))
		return (-1); // error
	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (-1);
	plane->x = readfloat(str, &i, ' ');
	plane->y = readfloat(str, &i, ',');
	plane->z = readfloat(str, &i, ',');
	plane->vx = readfloat(str, &i, ' ');
	plane->vy = readfloat(str, &i, ',');
	plane->vz = readfloat(str, &i, ',');
	plane->r = readint(str, &i, ' ');
	plane->g = readint(str, &i, ',');
	plane->b = readint(str, &i, ','):
	object->plane = plane;
	return (1);
}

int		squareid(t_square *square, char *str)
{
	int			i;
	t_object	*object;

	i = 0;
	last_object(scene)->next = object;
	if (!object_init(object))
		return (-1); // error
	square = malloc(sizeof(t_square));
	if (!square)
		return (-1);
	square->x = readfloat(str, &i, ' ');
	square->y = readfloat(str, &i, ',');
	square->z = readfloat(str, &i, ',');
	square->vx = readfloat(str, &i, ' ');
	square->vy = readfloat(str, &i, ',');
	square->vz = readfloat(str, &i, ',');
	square->size = readfloat(str, &i, ' ');
	square->r = readint(str, &i, ' ');
	square->g = readint(str, &i, ',');
	square->b = readint(str, &i, ','):
	object->square = square;
	return (1);
}

int		cylinderid(t_cylinder *cylinder, char *str)
{
	int			i;
	t_object	*object;

	i = 0;
	last_object(scene)->next = object;
	if (!object_init(object))
		return (-1); // error
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (-1);
	cylinder->x = readfloat(str, &i, ' ');
	cylinder->y = readfloat(str, &i, ',');
	cylinder->z = readfloat(str, &i, ',');
	cylinder->vx = readfloat(str, &i, ' ');
	cylinder->vy = readfloat(str, &i, ',');
	cylinder->vz = readfloat(str, &i, ',');
	cylinder->diam = readfloat(str, &i, ' ');
	cylinder->height = readfloat(str, &i, ' ');
	cylinder->r = readint(str, &i, ' ');
	cylinder->g = readint(str, &i, ',');
	cylinder->b = readint(str, &i, ','):
	object->cylinder = cylinder;
	return (1);
}

int		triangleid(t_triangle *triangle, char *str)
{
	int			i;
	t_object	*object;

	i = 0;
	last_object(scene)->next = object;
	if (!object_init(object))
		return (-1); // error
	triangle = malloc(sizeof(t_triangle));
	if (!triangle)
		return (-1);
	triangle->x1 = readfloat(str, &i, ' ');
	triangle->y1 = readfloat(str, &i, ',');
	triangle->z1 = readfloat(str, &i, ',');
	triangle->x2 = readfloat(str, &i, ' ');
	triangle->y2 = readfloat(str, &i, ',');
	triangle->z2 = readfloat(str, &i, ',');
	triangle->x3 = readfloat(str, &i, ' ');
	triangle->y3 = readfloat(str, &i, ',');
	triangle->z3 = readfloat(str, &i, ',');
	triangle->r = readint(str, &i, ' ');
	triangle->g = readint(str, &i, ',');
	triangle->b = readint(str, &i, ','):
	object->triangle = triangle;
	return (1);
}
