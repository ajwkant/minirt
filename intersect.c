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

	discriminator = b * b - 4 * a * c;
	if (discriminator < 0)
		return (0);
	if (discriminator == 0)
	{
		*x1 = -b / (2  * a);
		*x2 = x1;
		return (1);
	}
	q = -b + 
	
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
}

Vec3f L = orig - center; 
        float a = dir.dotProduct(dir);
        float b = 2 * dir.dotProduct(L); 
        float c = L.dotProduct(L) - radius2; 
        if (!solveQuadratic(a, b, c, t0, t1)) return false; 
#endif 
        if (t0 > t1) std::swap(t0, t1); 
 
        if (t0 < 0) { 
            t0 = t1; // if t0 is negative, let's use t1 instead 
            if (t0 < 0) return false; // both t0 and t1 are negative 
        } 
 
        t = t0; 
 
        return true; 