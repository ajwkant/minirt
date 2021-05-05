#include "minirt.h"

void	normalize_direction_vector(t_vec3f *direction)
{
	float dlen;

	// printf("uno: %f, dos: %f, tres: %f\n", direction->x, direction->y, direction->z);
	dlen = hypot(hypot(direction->x, direction->x), direction->z);
	// printf("dlen: %f\n", dlen);
	direction->x /= dlen;
	direction->y /= dlen;
	direction->z /= dlen;
}

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
	normalize_direction_vector(ray->direction);
	return (ray);
}

// Camera verplaatsbaar maken
int		ray_trace(t_scene *scene)
{
	int		x;
	int		y;
	float		closest_obj;
	float		distance;
	t_object	*current;
	unsigned int	rgb;
	t_ray	*ray;

	y = 0;
	while (y < scene->resolution->y)
	{
		x = 0;
		while (x < scene->resolution->x)
		{
			closest_obj = INFINITY;
			distance = INFINITY;
			ray = make_camera_ray(x, y, scene);
			current = scene->object;
			while (current)
			{
				distance = intersect(ray, current->sphere); // voorlopig sphere
				if (distance < closest_obj && distance > 0)
				{
					closest_obj = distance;
					rgb = make_rgb(*(current->sphere->rgb));
				}
				current = current->next;
			}
			if (closest_obj < INFINITY)
				my_mlx_pixel_put(scene, x, y, rgb);
			else
				my_mlx_pixel_put(scene, x, y, 0x000000);
			x++;
			freeray(ray);
		}
		x = 0;
		y++;
	}
	return (1); // nog goed maken
}
