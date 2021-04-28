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

void	my_mlx_pixel_put(t_truct *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int	main(int argc,char **argv)
{
	t_scene		scene;
	int			returnvalue;

	if (argc != 2)
		return (-1); // geen juiste argumenten error
	scene = scene_init();
	returnvalue = parser(argv[1], &scene);
	printscene(scene);
	return (0);
	//check returnvalue

}

// int		render_next_frame(t_truct *mystruct)
// {
// 	mlx_string_put (mystruct, void *win_ptr, int x, int y, int color, char *string );
// 	if (mystruct->i < 490)
// 		mystruct->i++;
// 	my_mlx_pixel_put(mystruct, 500 + mystruct->i, 500 + mystruct->i, 0x00FF0000);
// 	my_mlx_pixel_put(mystruct, 10 + mystruct->i, 10 + mystruct->i, 0x00FF0000);
// 	return (0);
// }

// int		main(void) // dit is de main voor om te gebruiken
// {

// 	t_truct		mystruct;
// 	void		*mlx_win;
// 	int			i;

//     mystruct.mlx = mlx_init();
// 	mlx_win = mlx_new_window(mystruct.mlx, 1000, 1000, "Hello world");
// 	mystruct.img = mlx_new_image(mystruct.mlx, 1000, 1000);
// 	mystruct.addr = mlx_get_data_addr(mystruct.img, &mystruct.bits_per_pixel, &mystruct.line_length,
// 		&mystruct.endian);
// 	i = 0;
// 	mlx_loop_hook(mystruct.mlx, render_next_frame, &mystruct);
// 	mlx_put_image_to_window(mystruct.mlx, mlx_win, mystruct.img, 0, 0);
// 	mlx_loop(mystruct.mlx);
// 	// while (i < 1000)
// 	// {
// 	// 	mystruct.i = i;
// 	// 	printf("TEST")
// 	// 	// mlx_loop_hook(mystruct.mlx, render_next_frame, &mystruct);
// 	// 	mlx_put_image_to_window(mystruct.mlx, mlx_win, mystruct.img, 0, 0);
// 	// 	mlx_loop(mystruct.mlx);
// 	// }

//     // mlx_loop_hook(mystruct.mlx, render_next_frame, &mystruct);
// }

// int		main(void)
// {
// 	// void	*mlx;
// 	// void	*mlx_win;
// 	// t_data	img;
// 	// int		x;
// 	// int		y;

// 	// mlx = mlx_init();
// 	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world");
// 	// img.img = mlx_new_image(mlx, 1920, 1080);
// 	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 	// 	&img.endian);

// 	// // x = 0;
// 	// // y = 0;
// 	// // while (x < 100 && y < 100)
// 	// // {
// 	// // 	my_mlx_pixel_put(&img, 500 + x, 500 + y, 0x00FF0000);
// 	// // 	x++;
// 	// // 	if (x == 100)
// 	// // 	{
// 	// // 		x = 0;
// 	// // 		y++;
// 	// // 	}
// 	// // }

// 	// // x = 0;
// 	// // y = 0;
// 	// // while (x < 10)
// 	// // {
// 	// // 	my_mlx_pixel_put(&img, 740 + x, 500 + y, 0x00FF0000);
// 	// // 	x++;
// 	// // }

// 	// x = -50;
// 	// y = -50;
// 	// while (x < 50 && y < 50)
// 	// {
// 	// 	if ((x * x) + (y * y) > 400 && x * x + y * y < 800)
// 	// 		my_mlx_pixel_put(&img, 800 + x, 500 + y, 0x00FF0000);
// 	// 	x++;
// 	// 	if (x == 50)
// 	// 	{
// 	// 		x = -50;
// 	// 		y++;
// 	// 	}
// 	// }
// 	// x = -50;
// 	// y = -50;
// 	// while (x < 50 && y < 50)
// 	// {
// 	// 	if ((x * x) + (y * y) > 400 && x * x + y * y < 800)
// 	// 		my_mlx_pixel_put(&img, 900 + x, 500 + y, 0x00FF0000);
// 	// 	x++;
// 	// 	if (x == 50)
// 	// 	{
// 	// 		x = -50;
// 	// 		y++;
// 	// 	}
// 	// }
// 	// x = 0;
// 	// y = 0;
// 	// // int z = 0;
// 	// while (x < 100 && y < 100)
// 	// {
// 	// 	if (x - y == 50 || x + y == 50)
// 	// 		my_mlx_pixel_put(&img, 800 + x, 600 + y, 0x00FF0000);
// 	// 	x++;

// 	// 	if (x == 100)
// 	// 	{
// 	// 		x = 0;
// 	// 		y++;
// 	// 		// z++;
// 	// 	}
// 	// }
// 	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	// mlx_loop(mlx);


// 	t_vars      vars;
// 	vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
//     // mlx_mouse_hook(vars.win, key_hook, &vars);
// 	mlx_hook(vars.win, 2, 1L<<0, close_function, &vars);
//     mlx_loop(vars.mlx);
// 	return (0);
// }
