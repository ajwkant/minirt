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
		* scene->resolution->x / scene->resolution->y * (tan(M_PI * scene->camera->vof / 360));
	ray->direction->y = 1 - 2 * (((int)y + 0.5) / scene->resolution->y) * (tan(M_PI * scene->camera->vof / 360));
	ray->direction->z = 1;
	normalize_direction_vector(ray->direction);
	return (ray);
}



// moet je elke framebuffer malloccen?
// functie maken die door alle objects heen loopt voor objects
// Camera verplaatsbaar maken
ray_trace(t_scene *scene)
{
	int		x;
	int		y;
	int		obj;
	int		closest_obj;
	int		distance;

	t_ray	*ray;

	scene->framebuffer = malloc(sizeof(scene->resolution->x * scene->resolution->y));
	if (!scene->framebuffer)
		return (); // fout
	y = 0;
	while (y < scene->resolution->y)
	{
		x = 0;
		while (x < scene->resolution->x)
		{
			obj = 0;
			closest_obj = 100000;
			ray = make_camera_ray(x, y, scene);
			while (objects[obj])
			{
				distance = intersect(ray, sphere);  //, objects[obj]); // objects maken, voorlopig 1 sphere
				if (distance < closest_obj)
				{
					closest_obj = distance;
					framebuffer[y * scene->width + x] = color(objects[obj].color);
				}
				obj++;
			}
			x++;
		}
		y++;
	}
}

