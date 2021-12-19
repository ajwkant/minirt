/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 12:46:35 by akant         #+#    #+#                 */
/*   Updated: 2021/10/15 14:19:39 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		error_return(int i, char *str)
{
	perror(str);
	return (i);
}

int		float_has_error(char *str, char prefix_char, char postfix_char)
{
	while (*str == prefix_char)
		str++;
	if (*str == '-')
		str++;
	if (!ft_isdigit(*str))
		return(error_return(1, "Error in reading float value: not a valid number.\n"));
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
	{
		str++;
		if (!ft_isdigit(*str))
			return(error_return(1, "Error in reading float value: not a valid number.\n"));
		while (ft_isdigit(*str))
			str++;
	}
	if (*str != postfix_char)
		return(error_return(1, "Error in reading float value: not a valid number.\n"));
	return (0);
}

int		rgb_has_error(char *str, char c)
{
	while (*str == c)
		str++;
	if (!ft_isdigit(*str))
		return (error_return(1, "Error in parsing RGB."));

	while (ft_isdigit(*str))
		str++;

	if (*str != ',')
		return (error_return(1, "Error in parsing RGB."));

	str++;
	if (!ft_isdigit(*str))
		return (error_return(1, "Error in parsing RGB."));

	while (ft_isdigit(*str))
		str++;

	if (*str != ',')
		return (error_return(1, "Error in parsing RGB."));

	str++;
	if (!ft_isdigit(*str))
		return (error_return(1, "Error in parsing RGB."));

	while (ft_isdigit(*str))
		str++;
	return (0);
}

int		vec3f_range_has_error(t_vec3f vec, float lower, float upper)
{
	if (!is_in_range(vec.x, lower, upper))
		return (1);
	if (!is_in_range(vec.y, lower, upper))
		return (1);
	if (!is_in_range(vec.z, lower, upper))
		return (1);
	return (0);
}

int		vec3f_has_error(char *str) // hier gaat het fout op de regel van camera
{
	if (float_has_error(str, ' ', ','))
		return (1);
	while (*str == ' ')
		str++;
	while (ft_isdigit(*str) || *str == '-' || *str == '.')
		str++;
	if (float_has_error(str, ',', ','))
		return (1);
	str++;
	while (ft_isdigit(*str) || *str == '-' || *str == '.')
		str++;
	if (float_has_error(str, ',', ' '))
		return (1);
	return(0);
}
