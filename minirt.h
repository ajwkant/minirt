#ifndef MINIRT_H
#define MINIRT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

typedef struct		s_list
{

}					t_list;

typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

typedef struct		s_amb
{
	float			ratio;
	int				r;
	int				g;
	int				b;
}					t_amb;

typedef struct		s_cam
{
	float			x;
	float			y;
	float			z;
	int				vx;
	int				vy;
	int				vz;
	int				fov;
}					t_cam

typedef struct		s_light
{
	float			x;
	float			y;
	float			z;
	float			brightness;
	int				r;
	int				g;
	int				b;
}					t_light

typedef struct		s_sphere
{
	float			x;
	float			y;
	float			z;
	float			dia;
	int				r;
	int				g;
	int				b;
}					t_sphere

typedef struct		s_plane
{
	float			x;
	float			y;
	float			z;
	float			xv;
	float			vy;
	float			vz;
	int				r;
	int				g;
	int				b;
}					t_plane

typedef struct		s_square
{
	float			x;
	float			y;
	float			z;
	float			xv;
	float			vy;
	float			vz;
	float			size;
	int				r;
	int				g;
	int				b;
}					t_square

typedef struct		s_cylinder
{
	float			x;
	float			y;
	float			z;
	float			xv;
	float			vy;
	float			vz;
	float			diam;
	float			height;
	int				r;
	int				g;
	int				b;
}					t_cylinder

typedef struct		s_triangle
{
	float			x1;
	float			y1;
	float			z1;
	float			x2;
	float			y2;
	float			z2;
	float			x3;
	float			y3;
	float			z3;
	int				r;
	int				g;
	int				b;
}					t_triangle



#endif