#include "minirt.h"

// checkerfunctie

t_rgb	*rgb_reader(char *str, int *i)
{
	t_rgb *rgb;

	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		return (NULL);
	rgb->r  = readint(str, i, ' ');
	rgb->g = readint(str, i, ',');
	rgb->b = readint(str, i, ',');
	return (rgb);
}

t_vec3f	*vec_reader(char *str, int *i)
{
	t_vec3f *vec;

	vec = malloc(sizeof(t_vec3f));
	if (!vec)
		return (NULL);
	vec->x = readfloat(str, i, ' ');
	vec->y = readfloat(str, i, ',');
	vec->z = readfloat(str, i, ',');
	return (vec);
}
