#include "minirt.h"

void	add_last_object(t_scene *scene, t_object *object)
{
	t_object *temp;

	if (scene->object)
	{
		temp = scene->object;
		while (temp->next)
			temp = temp->next;
		temp->next = object;
	}
	else
		scene->object = object;
}
