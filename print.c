#include "minirt.h"

void	rgbprint(t_rgb rgb)
{
	printf("r: %d, g: %d, b: %d\n", rgb.r, rgb.g, rgb.b);
}

void	printvec3f(t_vec3f vec)
{
	printf("x: %f, y: %f, z: %f\n", vec.x, vec.y, vec.z);
}

void	printobject(t_object object) // alle andere objecten nog toevoegen
{
	if (object.sphere)
	{
		printf("sphere place: ");
		printvec3f(object.sphere->place);
		printf("sphere dia: %f\n", object.sphere->dia);
		rgbprint(object.sphere->rgb);
	}
}

void	printscene(t_scene scene)
{
	if (scene.resolution)
		printf("res: x: %d,y: %d\n", scene.resolution->x, scene.resolution->y);
	if (scene.ambient)
	{
		printf("ambient ratio: %f\n", scene.ambient->ratio);
		rgbprint(scene.ambient->rgb);
	}
	// while (scene->camera)
	// 	printf("cam: x: %f,y: %f\n", scene->->x, scene->r->y);
	// light moet nog
	while (scene.object)
	{
		printobject(*scene.object);
		scene.object = scene.object->next;
	}
}