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

unsigned int	make_rgb(t_rgb vec)
{
	unsigned int rgb;

	rgb = vec.r;
	rgb = (rgb << 8) + vec.g;
	rgb = (rgb << 8) + vec.b;
	return (rgb);
}

t_rgb	*get_rgb(t_object *object)
{
	if (object->sphere)
		return (object->sphere->rgb);
	if (object->plane)
		return (object->plane->rgb);
	if (object->square)
		return (object->square->rgb);
	if (object->cylinder)
		return (object->cylinder->rgb);
	if (object->triangle)
		return (object->triangle->rgb);
	return (NULL);
}

void	rgb_ratio(t_rgb	*rgb, float fr)
{
	rgb->r *= fr;
	rgb->g *= fr;
	rgb->b *= fr;
}