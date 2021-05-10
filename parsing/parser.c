#include "minirt.h"

int		identifier(char *str, t_scene *scene)
{
	if (!ft_strncmp(str, "\n", 1))
		return (1);
	if (!ft_strncmp(str, "R ", 2))
		return (resolution(scene, str + 1));
	if (!ft_strncmp(str, "A ", 2))
		return (ambient(scene, str + 1));
	if (!ft_strncmp(str, "c ", 2))
		return (cameraid(scene, str + 1));
	if (!ft_strncmp(str, "l ", 2))
		return (lightid(scene, str + 1));
	if (!ft_strncmp(str, "pl ", 3))
		return (planeid(scene, str + 2));
	if (!ft_strncmp(str, "sp ", 3))
		return (sphereid(scene, str + 2)); 
	if (!ft_strncmp(str, "sq ", 3))
		return (squareid(scene, str + 2));
	if (!ft_strncmp(str, "cy ", 3))
		return (cylinderid(scene, str + 2));
	if (!ft_strncmp(str, "tr ", 3))
		return (triangleid(scene, str + 2));
	return (-1);
}

int		parser(char *file, t_scene *scene)
{
	int		fd;
	char	*line;
	int		ret;
	int		error;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	ret = get_next_line(fd, &line);
	while (ret >= 0)
	{
		error = identifier(line, scene); // check returnvalue
		free(line);
		if (error == -1)
			return (-1);
		if (ret == 0) // nog passende error dingen schrijven
			break ;
		ret = get_next_line(fd, &line);
	}
	if (ret == -1)
		return (-1);
	return (1);
}
