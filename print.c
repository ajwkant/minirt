#include "minirt.h"

void	rgbprint(t_rgb rgb)
{
	printf("r: %d, g: %d, b: %d\n", rgb.r, rgb.g, rgb.b);
}

void	printvec3f(t_vec3f vec)
{
	printf("x: %f, y: %f, z: %f\n", vec.x, vec.y, vec.z);
}

void	printobject(t_object *object) // alle andere objecten nog toevoegen
{
	if (object->is_sphere)
	{
		printf("\nsphere: \n");
		printf("sphere place: ");
		printvec3f(object->sphere.place);
		printf("sphere dia: %f\n", object->sphere.dia);
		printf("sphere rgb: ");
		rgbprint(object->sphere.rgb);
	}
	if (object->is_plane)
	{
		printf("\nplane: \n");
		printf("plane place: ");
		printvec3f(object->plane.place);
		printf("plane direction: ");
		printvec3f(object->plane.direction);
		printf("Plane rgb: ");
		rgbprint(object->plane.rgb);
	}
}

void	printscene(t_scene scene) // tot nu toe print ie alleen spheres
{
	int i;

	i = 0;
	if (scene.amb_is_set)
	{
		printf("ambient ratio: %f\n", scene.ambient.ratio);
		rgbprint(scene.ambient.rgb);
		printf("\n");
	}
	if (scene.cam_is_set)
	{
		printf("cam: place, direction, fov\n");
		printvec3f(scene.camera.place);
		printvec3f(scene.camera.direction);
		printf("fov: %d\n\n", scene.camera.fov);
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