/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_scene.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	sphere_scene_5(t_mod *mod)
{
	mod->ball[0].pos.x = 0;
	mod->ball[0].pos.y = 0;
	mod->ball[0].pos.z = -300;
	mod->ball[0].radius = 90;
	mod->ball[0].sq_radius = mod->ball[0].radius * mod->ball[0].radius;
	mod->ball[0].diffuse.red = 0.8;
	mod->ball[0].diffuse.green = 0.1;
	mod->ball[0].diffuse.blue = 0.1;
}

void	cylinder_scene_5(t_mod *mod)
{
	mod->cyl[0].r.start.x = -300;
	mod->cyl[0].r.start.y = 0;
	mod->cyl[0].r.start.z = -200;
	mod->cyl[0].r.dir.x = 0;
	mod->cyl[0].r.dir.y = -1;
	mod->cyl[0].r.dir.z = 0;
	mod->cyl[0].radius = 40;
	mod->cyl[0].sq_radius = mod->cyl[0].radius * mod->cyl[0].radius;
	mod->cyl[0].diffuse.red = 0.2;
	mod->cyl[0].diffuse.green = 0.2;
	mod->cyl[0].diffuse.blue = 0.7;
	mod->cyl[2] = mod->cyl[0];
	mod->cyl[2].r.start.z = -1000;
	mod->cyl[1] = mod->cyl[0];
	mod->cyl[1].r.start.x = 300;
	mod->cyl[3] = mod->cyl[2];
	mod->cyl[3].r.start.x = 300;
}

void	plane_scene_5(t_mod *mod)
{
	mod->plane[0].d = 100;
	mod->plane[0].n.x = 0;
	mod->plane[0].n.y = -1;
	mod->plane[0].n.z = 0;
	mod->plane[0].diffuse.red = 0;
	mod->plane[0].diffuse.green = 1;
	mod->plane[0].diffuse.blue = 1;
	mod->plane[1].d = 200;
	mod->plane[1].n.x = 0;
	mod->plane[1].n.y = 0;
	mod->plane[1].n.z = -1;
	mod->plane[1].diffuse.red = 1;
	mod->plane[1].diffuse.green = 1;
	mod->plane[1].diffuse.blue = 1;
	mod->plane[2].d = 300;
	mod->plane[2].n.x = 0;
	mod->plane[2].n.y = 1;
	mod->plane[2].n.z = 0;
	mod->plane[2].diffuse = mod->plane[0].diffuse;
}

void	scene_5(t_mod *mod)
{
	plane_scene_5(mod);
	sphere_scene_5(mod);
	cylinder_scene_5(mod);
}

void	find_closest_intersection_scene_5(t_mod *mod, t_ray *r)
{
	int i;

	if (intersect_sphere(r, &mod->ball[0], mod) && mod->light == 0)
		find_normal_sphere(mod, &mod->ball[0]);
	i = -1;
	while (++i < 3)
		if (intersect_plane(r, &mod->plane[i], mod) && mod->light == 0)
			find_normal_plane(mod, &mod->plane[i]);
	i = -1;
	while (++i < 4)
		if (intersect_cylinder(r, &mod->cyl[i], mod) && mod->light == 0)
			find_normal_cylinder(mod, &mod->cyl[i]);
}
