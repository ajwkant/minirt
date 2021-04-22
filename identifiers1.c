#include "minirt.h"

// errorcodes return nog doen
// returnwaardes van readfuncties checken

int		resolution(t_res *res, char *str) // Valuecheck
{
	int		i;

	i = 0;
	res = malloc(sizeof(t_res));
	if (!res)
		return (-1) // errorcode
	res->x = readint(str, &i, ' ');
	res->y = readint(str, &i, ' ');
	// Returnvalue check
	return (1);
}

int		ambient(t_amb *amb, char *str) // Ranges checken correctness
{
	int	i;

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
	if () // errorchecking returnwaardes functies
	return (1); // returnvalue checken
}

// Checker voor de returnvalues van readfloat
// Ranges checken correctness
// Errorhandling
int		cameraid(t_cam *cam, char *str)
{
	int		i;

	i = 0;
	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (-1);
	cam->x = readfloat(str, &i, ' ');
	cam->y = readfloat(str, &i, ',');
	cam->z = readfloat(str, &i, ',');
	cam->vx = readfloat(str, &i, ' ');
	cam->vy = readfloat(str, &i, ',');
	cam->vz = readfloat(str, &i, ',');
	cam->pov = readint(str, &i, ' ');
	return (1);
}

int		lightid(t_light *light, char *str)
{
	int		i;

	i = 0;
	light = malloc(sizeof(t_light));
	if (!light)
		return (-1);
	light->x = readfloat(str, &i, ' ');
	light->y = readfloat(str, &i, ',');
	light->z = readfloat(str, &i, ',');
	light->brightness = readfloat(str, &i, ' ');
	light->r = readint(str, &i, ' ');
	light->g = readint(str, &i, ',');
	light->b = readint(str, &i, ','):
	return (1);
}

int		sphereid(t_sphere *sphere, char *str)
{
	int		i;

	i = 0;
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (-1);
	sphere->x = readfloat(str, &i, ' ');
	sphere->y = readfloat(str, &i, ',');
	sphere->z = readfloat(str, &i, ',');
	sphere->brightness = readfloat(str, &i, ' ');
	sphere->r = readint(str, &i, ' ');
	sphere->g = readint(str, &i, ',');
	sphere->b = readint(str, &i, ','):
	return (1);
}
