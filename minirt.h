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
	t_vec3f			place;
	t_vec3f			direction;
}					t_ray;

typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

typedef struct		s_amb
{
	float			ratio;
	t_rgb			rgb;
}					t_amb;

typedef struct		s_cam
{
	t_vec3f			place;
	t_vec3f			direction;
	int				fov;
}					t_cam;

typedef struct		s_light
{
	t_vec3f			place;
	float			brightness;
	t_rgb			rgb;
	void			*next;
}					t_light;

typedef struct		s_sphere
{
	t_vec3f			place;
	float			dia;
	t_rgb			rgb;
}					t_sphere;

typedef struct		s_plane
{
	t_vec3f			place;
	t_vec3f			direction;
	t_rgb			rgb;
}					t_plane;

// typedef struct		s_square
// {
// 	t_vec3f			*place;
// 	t_vec3f			*direction;
// 	float			size;
// 	t_rgb			*rgb;
// }					t_square;

typedef struct		s_cylinder
{
	t_vec3f			place;
	t_vec3f			direction;
	float			diam;
	float			height;
	t_rgb			rgb;
}					t_cylinder;

// typedef struct		s_triangle
// {
// 	t_vec3f			*p1;
// 	t_vec3f			*p2;
// 	t_vec3f			*p3;
// 	t_rgb			*rgb;
// }					t_triangle;

typedef struct			s_object
{
	int					is_sphere;
	t_sphere			sphere;
	int					is_plane;
	t_plane				plane;
	// t_square			*square;
	int					is_cylinder;
	t_cylinder			cylinder;
	// t_triangle			*triangle;
	void				*next;
}						t_object;

// typedef struct			s_img
// {
// 	// void				*img_ptr;
// 	// char				*address;
// 	int					bits_per_pixel;
// 	int					line_size;
// 	int					endian;
// }						t_img;

typedef struct			s_scene
{
	void				*mlx;
	void				*window;
	void				*img_ptr;
	char				*address;
	int					bits_per_pixel;
	int					line_size;
	int					endian;
	// t_img				*img;
	int					res_is_set;
	int					amb_is_set;
	int					cam_is_set;

	t_res				resolution;
	t_amb				ambient;
	t_cam				camera;
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
t_rgb	rgb_reader(char *str, int *i);
t_vec3f	vec_reader(char *str, int *i);
unsigned int	make_rgb(t_rgb vec, float ratio);
t_rgb	get_rgb(t_object *object);
void	rgb_ratio(t_rgb	*rgb, float fr);
// Init
void		scene_init(t_scene *scene);
t_object	*object_init(void);
t_vec3f		vec3f_init(void);
t_ray	ray_init(void);

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
void		freeray(t_ray *ray);
t_ray		make_camera_ray(t_scene scene, int x, int y);
t_object	*intersect_object_list(t_scene scene, t_ray ray);
int			ray_trace(t_scene scene);

// Intersect
float	intersect(t_ray ray, t_object *object_list);
float	intersect_sphere(t_ray ray, t_sphere sphere);
float	intersect_plane(t_ray ray, t_plane plane);

// Minirt.c
void	my_mlx_pixel_put(t_scene scene, int x, int y, unsigned int color);
// Ray_math
t_vec3f	vector_deduction(t_vec3f a, t_vec3f b);
float	dotproduct(t_vec3f a, t_vec3f b);
t_vec3f	normalize_vector(t_vec3f direction);
t_vec3f	find_coordinates(t_ray ray, float distance);
// Lightray
t_ray	make_light_ray(t_scene scene, t_vec3f int_point);
t_ray	light_object_distance(t_scene *scene, t_vec3f *int_point, float *distance);
t_ray	light_reaches_point(t_scene *scene, t_ray *ray, float dist_cam_obj, t_vec3f intersection_point);
unsigned int	compute_shading(t_scene scene, t_ray ray, float distance, t_object *object);
// Normal
t_vec3f	find_normal_at_point(t_object *object, t_vec3f intersection_point);
t_vec3f	find_sphere_normal(t_sphere sphere, t_vec3f int_point);

#endif
