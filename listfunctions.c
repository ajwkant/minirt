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

void	camera_list_last(t_scene *scene, t_cam *cam)
{
	t_cam *temp;

	temp = scene->camera;
	if (!scene->camera)
		scene->camera = cam;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = cam;
	}
}

void	light_list_last(t_scene *scene, t_light *light)
{
	t_light *temp;

	temp = scene->light;
	if (!scene->light)
		scene->light = light;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = light;
	}
}
