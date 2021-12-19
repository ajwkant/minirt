/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 12:46:35 by akant         #+#    #+#                 */
/*   Updated: 2021/10/15 12:57:08 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		int_has_error(char *str, char prefix_char, char postfix_char) // wat als postfix het laatste char van de file is?
{
	while (*str == prefix_char)
		str++;
	if (!ft_isdigit(*str))
		return(error_return(1, "Error in reading int value: not a valid number.\n"));
	while (ft_isdigit(*str))
		str++;
	if (*str != postfix_char)
		return(error_return(1, "1Error in reading float value: not a valid number.\n"));
	return (0);
}

int		is_in_range(float num, float lower, float upper)
{
	if (num < lower || num > upper)
		return (0);
	return (1);
}

int		rgb_range_has_error(t_rgb rgb)
{
	if (!is_in_range(rgb.r, 0, 255))
		return (1);
	if (!is_in_range(rgb.g, 0, 255))
		return (1);
	if (!is_in_range(rgb.b, 0, 255))
		return (1);
	return (0);
}
