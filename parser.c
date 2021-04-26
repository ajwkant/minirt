#include "minirt.h"

// een of meerdere newlines overslaan
int		identifier(char *str, t_scene *scene)
{
	if (!ft_strncmp(str, "R ", 2))
		return (resolution(scene->resolution, str + 1));
	if (!ft_strncmp(str, "A ", 2))
		return (ambient(scene->ambient, str + 1));
	if (!ft_strncmp(str, "c ", 2))
		return (cameraid(scene->cameraid, str + 1));
	if (!ft_strncmp(str, "l ", 2))
		return (lichtid(scene->lightid, str + 1));
	if (!ft_strncmp(str, "pl ", 3))
		return (planeid(t_scene *scene, str + 1));
	if (!ft_strncmp(str, "sp ", 3))
		return (sphereid(t_scene *scene, str + 1)); 
	if (!ft_strncmp(str, "sq ", 3))
		return (squareid(t_scene *scene, str + 1));
	if (!ft_strncmp(str, "cy ", 3))
		return (cylinderid(t_scene *scene, str + 1));
	if (!ft_strncmp(str, "tr ", 3))
		return (triangleid(t_scene *scene, str + 1));
	return (-1);
}

void	*parser(char *file, t_scene *scene) // lege lines skippen
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
		error = identifier(line, scene); // check returnvalue
		if (ret == 0) // nog passende error dingen schrijven
			break ;
		ret = get_next_line(fd, &line);
	}
	if (ret == -1)
		return (NULL);
}
