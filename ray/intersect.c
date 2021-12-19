/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 15:16:01 by akant         #+#    #+#                 */
/*   Updated: 2021/10/15 15:16:26 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		abcformula(float a, float b, float c, float *x1, float *x2)
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
		*x2 = *x1;
		return (1);
	}
	if (b > 0)
		q = -0.5 * (b + sqrt(discriminator));
	else
		q = -0.5 * (b - sqrt(discriminator));
	*x1 = q / a;
	*x2 = c / q;
	if (*x1 > *x2)
	{
		temp = *x1;
		*x1 = *x2;
		*x2 = temp;
	}
	return (1);
}

float	intersect_sphere(t_ray ray, t_sphere sphere)
{
	t_vec3f	L;
	float	a;
	float	b;
	float	c;
	float	x1;
	float	x2;

	L = vector_deduction(ray.place, sphere.place);
	a = dotproduct(ray.direction, ray.direction);
	b = 2 * dotproduct(ray.direction, L);
	c = dotproduct(L, L) - ((sphere.dia / 2) * (sphere.dia / 2));
	if (!abcformula(a, b, c, &x1, &x2))
		return (INFINITY);
	if (x1 < 0)
	{
		x1 = x2;
		if (x1 < 0)
			return (INFINITY);
	}
	return(x1);
}

float	intersect_plane(t_ray ray, t_plane plane)
{
	float	t;
	float	denominator;
	t_vec3f	temp;


	// printvec3f(plane.direction);
	// printvec3f(ray.direction);

	temp = vector_deduction(plane.place, ray.place);
	// printvec3f(temp);
	temp = normalize_vector(temp);
	// printvec3f(temp);
	plane.direction = normalize_vector(plane.direction);
	t = dotproduct(temp, plane.direction);
	// printvec3f(ray.direction);
	denominator = dotproduct(ray.direction, plane.direction);
	if (denominator < 0.0001)
		return (INFINITY);
	if (t / denominator < 0)
		return (INFINITY);
	return (t / denominator);
}

float	intersect(t_ray ray, t_object *object)
{
	if (object->is_sphere)
		return (intersect_sphere(ray, object->sphere));
	if (object->is_plane)
		return (intersect_plane(ray, object->plane));
	if (*object_list->cylinder)
		return (intersect_cylinder(ray, object->cylinder));
	return (0); // error oid?
}
