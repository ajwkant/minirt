#include "minirt.h"

void	scene_init(t_scene *scene)
{
	scene->res_is_set = 0;
	scene->amb_is_set = 0;
	scene->cam_is_set = 0;
	scene->light = NULL;
}

t_object	*object_init(void)
{
	t_object *object;

	object = malloc(sizeof(t_object));
	if (!object)
		return (NULL);
	object->is_sphere = 0;
	object->is_plane = 0;
	// object->square = NULL;
	object->is_cylinder = 0;
	// object->triangle = NULL;
	object->next = NULL;
	return (object);
}

t_vec3f	vec3f_init(void)
{
	t_vec3f	temp;

	temp.x = 0;
	temp.y = 0;
	temp.z = 0;
	return (temp);
}

t_ray	ray_init(void)
{
	t_ray	temp;

	temp.place = vec3f_init();
	temp.direction = vec3f_init();
	return (temp);
}
