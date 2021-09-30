#include "minirt.h"

int		skipchar(char *str, int i, char c)
{
	if (str[i] != c)
	{
		printf("strchar: %c, c: %c\n", str[i], c);
		perror("Error in parsing. ' ' expected but not found.");
		return (-1);
	}
	while (str[i] == c)
		i++;
	return (i);
}

int		floatindex(char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]) || str[i] == '.' || str[i] == '-')
		i++;
	return (i);
}

int		readint(char *str, int *i, char c)
{
	int res;

	*i = skipchar(str, *i, c);
	if (*i == -1)
		return (-1);
	res = ft_atoi(str + *i);
	if (res) // fix this still
	*i += floatindex(str + *i);
	return (res);
}

float	ft_atof(char *str) // Min and Max value
{
	int		i;
	double	res;
	float	dec;
	int		neg;

	res = 0;
	dec = 0.1;
	neg = 1;
	i = 0;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		if ((res * neg) > MAX_FLOAT || (res * neg) < -MAX_FLOAT)
			return (0);
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while(ft_isdigit(str[i]))
		{
			res += (str[i] - '0') * dec;
			if (res * neg > MAX_FLOAT || res * neg < -MAX_FLOAT)
				return (0);
			dec /= 10;
			i++;
		}
	}
	res *= neg;
	return (res);
}

float	readfloat(char *str, int *i, char c)
{
	float res;

	*i = skipchar(str, *i, c);
	if (*i == -1)
		return (-1);
	// if (!ft_isdigit(str[*i]) && str[*i] != '-')
	// 	return (-1); // is dit nodig?
	res = ft_atof(str + *i);
	*i += floatindex(str + *i);
	return (res);
}
