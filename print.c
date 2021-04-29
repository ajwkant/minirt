#include "minirt.h"

void	rgbprint(t_rgb *rgb)
{
	printf("r: %d, g: %d, b: %d\n", rgb->r, rgb->g, rgb->b);
}

void	printvec3f(t_vec3f *vec)
{
	printf("x: %f, y: %f, z: %f\n", vec->x, vec->y, vec->z);
}

void	printobject(t_object *object) // alle andere objecten nog toevoegen
{
	if (object->sphere)
	{
		printf("sphere place: ");
		printvec3f(object->sphere->place);
		printf("sphere dia: %f\n", object->sphere->dia);
		rgbprint(object->sphere->rgb);
	}
}

void	printscene(t_scene scene) // tot nu toe print ie alleen spheres
{
	int i;

	i = 0;
	if (scene.resolution)
		printf("res: x: %d,y: %d\n\n", scene.resolution->x, scene.resolution->y);
	if (scene.ambient)
	{
		printf("ambient ratio: %f\n", scene.ambient->ratio);
		rgbprint(scene.ambient->rgb);
		printf("\n");
	}
	while (scene.camera)
	{
		printf("cam: place, direction, fov\n");
		printvec3f(scene.camera->place);
		printvec3f(scene.camera->direction);
		printf("fov: %d\n\n", scene.camera->fov);
		scene.camera = scene.camera->next;
	}
	while (scene.light)
	{
		printf("light: place, brightness, rgb\n");
		printvec3f(scene.light->place);
		printf("brightness: %f\n", scene.light->brightness);
		rgbprint(scene.light->rgb);
		printf("\n");
		scene.light = scene.light->next;
	}
	while (scene.object)
	{
		printobject(scene.object);
		scene.object = scene.object->next;
	}
}