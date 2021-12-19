#include "minirt.h"

int		planeid(t_scene *scene, char *str)
{
	int			i;
	t_object	*object;
	t_plane		plane;

	i = 0;
	object = object_init();
	if (!object)
		return (error_return(-1, "Object init failed.\n"));
	object->is_plane = 1;
	if (vec3f_has_error(str + i))
		return (error_return(-1, "Error in plane place.\n"));
	plane.place = vec_reader(str, &i);
	if (vec3f_has_error(str + i))
		return (error_return(-1, "Error: plane direction is not valid.\n"));
	plane.direction = vec_reader(str, &i);
	// returnvalue van vecreader?
	if (vec3f_range_has_error(plane.direction, -1, 1))
		return (error_return(-1, "Plane direction does not have a valid range."));
	if (rgb_has_error(str + i, ' '))
		return (error_return(-1, "Plane RGB not valid.\n"));
	plane.rgb = rgb_reader(str, &i);
	if (rgb_range_has_error(plane.rgb))
		return (error_return(-1, "Plane RGB not valid range.\n"));
	object->plane = plane;
	normalize_vector(plane.direction);
	add_last_object(scene, object);
	return (1);
}

int		cylinderid(t_scene *scene, char *str)
{
	int			i;
	t_object	*object;
	t_cylinder	cylinder;

	i = 0;
	object = object_init();
	if (!object)
		return (error_return(-1, "Object init failed.\n"));
	object->is_cylinder = 1;
	if (vec3f_has_error(str + i))
		return (error_return(-1, "Error in cylinder place.\n"));
	cylinder.place = vec_reader(str, &i);
	if (vec3f_has_error(str + i))
		return (error_return(-1, "Error: cylinder direction is not valid.\n"));
	cylinder.direction = vec_reader(str, &i);
	if (vec3f_range_has_error(cylinder.direction, -1, 1))
		return (error_return(-1, "Cylinder direction does not have a valid range."));
	if (float_has_error(str + i, ' ', ' '))
		return (error_return(-1, "Error in cylinder diameter.\n"));
	cylinder.dia = readfloat(str, &i, ' ');
	if (cylinder.dia == -1 && str[i] != '-')
		return (error_return(-1, "Error in cylinder diameter."));
	if (cylinder.dia == 0 && str[i - 1] != 0)
		return (error_return(-1, "Error in cylinder diameter."));
	if (cylinder.dia <= 0)
		return (error_return(-1, "Error: cylinder diameter is not valid.\n"));
	if (float_has_error(str + i, ' ', ' '))
		return (error_return(-1, "Error in cylinder height.\n"));
	cylinder.height = readfloat(str, &i, ' ');
	if (cylinder.height == -1 && str[i] != '-')
		return (error_return(-1, "Error in cylinder height."));
	if (cylinder.height == 0 && str[i - 1] != 0)
		return (error_return(-1, "Error in cylinder height."));
	if (cylinder.height <= 0)
		return (error_return(-1, "Error: cylinder height is not valid.\n"));
	if (rgb_has_error(str + i, ' '))
		return (error_return(-1, "Cylinder RGB not valid.\n"));
	cylinder.rgb = rgb_reader(str, &i);
	if (rgb_range_has_error(cylinder.rgb))
		return (error_return(-1, "Cylinder RGB not valid range.\n"));
	object->cylinder = cylinder;
	add_last_object(scene, object);
	return (1);
}
