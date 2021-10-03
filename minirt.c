#include <mlx.h>
#include <stdio.h>
#include "minirt.h"

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

typedef struct  s_truct {
    void        *mlx;
	void		*img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
	int			i;
}               t_truct;

int		close_function(int keycode, t_vars *vars)
{
	printf("keycode: %d\n", keycode);
	vars = NULL;
	mlx_destroy_window(vars->mlx, vars->win);
	return (1);
}

void	my_mlx_pixel_put(t_scene scene, int x, int y, unsigned int color)
{
    char	*dst;

    dst = scene.address + (y * scene.line_size + x * (scene.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


// int frame_render(t_scene *scene)
// {
// 	ray_trace(scene);
//     //mrt_draw_shade(v, 0xFFFFFF);
//     mlx_put_image_to_window(scene->mlx, scene->window, scene->img_ptr, 0, 0);
//     return (1);
// }

// void	key_hook(int keycode, void *param)
// {
// 	printf("keycode: %d\n", keycode);
// 	param = NULL;
// }

int		main(int argc, char **argv)
{
	t_scene		scene;
	int			returnvalue;

	if (argc != 2)
		return (-1);
	scene_init(&scene);
	returnvalue = parser(argv[1], &scene);
	if (returnvalue == -1)
		return (-1);

	scene.mlx = mlx_init();
	scene.x = 1080;
	scene.y = 1920;
	scene.window = mlx_new_window(scene.mlx, scene.x, scene.y, "Hello world");
	// mlx_mouse_hook(scene.window, (void *)key_hook, &scene);
	scene.img_ptr = mlx_new_image(scene.mlx, scene.x, scene.y);
	scene.address = mlx_get_data_addr(scene.img_ptr, &scene.bits_per_pixel, &scene.line_size,
		&scene.endian);
	printf("heyo\n\n");

	returnvalue = ray_trace(scene); // ------hier gaat het nu fout
	printf("heyo\n\n");

	if (returnvalue == -1)
		return (-1);
	// i = 0;
	// mlx_loop_hook(scene.mlx, render_next_frame, &scene);
	mlx_put_image_to_window(scene.mlx, scene.window, scene.img_ptr, 0, 0);
	mlx_loop(scene.mlx);
	// printf("afgelopen uit");
}

// 	t_vars      vars;
// 	vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
//     // mlx_mouse_hook(vars.win, key_hook, &vars);
// 	mlx_hook(vars.win, 2, 1L<<0, close_function, &vars);
//     mlx_loop(vars.mlx);
// 	return (0);
// }
