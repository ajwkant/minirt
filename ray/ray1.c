#include "minirt.h"

void	freeray(t_ray *ray)
{
	free(ray->direction);
	free(ray);
}

// First make the camera always be on the origin
t_ray	*make_camera_ray(int x, int y, t_scene *scene)
{
	t_ray	*ray;
	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->direction = malloc(sizeof(t_vec3f));
	if (!ray->direction)
		return (NULL);
	ray->place = scene->camera->place;
	ray->direction->x = (2 * (((int)x + 0.5) / scene->resolution->x) - 1)
		* scene->resolution->x / scene->resolution->y * (tan(M_PI * scene->camera->fov / 360));
	ray->direction->y = 1 - 2 * (((int)y + 0.5) / scene->resolution->y) * (tan(M_PI * scene->camera->fov / 360));
	ray->direction->z = 1;
	normalize_vector(ray->direction);
	return (ray);
}

t_object	*intersect_object_list(t_scene *scene, float *closest, t_ray *ray)
{
	float		distance;
	t_object	*current;
	// unsigned int	rgb;
	t_object	*save_object;

	save_object = NULL;
	distance = INFINITY;
	current = scene->object;
	while (current)
	{
		distance = intersect(ray, current);
		if (distance < *closest && distance > 0)
		{
			*closest = distance;
			save_object = current;
		}
		current = current->next;
	}
	return (save_object);
}

// Camera verplaatsbaar maken
int		ray_trace(t_scene *scene)
{
	int		x;
	int		y;
	t_object	*object;
	float		distance;
	t_ray		*ray;
	unsigned int rgb;

	y = 0;
	while (y < scene->resolution->y)
	{
		x = 0;
		while (x < scene->resolution->x)
		{
			write(1, "A\n", 2);
			distance = INFINITY;
			ray = make_camera_ray(x, y, scene);
			write(1, "B\n", 2);
			object = intersect_object_list(scene, &distance, ray); // check argumenten
			write(1, "C\n", 2);
			rgb = 0x000000;
			if (distance < INFINITY)
				rgb = compute_shading(scene, ray, distance, object);
			freeray(ray);
			write(1, "D\n", 2);
			my_mlx_pixel_put(scene, x, y, rgb);
			x++;
		}
		x = 0;
		y++;
	}
	return (1); // nog goed maken
}
