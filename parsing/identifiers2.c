#include "minirt.h"

int		planeid(t_scene *scene, char *str)
{
	int			i;
	t_object	*object;
	t_plane		plane;

	i = 0;
	object = object_init();
	object->is_plane = 1;
	plane.place = vec_reader(str, &i);
	plane.direction = vec_reader(str, &i);
	plane.rgb = rgb_reader(str, &i);
	object->plane = plane;
	normalize_vector(plane.direction);
	add_last_object(scene, object);
	return (1);
}

// int		squareid(t_scene *scene, char *str)
// {
// 	int			i;
// 	t_object	*object;
// 	t_square	*square;

// 	square = malloc(sizeof(t_square));
// 	if (!square)
// 		return (-1);
// 	i = 0;
// 	object = object_init();
// 	square->place = vec_reader(str, &i);
// 	square->direction = vec_reader(str, &i);
// 	square->rgb = rgb_reader(str, &i);
// 	square->size = readfloat(str, &i, ' ');
// 	object->square = square;
// 	add_last_object(scene, object);
// 	return (1);
// }

int		cylinderid(t_scene *scene, char *str)
{
	int			i;
	t_object	*object;
	t_cylinder	cylinder;

	i = 0;
	object = object_init();
	object->is_cylinder = 1;
	cylinder.place = vec_reader(str, &i);
	cylinder.direction = vec_reader(str, &i);
	cylinder.diam = readfloat(str, &i, ' ');
	cylinder.height = readfloat(str, &i, ' ');
	cylinder.rgb = rgb_reader(str, &i);
	object->cylinder = cylinder;
	add_last_object(scene, object);
	return (1);
}

// int		triangleid(t_scene *scene, char *str)
// {
// 	int			i;
// 	t_object	*object;
// 	t_triangle	*triangle;

// 	triangle = malloc(sizeof(t_triangle));
// 	if (!triangle)
// 		return (-1);
// 	i = 0;
// 	object = object_init();
// 	triangle->p1 = vec_reader(str, &i);
// 	triangle->p2 = vec_reader(str, &i);
// 	triangle->p3 = vec_reader(str, &i);
// 	triangle->rgb = rgb_reader(str, &i);
// 	object->triangle = triangle;
// 	add_last_object(scene, object);
// 	return (1);
// }
