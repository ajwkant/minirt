#include "minirt.h"

t_ray	make_light_ray(t_scene scene, t_vec3f intersection_point) // aanpassen voor meerdere lichten
{
	t_ray	ray;

	ray = ray_init();
	ray.place = scene.light->place;
	ray.direction.x = intersection_point.x - scene.light->place.x;
	ray.direction.y = intersection_point.y - scene.light->place.y;
	ray.direction.z = intersection_point.z - scene.light->place.z;
	printf("light direction: \n");
	printvec3f(ray.direction);
	ray.direction = normalize_vector(ray.direction);
	printf("light direction: \n");
	printvec3f(ray.direction);
	return (ray);
}

int	light_gets_blocked(t_scene scene, t_object *object, t_vec3f intersection_point)
{
	t_ray		lightray;
	t_object	*closest_object;
	float		distance_to_object;
	float		distance_to_closest;

	// write(1, "A\n", 2);

	lightray = make_light_ray(scene, intersection_point);
	// write(1, "B\n", 2);
	printf("inside the lgb function\n");
	printvec3f(intersection_point);
	closest_object = intersect_object_list(scene, lightray);
	if (!closest_object) // hij mist elk object.. hoort niet denk ik
		write(1, "C\n", 2);

	distance_to_object = intersect(lightray, object);
	write(1, "D\n", 2);

	distance_to_closest = intersect(lightray, closest_object);
	write(1, "E\n", 2);

	// printvec3f(lightray.place);
	// printvec3f(object->sphere.place);
	// printf("distance light object : %f\n", distance_to_object);

	// printf("distance light object : %f\ndistance light closest: %f\n", distance_to_object, distance_to_closest);
	// write(1, "Light distance print\n", ft_strlen("Light distance print\n"));
	// printf("distance light object : %f\ndistance light closest: %f\n", object->sphere.place.x, closest_object->sphere.place.x);
	if (distance_to_closest - distance_to_object < -0.01
		|| distance_to_closest - distance_to_object > 0.01)
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
	printvec3f(intersection_point);

	if (light_gets_blocked(scene, object, intersection_point))
		return (0); // return darkness, it's in the shadow



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
