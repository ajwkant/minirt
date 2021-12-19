/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_rgb_reader.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 14:16:11 by akant         #+#    #+#                 */
/*   Updated: 2021/10/15 14:16:16 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	rgb_reader(char *str, int *i)
{
	t_rgb rgb;

	rgb.r  = readint(str, i, ' ');
	rgb.g = readint(str, i, ',');
	rgb.b = readint(str, i, ',');
	return (rgb);
}

t_vec3f	vec_reader(char *str, int *i)
{
	t_vec3f vec;

	vec.x = readfloat(str, i, ' ');
	vec.y = readfloat(str, i, ',');
	vec.z = readfloat(str, i, ',');
	return (vec);
}

unsigned int	make_rgb(t_rgb vec, float ratio)
{
	unsigned int rgb;

	rgb = vec.r * ratio;
	rgb = (rgb << 8) + vec.g * ratio;
	rgb = (rgb << 8) + vec.b * ratio;
	return (rgb);
}

t_rgb	get_rgb(t_object *object)
{
	if (object->is_sphere)
		return (object->sphere.rgb);
	if (object->is_plane)
		return (object->plane.rgb);
	// if (object->is_cylinder)
	return (object->cylinder.rgb);
}
