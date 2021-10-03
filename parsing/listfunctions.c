/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   listfunctions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 15:31:30 by akant         #+#    #+#                 */
/*   Updated: 2021/10/03 18:30:26 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_last_object(t_scene *scene, t_object *object)
{
	t_object *temp;

	if (scene->object)
	{
		temp = scene->object;
		while (temp->next)
			temp = temp->next;
		temp->next = object;
	}
	else
		scene->object = object;
}

void	light_list_last(t_scene *scene, t_light *light)
{
	t_light *temp;

	if (!scene->light)
		scene->light = light;
	else
	{
		temp = scene->light;
		while (temp->next)
			temp = temp->next;
		temp->next = light;
	}
}
