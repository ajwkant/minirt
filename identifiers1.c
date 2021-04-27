#include "minirt.h"

// errorcodes return nog doen
// returnwaardes van readfuncties checken
int		resolution(t_res *res, char *str) // Valuecheck
{
	int		i;

	i = 0;
	if (res != NULL)
		return (-1);
	res = malloc(sizeof(t_res));
	if (!res)
		return (-1); // errorcode
	res->x = readint(str, &i, ' ');
	res->y = readint(str, &i, ' ');
	// Returnvalue check
	return (1);
}

int		ambient(t_amb *amb, char *str) // Ranges checken correctness
{
	int	i;

	if (amb != NULL)
		return (-1);
	i = 0;
	amb = malloc(sizeof(t_amb));
	if (!amb)
		return (-1);
	amb->rgb = malloc(sizeof(t_rgb));
	if (!amb->rgb)
		return (-1);
	amb->ratio = readfloat(str, &i, ' ');
	amb->rgb->r  = readint(str, &i, ' ');
	amb->rgb->g = readint(str, &i, ',');
	amb->rgb->b = readint(str, &i, ',');
	// if () // errorchecking returnwaardes functies
	return (1); // returnvalue checken
}

// Checker voor de returnvalues van readfloat
// Ranges checken correctness
// Errorhandling
int		cameraid(t_cam *cam, char *str)
{
	int		i;

	i = 0;
	if (cam == NULL)
		cam = malloc(sizeof(t_cam)); // volgende camera in de list oid
	// else
	// 	// laatste camera van de lijst en dan toevoegen
	if (!cam)
		return (-1);
	cam->place->x = readfloat(str, &i, ' ');
	cam->place->y = readfloat(str, &i, ',');
	cam->place->z = readfloat(str, &i, ',');
	cam->direction->x = readfloat(str, &i, ' ');
	cam->direction->y = readfloat(str, &i, ',');
	cam->direction->z = readfloat(str, &i, ',');
	cam->fov = readint(str, &i, ' ');
	cam->next = NULL;
	return (1);
}

int		lightid(t_light *light, char *str)
{
	int		i;

	i = 0;
	if (light == NULL) // zelfde als bij cam, een lijst maken
		light = malloc(sizeof(t_light));
	if (!light)
		return (-1);
	light->place->x = readfloat(str, &i, ' ');
	light->place->y = readfloat(str, &i, ',');
	light->place->z = readfloat(str, &i, ',');
	light->brightness = readfloat(str, &i, ' ');
	light->rgb->r = readint(str, &i, ' ');
	light->rgb->g = readint(str, &i, ',');
	light->rgb->b = readint(str, &i, ',');
	return (1);
}

int		sphereid(t_scene *scene, char *str)
{
	int			i;
	t_object	*object;
	t_sphere	*sphere;

	i = 0;
	object = object_init();
	if (object)
		return (-1); // error
	add_last_object(scene, object);
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (-1);
	sphere->place->x = readfloat(str, &i, ' ');
	sphere->place->y = readfloat(str, &i, ',');
	sphere->place->z = readfloat(str, &i, ',');
	sphere->dia = readfloat(str, &i, ' ');
	sphere->rgb->r = readint(str, &i, ' ');
	sphere->rgb->g = readint(str, &i, ',');
	sphere->rgb->b = readint(str, &i, ',');
	object->sphere = sphere;
	return (1);
}
