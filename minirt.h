#ifndef MINIRT_H
#define MINIRT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include "libft.h"
#include <math.h>


// void			*img;
    // char        	*addr;
    // int         	bits_per_pixel;

typedef struct  	s_vec3f
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
}					t_cam;

typedef struct		s_light
{
	t_vec3f			*place;
	float			brightness;
	t_rgb			*rgb;
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

typedef struct			s_scene
{
	void				*mlx;
	t_vec3f				*framebuffer;
	t_res				*resolution;
	t_amb				*ambient;
	t_cam				*camera;
	t_light				*light;
	t_sphere			*sphere;
	t_plane				*plane;
	t_square			*square;
	t_cylinder			*cylinder;
	t_triangle			*triangle;
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

#endif