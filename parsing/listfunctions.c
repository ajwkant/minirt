/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   listfunctions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 15:31:30 by akant         #+#    #+#                 */
/*   Updated: 2021/09/20 15:31:32 by akant         ########   odam.nl         */
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

	temp = scene->light;
	if (!scene->light)
		scene->light = light;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = light;
	}
}
