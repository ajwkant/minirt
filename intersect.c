#include "minirt.h"

vec3f	*vector_deduction(vec3f *a, vec3f *b)
{
	vec3f	*result;
	result = malloc(sizeof(vec3f));
	if (!result)
		return (NULL);
	result = a->x - b->x;
	result = a->y - b->y;
	result = a->z - b->z;
	return (result);
}

float	dotproduct(vec3f *a, vec3f *b)
{
	return (a->x * b->x + a->y * b->y +  a->z * b->z);
}

int		abcformula(float a, float b, float c, int *x1, int *x2)
{
	float discriminator;
	float q;
	float temp;

	discriminator = b * b - 4 * a * c;
	if (discriminator < 0)
		return (0);
	if (discriminator == 0)
	{
		*x1 = -b / (2  * a);
		*x2 = x1;
		return (1);
	}
	*x1 = (-b + sqrt(discriminator)) / (2  * a);
	*x2 = (-b - sqrt(discriminator)) / (2  * a);
	if (*x1 > *x2)
	{
		temp = *x1;
		*x1 = *x2;
		*x2 = temp;
	}
	return (1);
}

float	intersect(t_ray *ray, t_sphere *sphere)
{
	t_vec3f *L;
	float	a;
	float	b;
	float	c;
	int		x1;
	int		x2;


	L = vector_deduction(ray->place, sphere->place);
	a = dotproduct(ray->direction, ray->direction);
	if (a != 1)
		return (-1); // foutmelding
	b = 2 * dotproduct(ray->direction, L);
	c = dotproduct(L, L) - sphere->dia * sphere->dia;
	if (!abcformula(a, b, c, &x1, &x2))
		return (-1); // geen snijpunten
	if (*x1 < 0)
	{
		*x1 = *x2;
		if (*x1 < 0)
		return (-1);
	}
	return(x1);
}