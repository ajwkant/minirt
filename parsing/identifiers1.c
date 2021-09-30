#include "minirt.h"

// errorcodes return nog doen
// returnwaardes van readfuncties checken
// Checken of res en amb al bestaan

// Checker voor de returnvalues van readfloat
// Ranges checken correctness
// Errorhandling
int		error_return(int i, char *str)
{
	perror(str);
	return (i);
}

int		float_has_error(char *str, char prefix_char, char postfix_char)
{
	while (*str == prefix_char)
		str++;
	if (*str == '-')
		str++;
	if (!ft_isdigit(*str))
		return(error_return(1, "Error in reading float value: not a valid number.\n"));
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
		str++;
	if (!ft_isdigit(*str))
		return(error_return(1, "Error in reading float value: not a valid number.\n"));
	while (ft_isdigit(*str))
		str++;
	if (*str != postfix_char)
		return(error_return(1, "Error in reading float value: not a valid number.\n"));
	return (0);
}

int		rgb_has_error(char *str, char c)
{
	while (*str == c)
		str++;
	if (!ft_isdigit(*str))
		return (error_return(1, "Error in parsing RGB."));

	while (ft_isdigit(*str))
		str++;

	if (*str != ',')
		return (error_return(1, "Error in parsing RGB."));

	str++;
	if (!ft_isdigit(*str))
		return (error_return(1, "Error in parsing RGB."));

	while (ft_isdigit(*str))
		str++;

	if (*str != ',')
		return (error_return(1, "Error in parsing RGB."));

	str++;
	if (!ft_isdigit(*str))
		return (error_return(1, "Error in parsing RGB."));

	while (ft_isdigit(*str))
		str++;
	return (0);
}

int		is_in_range(float num, float lower, float upper)
{
	if (num < lower || num > upper)
		return (0);
	return (1);
}

int		rgb_range_has_error(t_rgb rgb)
{
	if (!is_in_range(rgb.r, 0, 255))
		return (1);
	if (!is_in_range(rgb.g, 0, 255))
		return (1);
	if (!is_in_range(rgb.b, 0, 255))
		return (1);
	return (0);
}

int		ambient(t_scene *scene, char *str) // Ranges checken correctness
{
	int	i;
	t_amb amb;

	i = 0;
	if (scene->amb_is_set)
		return (-1);
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
		return (-1);
	amb.rgb = rgb_reader(str, &i);
	if (rgb_range_has_error(amb.rgb))
		return (error_return(-1, "Ambient RGB not valid range.\n"));
	scene->ambient = amb;
	scene->amb_is_set = 1;
	return (1);
}

int		vec_range_has_error(t_vec3f vec, float upper, float lower)
{
	if (!is_in_range(rgb.r, lower, upper))
		return (1);
	if (!is_in_range(rgb.g, lower, upper))
		return (1);
	if (!is_in_range(rgb.b, lower, upper))
		return (1);
	return (0);
}

int		vec3f_has_error(char *str)
{
	if (float_has_error(str, ' ', ','))
		return (1);
	while (ft_isdigit(*str) || *str == '-' || *str == '.')
		str++;
	if (float_has_error(str, ',', ','))
		return (1);
	while (ft_isdigit(*str) || *str == '-' || *str == '.')
		str++;
	if (float_has_error(str, ',', ' '))
		return (1);
	return(0);
}

int		vec3f_range_has_error(t_vec3f vec, float upper, float lower)
{
	if (!is_in_range(vec.x, lower, upper))
		return (1);
	if (!is_in_range(vec.y, lower, upper))
		return (1);
	if (!is_in_range(vec.z, lower, upper))
		return (1);
	return (0);
}

int		int_has_error(char *str, char prefix_char, char postfix_char) // wat als postfix het laatste char van de file is?
{
	while (*str == prefix_char)
		str++;
	if (!ft_isdigit(*str))
		return(error_return(1, "Error in reading int value: not a valid number.\n"));
	while (ft_isdigit(*str))
		str++;
	if (*str != postfix_char)
		return(error_return(1, "Error in reading float value: not a valid number.\n"));
	return (0);
}

int		cameraid(t_scene *scene, char *str)
{
	int		i;
	t_cam	new;

	i = 0;
	if (scene->cam_is_set)
		return (-1);
	if (vec3f_has_error(str + i))
		return (-1);
	new.place = vec_reader(str, &i); // check returnvalue
	if (vec3f_has_error(str + i))
		return (-1);
	new.direction = vec_reader(str, &i);
	if (vec3f_range_has_error(new.direction, -1, 1))
		return (error_return(-1, "Camera direction does not have a valid range."));
	if (int_has_error(str + 1))
		return (error_return(-1, "Error in reading camera POV\n"));
	new.fov = readint(str, &i, ' ');
	if (!is_in_range(new.fov, 0, 180)
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
		return (error_return(-1, "Error in light brightness.")); // ---------range
	if (rgb_has_error(str + i, ' '))
		return (-1);
	light->rgb = rgb_reader(str, &i);
	if (rgb_range_has_error(light->rgb))
		return (error_return(-1, "Light RGB not valid range.\n"));
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
	// -----------hier en light brightness range checken

	sphere.rgb = rgb_reader(str, &i);
	object->sphere = sphere;
	add_last_object(scene, object);
	return (1);
}
