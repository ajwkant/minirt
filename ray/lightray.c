#include "minirt.h"

t_ray	make_light_ray(t_scene scene, t_vec3f intersection_point) // aanpassen voor meerdere lichten
{
	t_ray	ray;

	ray = ray_init();
	ray.place = scene.light->place;
	ray.direction.x = intersection_point.x - scene.light->place.x;
	ray.direction.y = intersection_point.y - scene.light->place.y;
	ray.direction.z = intersection_point.z - scene.light->place.z;
	ray.direction = normalize_vector(ray.direction);
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
	if (!closest_object) // hij mist elk object.. hoort niet denk ik
		return (0); // cheatfix voor nu, hij mist elk object terwijl hij
		// het intersect object wel hoort te raken.. nu als ie alles mist
		// raakt hij iig geen object in de weg.

	distance_to_object = intersect(lightray, object);
	distance_to_closest = intersect(lightray, closest_object);
	if (distance_to_closest - distance_to_object < -0.001
		|| distance_to_closest - distance_to_object > 0.001)
		return (1);
	return (0);
}

// Functie moet nog meerdere lichten aankunnen
unsigned int	compute_shading(t_scene scene, t_ray ray, t_object *object)
{
	t_ray	lightray;
	t_vec3f	intersection_point;
	t_vec3f	normal;
	float	facing_ratio;
	t_rgb	rgb_vec;
	float	cam_obj_dist;
	// for (elk licht) loopje maken

	cam_obj_dist = intersect(ray, object);
	intersection_point = find_coordinates(ray, cam_obj_dist);

	if (light_gets_blocked(scene, object, intersection_point))
		return (0x000000);

	lightray = make_light_ray(scene, intersection_point);
	normal = find_normal_at_point(object, intersection_point); // check of het een valid normal is
	facing_ratio = dotproduct(lightray.direction, normal);
	// printf("facing ratio: %f\n", facing_ratio);
	if (facing_ratio < 0)
		facing_ratio *= -1;
	// rgbprint(object->sphere->rgb);
	rgb_vec = get_rgb(object);
	// rgbprint(rgb_vec);
	// rgbprint(rgb_vec);
	// printf("ratio: %f\n", facing_ratio);
	return (make_rgb(rgb_vec, facing_ratio));

	// rgb_ratio(rgb_vec, facing_ratio);
	// return (make_rgb(*rgb_vec));
}
