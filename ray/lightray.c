#include "minirt.h"

t_ray	make_light_ray(t_scene scene, t_vec3f int_point) // aanpassen voor meerdere lichten
{
	t_ray	ray;

	ray = ray_init();
	ray.place = scene.light->place;
	ray.direction.x = int_point.x - scene.light->place.x;
	ray.direction.y = int_point.y - scene.light->place.y;
	ray.direction.z = int_point.z - scene.light->place.z;
	normalize_vector(ray.direction);
	return (ray);
}

int	light_gets_blocked(t_scene scene, t_object *object, t_vec3f intersection_point)
{
	t_ray		lightray;
	t_object	*closest_object;
	float		distance_to_object;
	float		distance_to_closest;

	lightray = make_light_ray(scene, intersection_point);
	closest_object = intersect_object_list(scene, lightray);
	distance_to_object = intersect(lightray, object);
	distance_to_closest = intersect(lightray, closest_object);
	if (distance_to_closest - distance_to_object < -0.0001
		|| distance_to_closest - distance_to_object > 0.0001)
		return (1);
	return (0);
}

// Functie moet nog meerdere lichten aankunnen
unsigned int	compute_shading(t_scene scene, t_ray ray, float cam_obj_dist, t_object *object)
{
	t_ray	lightray;
	t_vec3f	intersection_point;
	t_vec3f	normal;
	float	facing_ratio;
	t_rgb	rgb_vec;
	// for (elk licht) loopje maken

	intersection_point = find_coordinates(ray, cam_obj_dist);
	if (light_gets_blocked(scene, object, intersection_point))
		return () // return darkness, it's in the shadow

	normal = find_normal_at_point(object, intersection_point); // check of het een valid normal is
	facing_ratio = dotproduct(lightray.direction, normal);
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
