#include "minirt.h"

// errorcodes return nog doen
// returnwaardes van readfuncties checken
// Checken of res en amb al bestaan

int		resolution(t_scene *scene, char *str) // Valuecheck
{
	int		i;
	t_res	res;

	i = 0;
	if (scene->res_is_set)
		return (-1);
	res.x = readint(str, &i, ' ');
	res.y = readint(str, &i, ' ');
	scene->resolution = res;
	scene->res_is_set = 1;
	scene->line_size = res.x;
	return (1);
}

int		ambient(t_scene *scene, char *str) // Ranges checken correctness
{
	int	i;
	t_amb amb;

	i = 0;
	if (scene->amb_is_set)
		return (-1);
	amb.ratio = readfloat(str, &i, ' ');
	amb.rgb = rgb_reader(str, &i);
	scene->ambient = amb;
	scene->amb_is_set = 1;
	return (1); // returnvalue checken
}

// Checker voor de returnvalues van readfloat
// Ranges checken correctness
// Errorhandling
int		cameraid(t_scene *scene, char *str)
{
	int		i;
	t_cam	new;

	if (scene->cam_is_set)
		return (0);
	i = 0;
	new.place = vec_reader(str, &i);
	new.direction = vec_reader(str, &i);
	new.fov = readint(str, &i, ' ');
	scene->camera = new;
	scene->cam_is_set = 1;
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
	t_sphere	sphere;

	i = 0;
	object = object_init();
	object->is_sphere = 1;
	sphere.place = vec_reader(str, &i);
	sphere.dia = readfloat(str, &i, ' ');
	sphere.rgb = rgb_reader(str, &i);
	object->sphere = sphere;
	add_last_object(scene, object);
	return (1);
}
