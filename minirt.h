#ifndef MINIRT_H
#define MINIRT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <sys/stat.h> 
#include <fcntl.h>
#include <math.h>


// void			*img;
    // char        	*addr;
    // int         	bits_per_pixel;

// Een lange list maken van alle objecten

typedef struct		s_vec3f
{
	float				x;
	float				y;
	float				z;
}					t_vec3f;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_ray
{
	t_vec3f			*place;
	t_vec3f			*direction;
}					t_ray;

typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

typedef struct		s_amb
{
	float			ratio;
	t_rgb			*rgb;
}					t_amb;

typedef struct		s_cam
{
	t_vec3f			*place;
	t_vec3f			*direction;
	int				fov;
	void			*next;
}					t_cam;

typedef struct		s_light
{
	t_vec3f			*place;
	float			brightness;
	t_rgb			*rgb;
	void			*next;
}					t_light;

typedef struct		s_sphere
{
	t_vec3f			*place;
	float			dia;
	t_rgb			*rgb;
}					t_sphere;

typedef struct		s_plane
{
	t_vec3f			*place;
	t_vec3f			*direction;
	t_rgb			*rgb;
}					t_plane;

typedef struct		s_square
{
	t_vec3f			*place;
	t_vec3f			*direction;
	float			size;
	t_rgb			*rgb;
}					t_square;

typedef struct		s_cylinder
{
	t_vec3f			*place;
	t_vec3f			*direction;
	float			diam;
	float			height;
	t_rgb			*rgb;
}					t_cylinder;

typedef struct		s_triangle
{
	t_vec3f			*p1;
	t_vec3f			*p2;
	t_vec3f			*p3;
	t_rgb			*rgb;
}					t_triangle;

typedef struct			s_object
{
	t_sphere			*sphere;
	t_plane				*plane;
	t_square			*square;
	t_cylinder			*cylinder;
	t_triangle			*triangle;
	void				*next;
}						t_object;

typedef struct			s_img
{
	// void				*img_ptr;
	// char				*address;
	int					bits_per_pixel;
	int					line_size;
	int					endian;
}						t_img;

typedef struct			s_scene
{
	void				*mlx;
	void				*img_ptr;
	char				*address;
	int					bits_per_pixel;
	int					line_size;
	int					endian;
	t_img				*img;
	t_rgb				*framebuffer;
	t_res				*resolution;
	t_amb				*ambient;
	t_cam				*camera;
	t_light				*light;
	t_object			*object;
	// int					x;
	// int					y;
}						t_scene;



// typedef struct		s_truct {
//     void       		*mlx;
// 	// void			*img;
//     // char        	*addr;
//     // int         	bits_per_pixel;
//     int         	width;
//     int         	height;
//     // int         	endian;
// 	// int				i;
// }               	t_truct;


int		parser(char *file, t_scene *scene);

// Parserhelperfunctions
int		skipchar(char *str, int i, char c);
int		floatindex(char *str);
int		readint(char *str, int *i, char c);
float	readfloat(char *str, int *i, char c);
float	ft_atof(char *str);
// Identifiers 1
int		resolution(t_scene *scene, char *str);
int		ambient(t_scene *scene, char *str);
int		cameraid(t_scene *scene, char *str);
int		lightid(t_scene *scene, char *str);
int		sphereid(t_scene *scene, char *str);
// Identifiers 2
int		planeid(t_scene *scene, char *str);
int		squareid(t_scene *scene, char *str);
int		cylinderid(t_scene *scene, char *str);
int		triangleid(t_scene *scene, char *str);
// Vec_rgb_reader
t_rgb	*rgb_reader(char *str, int *i);
t_vec3f	*vec_reader(char *str, int *i);
unsigned int	make_rgb(t_rgb vec);
// Init
void	scene_init(t_scene *scene);
t_object	*object_init(void);

// Print
void	rgbprint(t_rgb *rgb);
void	printvec3f(t_vec3f *vec);
void	printobject(t_object *object);
void	printscene(t_scene scene);
// Listfunctions
void	add_last_object(t_scene *scene, t_object *object);
void	camera_list_last(t_scene *scene, t_cam *cam);
void	light_list_last(t_scene *scene, t_light *light);
// Ray1c
int		ray_trace(t_scene *scene);

// Intersect
float	intersect(t_ray *ray, t_sphere *sphere);
#endif