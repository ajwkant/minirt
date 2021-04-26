#include "minirt.h"

t_object	*last_object(t_scene *scene)
{
	while (scene->object->next)
		scene->object = scene->object->next;
	return (scene->object);
}
