#include "minirt.h"

// First make the camera always be on the origin
t_ray	make_camera_ray(t_scene scene, int x, int y)
{
	t_ray	ray;

	ray.place = scene.camera.place;
	ray.direction.x = (2 * (((int)x + 0.5) / scene.resolution.x) - 1)
		* scene.resolution.x / scene.resolution.y * (tan(M_PI * scene.camera.fov / 360));
	ray.direction.y = 1 - 2 * (((int)y + 0.5) / scene.resolution.y) * (tan(M_PI * scene.camera.fov / 360));
	ray.direction.z = 1;
	ray.direction = normalize_vector(ray.direction);
	return (ray);
}

t_object	*intersect_object_list(t_scene scene, t_ray ray)
{
	float		distance;
	float		closest;
	t_object	*current;
	t_object	*save_object;

	save_object = NULL;
	closest = INFINITY;
	current = scene.object;
	while (current)
	{
		distance = intersect(ray, current);
		if (distance < closest && distance > 0)
		{
			closest = distance;
			save_object = current;
		}
		current = current->next;
	}
	return (save_object);
}

// Camera verplaatsbaar maken
int		ray_trace(t_scene scene)
{
	int				x;
	int				y;
	t_object		*object;
	t_ray			ray;
	unsigned int	rgb;

	y = 0;
	while (y < scene.resolution.y)
	{
		x = 0;
		while (x < scene.resolution.x)
		{
			ray = make_camera_ray(scene, x, y);
			object = intersect_object_list(scene, ray);
			rgb = 0x000000;
			if (object)
				rgb = compute_shading(scene, ray, object);
			// printf("rgb: %u\n", rgb);
			my_mlx_pixel_put(scene, x, y, rgb);
			x++;
		}
		x = 0;
		y++;
	}
	return (1); // nog goed maken
}
