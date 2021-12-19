#include "minirt.h"

t_vec3f	find_sphere_normal(t_sphere sphere, t_vec3f int_point)
{
	t_vec3f	result;

	result.x = int_point.x - sphere.place.x;
	result.y =	int_point.y - sphere.place.y;
	result.z = int_point.z - sphere.place.z;
	result = normalize_vector(result);
	return (result);
}

t_vec3f	find_normal_at_point(t_object *object, t_vec3f intersection_point)
{
	t_vec3f	temp;

	temp = vec3f_init();
	if (object->is_sphere)
		return(find_sphere_normal(object->sphere, intersection_point));
	if (object->is_plane)
	{
		temp = normalize_vector(object->plane.direction);
		return (temp);
	}
	// if (object->square)
	// 	normal = find_square_normal(object->square, int_point);
	// if (object->cylinder)
	// 	normal = find_cylinder_normal(object->cylinder, int_point);
	// if (object->triangle)
	// 	normal = find_triangle_normal(object->triangle, int_point);
	return (temp);
}
