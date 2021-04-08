#include "minirt.h"

int		skipchar(char *str, i, char c)
{
	if (str[i] != c)
		return (-1) // proper errorcode
	while (str[i] == c)
		i++;
	return (i);
}

int		floatindex(char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]) || str[i] == '.')
		i++;
	return (i);
}

int		readint(char *str, int *i, char c)
{
	int res;

	*i = skipchar(str, i, c);
	if (*i == -1) // errorcheck
		return (-1);
	if (!ft_isdigit(str[i]))
		return (-1) // proper errorcode
	res = ft_atoi(str);
	*i += floatindex(str);
	return (res);
}

float	readfloat(char *str, int *i, char c)
{
	int res;

	*i = skipchar(str, i, c);
	if (*i == -1) // errorcheck
		return (-1);
	if (!ft_isdigit(str[i]))
		return (-1) // proper errorcode
	res = ft_atof(str);
	*i += floatindex(str);
	return (res);
}

float	ft_atof(char *str)
{
	int		i;
	float	res;
	float	dec;
	int		neg;

	res = 0;
	dec = 0.1;
	neg = 1;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while(ft_isdigit(str[i]))
		{
			res += (str[i] - '0') * dec;
			dec /= 10;
			i++;
		}
	}
	res *= neg;
	return (res);
}
