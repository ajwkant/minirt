#include "minirt.h"















// een of meerdere newlines overslaan
// struct goed maken en doorgeven

int		identifier(char *str)
{
	if (*str == 'R')
		return (resolution(, str + 1));
	if (*str == 'A')
		return (ambient( , str + 1));
	if (*str == 'c' && str[1] == ' ')
		return ();
	if (*str == 'l')
		return ();
	if (*str == 'p')
		return ();
	if (*str == 's' && str[1] == 'p')
		return ();
	if (*str == 's' && str[1] == 'q')
		return ();
	if (*str == 'c' && str[1] = 'y')
		return ();
	if (*str == 't' && str[1] == 'r')
		return ();
	return (-1);
}

void	*parser(char *file)
{
	int		fd;
	char	*line;
	int		ret;
	int		error;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = get_next_line(fd, &line);
	while (ret >= 0)
	{
		error = identifier(line);
		if (ret == 0) // nog passende error dingen schrijven
			break ;
		ret = get_next_line(fd, &line);
	}
	if (ret == -1)
		return (NULL);
}
