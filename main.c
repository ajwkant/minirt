#include "minirt.h"

int		scene_init(t_scene *scene)
{
	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (0);
	scene->framebuffer = NULL;
	scene->resolution = NULL;
	scene->ambient = NULL;
	scene->camera = NULL;
	scene->light = NULL;
	scene->object = NULL;
	return (1);
}

void	object_init(t_object *object)
{
	object = malloc(sizeof(t_object));
	if (!object)
		return (0);
	object->sphere = NULL;
	object->plane = NULL;
	object->square = NULL;
	object->cylinder = NULL;
	object->triangle = NULL;
	object->next = NULL;
	return (1);
}

 int		main(int argc, char **argv)
{
	t_scene		scene;
	int			returnvalue;

	if (argc != 2)
		return (-1); // geen juiste argumenten error
	if (!scene_init(&scene))
		return (-1); // error
	returnvalue = parser(argv[1], &scene);
	//check returnvalue

}

// int		main(void)
// {
// 	t_ray *ray;
// 	t_scene *scene;

// 	if (!scene_init(scene))
// 		return (-1); // error
// 	scene->camera = malloc(sizeof(t_cam));
// 	scene->camera->place = malloc(sizeof(t_vec3f));
// 	scene->resolution = malloc(sizeof(t_res));
// 	scene->resolution->x = 6;
// 	scene->resolution->y = 6;
// 	scene->camera->place->x = 0;
// 	scene->camera->place->y = 0;
// 	scene->camera->place->z = 0;
// 	// if (!object_init(scene->object))
// 	// 	return (-1); // error





// 	// ray = make_camera_ray(4, 2, scene);
// 	// printf("uno: %f, dos: %f, tres: %f\n", ray->place->x, ray->place->y, ray->place->z);
// 	// printf("uno: %f, dos: %f, tres: %f\n", ray->direction->x, ray->direction->y, ray->direction->z);
// }
