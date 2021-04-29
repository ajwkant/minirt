#include "minirt.h"

t_scene		scene_init(void)
{
	t_scene scene;

	scene.framebuffer = NULL;
	scene.resolution = NULL;
	scene.ambient = NULL;
	scene.camera = NULL;
	scene.light = NULL;
	scene.object = NULL;
	return (scene);
}

t_object	*object_init(void)
{
	t_object *object;

	object = malloc(sizeof(t_object));
	if (!object)
		return (NULL);
	object->sphere = NULL;
	object->plane = NULL;
	object->square = NULL;
	object->cylinder = NULL;
	object->triangle = NULL;
	object->next = NULL;
	return (object);
}
