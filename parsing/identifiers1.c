#include "minirt.h"

// errorcodes return nog doen
// returnwaardes van readfuncties checken
// Checken of res en amb al bestaan

// Checker voor de returnvalues van readfloat
// Ranges checken correctness
// Errorhandling

int		ambient(t_scene *scene, char *str) // Ranges checken correctness
{
	int	i;
	t_amb amb;

	i = 0;
	if (scene->amb_is_set)
		return (error_return(-1, "Error: ambient is already set.\n"));
	if (float_has_error(str + i, ' ', ' '))
		return (error_return(-1, "Error in ambient ratio."));
	amb.ratio = readfloat(str, &i, ' ');
	if (amb.ratio == -1 && str[i] != '-')
		return (error_return(-1, "Error in reading ambient ratio."));
	if (amb.ratio == 0 && str[i - 1] != 0)
		return (error_return(-1, "Ambient ratio is too big or too small."));
	if (!is_in_range(amb.ratio, 0, 1))
		return (error_return(-1, "Ambient ratio not in range 0.0-1.0.\n"));
	if (rgb_has_error(str + i, ' '))
		return (error_return(-1, "Error: ambient RGB.\n"));
	amb.rgb = rgb_reader(str, &i);
	if (rgb_range_has_error(amb.rgb))
		return (error_return(-1, "Ambient RGB not valid range.\n"));
	scene->ambient = amb;
	scene->amb_is_set = 1;
	return (1);
}

int		cameraid(t_scene *scene, char *str)
{
	int		i;
	t_cam	new;

	i = 0;
	if (scene->cam_is_set)
		return (error_return(-1, "Error:camera is already set.\n"));
	if (vec3f_has_error(str + i))
		return (error_return(-1, "Error: camera place.\n"));
	new.place = vec_reader(str, &i); // check returnvalue
	if (vec3f_has_error(str + i))
		return (error_return(-1, "Error: direction is not valid.\n"));
	new.direction = vec_reader(str, &i); // returnvalue van vec_reader?
	if (vec3f_range_has_error(new.direction, -1, 1))
		return (error_return(-1, "Camera direction does not have a valid range."));
	if (int_has_error(str + i, ' ', '\0')) // Wat als dit de laatste regel is?
		return (error_return(-1, "Error in reading camera POV\n"));
	new.fov = readint(str, &i, ' ');
	if (!is_in_range(new.fov, 0, 180))
		return (error_return(-1, "Error: POV not in valid range.\n"));
	scene->camera = new;
	scene->cam_is_set = 1;
	return (1);
}

int		lightid(t_scene *scene, char *str)
{
	int		i;
	t_light	*light;

	i = 0;
	light = malloc(sizeof(t_light));
	if (!light)
		return (error_return(-1, "Malloc error.\n"));
	if (vec3f_has_error(str + i))
		return (error_return(-1, "Error in light place.\n"));
	light->place = vec_reader(str, &i);
	if (float_has_error(str + i, ' ', ' '))
		return (error_return(-1, "Error in light brightness.\n"));
	light->brightness = readfloat(str, &i, ' ');
	if (light->brightness == -1 && str[i] != '-')
		return (error_return(-1, "Error in light brightness."));
	if (light->brightness == 0 && str[i - 1] != 0)
		return (error_return(-1, "Error in light brightness."));
	if (!is_in_range(light->brightness, 0, 1))
		return (error_return(-1, "Error: Light brightness not in valid range.\n"));
	if (rgb_has_error(str + i, ' '))
		return (error_return(-1, "Light RGB not valid.\n"));
	light->rgb = rgb_reader(str, &i);
	if (rgb_range_has_error(light->rgb))
		return (error_return(-1, "Light RGB not valid range.\n"));
	light->next = NULL;
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
	if (!object)
		return (error_return(-1, "Object init failed.\n"));
	object->is_sphere = 1;
	if (vec3f_has_error(str + i))
		return (error_return(-1, "Error in sphere place.\n"));
	sphere.place = vec_reader(str, &i);
	if (float_has_error(str + i, ' ', ' '))
		return (error_return(-1, "Error in sphere diameter.\n"));
	sphere.dia = readfloat(str, &i, ' ');
	if (sphere.dia == -1 && str[i] != '-')
		return (error_return(-1, "Error in sphere diameter."));
	if (sphere.dia == 0 && str[i - 1] != 0)
		return (error_return(-1, "Error in sphere diameter."));
	if (sphere.dia <= 0)
		return (error_return(-1, "Error: sphere diameter is not valid.\n"));
	if (rgb_has_error(str + i, ' '))
		return (error_return(-1, "Sphere RGB not valid.\n"));
	sphere.rgb = rgb_reader(str, &i);
	if (rgb_range_has_error(sphere.rgb))
		return (error_return(-1, "Light RGB not valid range.\n"));
	object->sphere = sphere;

	add_last_object(scene, object);
	return (1);
}
