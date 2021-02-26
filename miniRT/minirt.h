#ifndef MINIRT_H
# define MINIRT_H

#include <math.h>

typedef unsigned char uchar;

typedef struct image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		linesize;
	int		endian;
}	t_img;

typedef struct vector
{
	int x;
	int y;
	int z;
}	vec;

typedef struct color_data
{
	int r;
	int g;
	int b;
	int a;
}	color;

typedef struct camera_data
{
	vec pos;
	vec direction;
	int fov;
}	camera;

typedef struct light_data
{
	color color;
	vec pos;
	float brightness;
}	light;

typedef struct obj_sphere
{
	vec pos;
	color color;
	float diameter;
}	sphere;

typedef struct ambient
{
	color color;
	float intensity;
}	amb_light;

typedef struct 3d_plane
{
	vec pos;
	vec normal;
	color color;
}	plane;

typedef struct 3d_square
{
	vec 	center;
	float	side;
	vec 	normal;
	color color;
}	square;

typedef struct 3d_cylinder
{
	vec pos;
	float height;
	float diameter;
	vec normal;
	color color;
}	cylinder;

typedef struct 3d_triangle
{
	vec 1p;
	vec 2p;
	vec 3p;
	color color;
}	triangle;

typedef struct scene_data
{
	int			res_height;
	int			res_width;
	amb_light	ambient;
	camera		cam;
	light		light;
}	scene;

#endif
