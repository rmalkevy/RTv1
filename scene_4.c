/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	sphere_plane_scene_4(t_mod *mod)
{
	mod->ball[0].pos.x = 0;
	mod->ball[0].pos.y = 0;
	mod->ball[0].pos.z = -300;
	mod->ball[0].radius = 100;
	mod->ball[0].sq_radius = mod->ball[0].radius * mod->ball[0].radius;
	mod->ball[0].diffuse.red = 0.8;
	mod->ball[0].diffuse.green = 0.1;
	mod->ball[0].diffuse.blue = 0.1;
	mod->plane[0].d = 100;
	mod->plane[0].n.x = 0;
	mod->plane[0].n.y = -1;
	mod->plane[0].n.z = 0;
	mod->plane[0].diffuse.red = 1;
	mod->plane[0].diffuse.green = 1;
	mod->plane[0].diffuse.blue = 1;
}

void	cylinder_scene_4(t_mod *mod)
{
	mod->cyl[0].r.start.x = 0;
	mod->cyl[0].r.start.y = 0;
	mod->cyl[0].r.start.z = -250;
	mod->cyl[0].r.dir.x = 0;
	mod->cyl[0].r.dir.y = -1;
	mod->cyl[0].r.dir.z = 0;
	mod->cyl[0].radius = 80;
	mod->cyl[0].sq_radius = mod->cyl[0].radius * mod->cyl[0].radius;
	mod->cyl[0].diffuse.red = 0.2;
	mod->cyl[0].diffuse.green = 0.2;
	mod->cyl[0].diffuse.blue = 0.7;
}

void	cone_scene_4(t_mod *mod)
{
	mod->cone.r.start.x = 0;
	mod->cone.r.start.y = -100;
	mod->cone.r.start.z = -300;
	mod->cone.r.dir.x = -0.707;
	mod->cone.r.dir.y = -0.707;
	mod->cone.r.dir.z = 0;
	mod->cone.angle = 20 * M_PI / 180;
	mod->cone.diffuse.red = 0.3;
	mod->cone.diffuse.green = 0.2;
	mod->cone.diffuse.blue = 0.4;
	mod->cone.sq_cos = cos(mod->cone.angle) * cos(mod->cone.angle);
	mod->cone.sq_sin = sin(mod->cone.angle) * sin(mod->cone.angle);
}

void	scene_4(t_mod *mod)
{
	cone_scene_4(mod);
	sphere_plane_scene_4(mod);
	cylinder_scene_4(mod);
}

void	find_closest_intersection_scene_4(t_mod *mod, t_ray *r)
{
	if (intersect_sphere(r, &mod->ball[0], mod) && mod->light == 0)
		find_normal_sphere(mod, &mod->ball[0]);
	if (intersect_plane(r, &mod->plane[0], mod) && mod->light == 0)
		find_normal_plane(mod, &mod->plane[0]);
	if (intersect_cylinder(r, &mod->cyl[0], mod) && mod->light == 0)
		find_normal_cylinder(mod, &mod->cyl[0]);
	if (intersect_cone(r, &mod->cone, mod) && mod->light == 0)
		find_normal_cone(mod, &mod->cone);
}
