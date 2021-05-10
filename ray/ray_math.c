#include "minirt.h"

t_vec3f	*vector_deduction(t_vec3f *a, t_vec3f *b)
{
	t_vec3f	*result;
	result = malloc(sizeof(t_vec3f));
	if (!result)
		return (NULL);
	result->x = a->x - b->x;
	result->y = a->y - b->y;
	result->z = a->z - b->z;
	return (result);
}

float	dotproduct(t_vec3f *a, t_vec3f *b)
{
	return (a->x * b->x + a->y * b->y +  a->z * b->z);
}

void	normalize_vector(t_vec3f *direction)
{
	float dlen;

	// printf("uno: %f, dos: %f, tres: %f\n", direction->x, direction->y, direction->z);
	dlen = hypot(hypot(direction->x, direction->y), direction->z);
	// printf("dlen: %f\n", dlen);
	direction->x /= dlen;
	direction->y /= dlen;
	direction->z /= dlen;
}

t_vec3f	*find_coordinates(t_ray *ray, float distance)
{
	t_vec3f	*result;
	result = malloc(sizeof(t_vec3f));
	if (!result)
		return (NULL);
	result->x = ray->place->x + ray->direction->x * distance;
	result->y = ray->place->y + ray->direction->y * distance;
	result->z = ray->place->z + ray->direction->z * distance;
	return (result);
}
