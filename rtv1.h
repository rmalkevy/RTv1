/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:14:16 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 14:14:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RTV1_H
# define _RTV1_H
# include "libft/libft.h"
# include <math.h>
# include "minilibx/mlx.h"
# include <pthread.h>

# define WIDTH			1000
# define HALF_WIDTH		WIDTH / 2
# define HEIGHT			800
# define HALF_HEIGHT	HEIGHT / 2
# define THREAD			8
# define SAMPLES		1
# define ANGLE			M_PI / 300
# define CAM_START		-4000
# define DISTANCE		100
# define LIGHTS			1
# define A				0
# define B				1

/*
** The vector structure
*/

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

/*
** The ray
*/

typedef struct	s_ray
{
	t_vector	start;
	t_vector	dir;
}				t_ray;

/*
** Color
*/

typedef struct	s_color
{
	double		red;
	double		green;
	double		blue;
}				t_color;

/*
** The sphere
*/

typedef struct	s_sphere
{
	t_vector	pos;
	double		radius;
	double		sq_radius;
	t_color		diffuse;
}				t_sphere;

/*
** The plane
*/

typedef struct	s_plane
{
	double		d;
	t_vector	n;
	t_color		diffuse;
}				t_plane;

/*
** The cylinder
*/

typedef struct	s_cylinder
{
	t_ray		r;
	double		radius;
	double		sq_radius;
	t_color		diffuse;
}				t_cylinder;

/*
** The cone
*/

typedef struct	s_cone
{
	t_ray		r;
	double		angle;
	t_color		diffuse;
	double		sq_cos;
	double		sq_sin;
}				t_cone;

/*
** Lightsource definition
*/

typedef struct	s_light
{
	t_vector	pos;
	t_color		intensity;
}				t_light;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*image;
	char		*line;
}				t_win;

typedef struct	s_rot
{
	double		angl_x;
	double		angl_y;
	double		angl_z;
	double		cy_cz;
	double		sy_sx;
	double		cy_sz_cx;
	double		sum1;
	double		cy_sz_sx;
	double		sy_cx;
	double		sum2;
	double		sz;
	double		cz_cx;
	double		cz_sx;
	double		sy_cz;
	double		sy_sz_cx;
	double		cy_cx;
	double		sx_cy;
	double		sx_sy_sz;
	double		sum3;
	double		sum4;
}				t_rot;

typedef struct	s_mod
{
	double		opacity;
	double		cam_distance;
	double		a;
	double		b;
	double		c;
	double		dot1;
	double		dot2;
	t_vector	delta_p;
	double		cos;
	double		sin;
	double		red;
	double		green;
	double		blue;
	double		t;
	double		t0;
	double		t1;
	int			y_cur;
	int			intersection;
	int			light;
	int			shadow;
	t_ray		r;
	t_light		lit[3];
	t_sphere	ball[5];
	t_plane		plane[3];
	t_cylinder	cyl[4];
	t_cone		cone;
	t_color		cur_color;
	t_vector	dist;
	t_vector	new_start;
	t_vector	n;
	t_win		*w;
	t_rot		rot;
	void		*find_intersection;
	void		*scene;
}				t_mod;
void			find_closest_intersection_scene_1(t_mod *mod, t_ray *r);
void			find_closest_intersection_scene_2(t_mod *mod, t_ray *r);
void			find_closest_intersection_scene_3(t_mod *mod, t_ray *r);
void			find_closest_intersection_scene_4(t_mod *mod, t_ray *r);
void			find_closest_intersection_scene_5(t_mod *mod, t_ray *r);
int				my_key_funct(int keycode, t_mod *mod);
void			init_mod(t_mod *mod);
t_vector		vector_sub(t_vector *v1, t_vector *v2);
double			vector_dot(t_vector *v1, t_vector *v2);
t_vector		vector_scale(double c, t_vector *v);
t_vector		vector_add(t_vector *v1, t_vector *v2);
double			vector_len(t_vector *v1, t_vector *v2);
double			vector_cos(t_vector *v1, t_vector *v2);
double			vector_sin(t_vector *v1, t_vector *v2);
t_vector		vector_mult(t_vector *v1, t_vector *v2);
t_vector		vector_normalize(t_vector *n);
double			min_distance(t_mod *mod);
void			find_normal_sphere(t_mod *mod, t_sphere *ball);
void			find_normal_cylinder(t_mod *mod, t_cylinder *cyl);
void			find_normal_cone(t_mod *mod, t_cone *cone);
void			find_normal_plane(t_mod *mod, t_plane *plane);
int				intersect_sphere(t_ray *r, t_sphere *s, t_mod *mod);
int				intersect_plane(t_ray *r, t_plane *plane, t_mod *mod);
int				intersect_cylinder(t_ray *r, t_cylinder *cyl, t_mod *mod);
int				intersect_cone(t_ray *r, t_cone *cone, t_mod *mod);
void			init_pixel(t_mod *mod, t_vector *pixel);
void			value_of_light(t_mod *mod);
void			put_color_to_pixel(t_mod *mod, double x, double y);
void			color_zero(t_mod *mod);
void			calculation_rotation(t_rot *rot);
t_vector		rot_coordinate(t_rot *rot, t_vector *v);
void			init_rot(t_mod *mod);
void			write_to_image(t_mod *mod);
void			create_image(t_mod *mod);
void			scene_1(t_mod *mod);
void			scene_2(t_mod *mod);
void			scene_3(t_mod *mod);
void			scene_4(t_mod *mod);
void			scene_5(t_mod *mod);
void			work_with_scene(t_mod *mod, int num);
int				error(char *av);

#endif
