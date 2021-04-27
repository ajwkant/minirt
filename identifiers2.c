#include "minirt.h"

int		planeid(t_scene *scene, char *str)
{
	int			i;
	t_object	*object;
	t_plane		*plane;

	i = 0;
	object = object_init();
	if (object)
		return (-1); // error
	add_last_object(scene, object);
	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (-1);
	plane->place->x = readfloat(str, &i, ' ');
	plane->place->y = readfloat(str, &i, ',');
	plane->place->z = readfloat(str, &i, ',');
	plane->direction->x = readfloat(str, &i, ' ');
	plane->direction->y = readfloat(str, &i, ',');
	plane->direction->z = readfloat(str, &i, ',');
	plane->rgb->r = readint(str, &i, ' ');
	plane->rgb->g = readint(str, &i, ',');
	plane->rgb->b = readint(str, &i, ',');
	object->plane = plane;
	return (1);
}

int		squareid(t_scene *scene, char *str)
{
	int			i;
	t_object	*object;
	t_square	*square;

	i = 0;
	object = object_init();
	if (object)
		return (-1); // error
	add_last_object(scene, object);
	square = malloc(sizeof(t_square));
	if (!square)
		return (-1);
	square->place->x = readfloat(str, &i, ' ');
	square->place->y = readfloat(str, &i, ',');
	square->place->z = readfloat(str, &i, ',');
	square->direction->x = readfloat(str, &i, ' ');
	square->direction->y = readfloat(str, &i, ',');
	square->direction->z = readfloat(str, &i, ',');
	square->size = readfloat(str, &i, ' ');
	square->rgb->r = readint(str, &i, ' ');
	square->rgb->g = readint(str, &i, ',');
	square->rgb->b = readint(str, &i, ',');
	object->square = square;
	return (1);
}

int		cylinderid(t_scene *scene, char *str)
{
	int			i;
	t_object	*object;
	t_cylinder	*cylinder;

	i = 0;
	object = object_init();
	if (object)
		return (-1); // error
	add_last_object(scene, object);
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (-1);
	cylinder->place->x = readfloat(str, &i, ' ');
	cylinder->place->y = readfloat(str, &i, ',');
	cylinder->place->z = readfloat(str, &i, ',');
	cylinder->direction->x = readfloat(str, &i, ' ');
	cylinder->direction->y = readfloat(str, &i, ',');
	cylinder->direction->z = readfloat(str, &i, ',');
	cylinder->diam = readfloat(str, &i, ' ');
	cylinder->height = readfloat(str, &i, ' ');
	cylinder->rgb->r = readint(str, &i, ' ');
	cylinder->rgb->g = readint(str, &i, ',');
	cylinder->rgb->b = readint(str, &i, ',');
	object->cylinder = cylinder;
	return (1);
}

int		triangleid(t_scene *scene, char *str)
{
	int			i;
	t_object	*object;
	t_triangle	*triangle;

	i = 0;
	object = object_init();
	if (object)
		return (-1); // error
	add_last_object(scene, object);
	triangle = malloc(sizeof(t_triangle));
	if (!triangle)
		return (-1);
	triangle->p1->x = readfloat(str, &i, ' ');
	triangle->p1->y = readfloat(str, &i, ',');
	triangle->p1->z = readfloat(str, &i, ',');
	triangle->p2->x = readfloat(str, &i, ' ');
	triangle->p2->y = readfloat(str, &i, ',');
	triangle->p2->z = readfloat(str, &i, ',');
	triangle->p3->x = readfloat(str, &i, ' ');
	triangle->p3->y = readfloat(str, &i, ',');
	triangle->p3->z = readfloat(str, &i, ',');
	triangle->rgb->r = readint(str, &i, ' ');
	triangle->rgb->g = readint(str, &i, ',');
	triangle->rgb->b = readint(str, &i, ',');
	object->triangle = triangle;
	return (1);
}
