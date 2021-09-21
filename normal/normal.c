#include "minirt.h"

t_vec3f	*find_sphere_normal(t_sphere *sphere, t_vec3f *int_point)
{
	t_vec3f	*result;
	result = malloc(sizeof(t_vec3f));
	if (!result)
		return (NULL);
	result->x = int_point->x - sphere->place->x;
	result->y =	int_point->y - sphere->place->y;
	result->z = int_point->z - sphere->place->z;
	normalize_vector(result);
	return (result);
}

t_vec3f	*find_normal_at_point(t_object *object, t_vec3f *int_point)
{
	t_vec3f	*normal;

	normal = NULL;
	if (object->sphere)
		normal = find_sphere_normal(object->sphere, int_point);
	if (object->plane)
		normal = find_plane_normal(object->plane, int_point);
	// if (object->square)
	// 	normal = find_square_normal(object->square, int_point);
	// if (object->cylinder)
	// 	normal = find_cylinder_normal(object->cylinder, int_point);
	// if (object->triangle)
	// 	normal = find_triangle_normal(object->triangle, int_point);
	return (normal);
}
