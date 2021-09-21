#include "minirt.h"

t_ray	*make_light_ray(t_scene *scene, t_vec3f *int_point) // aanpassen voor meerdere lichten
{
	t_ray	*ray;
	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->direction = malloc(sizeof(t_vec3f));
	if (!ray->direction)
		return (NULL);
	ray->place = scene->light->place;
	ray->direction->x = int_point->x - scene->light->place->x;
	ray->direction->y = int_point->y - scene->light->place->y;
	ray->direction->z = int_point->z - scene->light->place->z;
	normalize_vector(ray->direction);;
	return (ray);
}

t_ray	*light_ray_distance(t_scene *scene, t_vec3f *int_point, float *distance)
{
	t_ray	*lightray;

	lightray = make_light_ray(scene, int_point);
	intersect_object_list(scene, distance, lightray); // andere intersect functie maken die na het eerste object dat het raakt al returnt als "object in de weg"
	return (lightray);
}

t_ray	*light_reaches_point(t_scene *scene, t_ray *ray, float distance, t_vec3f *int_point)
{
	t_ray	*lightray;
	float	dist_light_int_point;

	int_point = find_coordinates(ray, distance);
	if (!int_point)
		return (NULL);
	lightray = light_ray_distance(scene, int_point, &dist_light_int_point);
	if (distance - dist_light_int_point < 0.00001 ||
		distance - dist_light_int_point > -0.00001)
		return (lightray);
	return (NULL);
}

// Functie moet nog meerdere lichten aankunnen
unsigned int	compute_shading(t_scene *scene, t_ray *ray, float distance, t_object *object)
{
	t_ray	*lightray;
	t_vec3f	int_point;
	t_vec3f	*normal;
	float	facing_ratio;
	t_rgb	*rgb_vec;
	// for (elk licht) loopje maken

	lightray = light_reaches_point(scene, ray, distance, &int_point);
	// printvec3f(lightray->direction);
	normal = find_normal_at_point(object, &int_point);
	facing_ratio = dotproduct(lightray->direction, normal);
	// printf("facing ratio: %f\n", facing_ratio);
	if (facing_ratio < 0)
		facing_ratio *= -1;
	// rgbprint(object->sphere->rgb);
	rgb_vec = get_rgb(object);
	// rgbprint(rgb_vec);
	return (make_rgb(rgb_vec, facing_ratio));

	// rgb_ratio(rgb_vec, facing_ratio);
	// return (make_rgb(*rgb_vec));
}
