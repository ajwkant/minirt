#include "minirt.h"

// errorcodes return nog doen
// returnwaardes van readfuncties checken
// Checken of res en amb al bestaan

int		resolution(t_scene *scene, char *str) // Valuecheck
{
	int		i;
	t_res	*res;

	i = 0;
	if (scene->resolution)
		return (-1);
	res = malloc(sizeof(t_res));
	if (!res)
		return (-1);
	res->x = readint(str, &i, ' ');
	res->y = readint(str, &i, ' ');
	scene->resolution = res;
	return (1);
}

int		ambient(t_scene *scene, char *str) // Ranges checken correctness
{
	int	i;
	t_amb *amb;

	i = 0;
	if (scene->ambient)
		return (-1);
	amb = malloc(sizeof(t_amb));
	if (!amb)
		return (-1);
	amb->ratio = readfloat(str, &i, ' ');
	amb->rgb = rgb_reader(str, &i);
	scene->ambient = amb;
	return (1); // returnvalue checken
}

// Checker voor de returnvalues van readfloat
// Ranges checken correctness
// Errorhandling
int		cameraid(t_scene *scene, char *str)
{
	int		i;
	t_cam	*new;

	new = malloc(sizeof(t_cam));
	if (!new)
		return (-1);
	i = 0;
	new->place = vec_reader(str, &i);
	new->direction = vec_reader(str, &i);
	new->fov = readint(str, &i, ' ');
	new->next = NULL;
	camera_list_last(scene, new);
	return (1);
}

int		lightid(t_scene *scene, char *str)
{
	int		i;
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (-1);
	i = 0;
	light->place = vec_reader(str, &i);
	light->brightness = readfloat(str, &i, ' ');
	light->rgb = rgb_reader(str, &i);
	light_list_last(scene, light);
	return (1);
}

int		sphereid(t_scene *scene, char *str)
{
	int			i;
	t_object	*object;
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (-1);
	i = 0;
	object = object_init();
	object->sphere = sphere;
	sphere->place = vec_reader(str, &i);
	sphere->dia = readfloat(str, &i, ' ');
	sphere->rgb = rgb_reader(str, &i);
	add_last_object(scene, object);
	return (1);
}
