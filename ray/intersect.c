#include "minirt.h"

int		abcformula(float a, float b, float c, float *x1, float *x2)
{
	float discriminator;
	// float q; // nog checken uit de tutorial
	float temp;

	discriminator = b * b - 4 * a * c;
	if (discriminator < 0)
		return (0);
	if (discriminator == 0)
	{
		*x1 = -b / (2  * a);
		*x2 = *x1;
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

float	intersect_sphere(t_ray *ray, t_sphere *sphere)
{
	t_vec3f *L;
	float	a;
	float	b;
	float	c;
	float	x1;
	float	x2;


	L = vector_deduction(ray->place, sphere->place);
	a = dotproduct(ray->direction, ray->direction);
	// if (a != 1)
	// 	return (-1); // foutmelding
	b = 2 * dotproduct(ray->direction, L);
	c = dotproduct(L, L) - sphere->dia * sphere->dia;
	free(L);
	if (!abcformula(a, b, c, &x1, &x2))
		return (INFINITY); // geen snijpunten
	if (x1 < 0)
	{
		x1 = x2;
		if (x1 < 0)
		return (INFINITY);
	}
	return(x1);
}

float	intersect(t_ray *ray, t_object *object_list)
{
	if (*object_list->sphere)
		return (intersect_sphere(ray, object_list->sphere));
	if (*object_list->plane)
		return (intersect_plane(ray, object_list->plane));
	if (*object_list->cylinder)
		return (intersect_cylinder);
}
