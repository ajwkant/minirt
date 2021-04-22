#include "minirt.h"

int		main(int argc, char **argv)
{
	t_scene		scene;
	int			returnvalue;

	if (argc != 2)
		return () // geen juiste argumenten error
	returnvalue = parser(argv[1], &scene);
	//check returnvalue
}

int		main(void)
{
	t_ray *ray;
	t_scene *scene;

	scene = malloc(sizeof(t_scene));
	scene->camera = malloc(sizeof(t_cam));
	scene->camera->place = malloc(sizeof(t_vec3f));
	scene->resolution = malloc(sizeof(t_res));
	scene->resolution->x = 6;
	scene->resolution->y = 6;
	scene->camera->place->x = 0;
	scene->camera->place->y = 0;
	scene->camera->place->z = 0;
	// scene-> sphere maken
	ray = make_camera_ray(4, 2, scene);
	printf("uno: %f, dos: %f, tres: %f\n", ray->place->x, ray->place->y, ray->place->z);
	printf("uno: %f, dos: %f, tres: %f\n", ray->direction->x, ray->direction->y, ray->direction->z);
}
