/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	cone_scene_3(t_mod *mod)
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

void	plane_scene_3(t_mod *mod)
{
	mod->plane[0].d = 100;
	mod->plane[0].n.x = 0;
	mod->plane[0].n.y = -1;
	mod->plane[0].n.z = 0;
	mod->plane[0].diffuse.red = 1;
	mod->plane[0].diffuse.green = 1;
	mod->plane[0].diffuse.blue = 1;
}

void	scene_3(t_mod *mod)
{
	cone_scene_3(mod);
	plane_scene_3(mod);
}

void	find_closest_intersection_scene_3(t_mod *mod, t_ray *r)
{
	if (intersect_plane(r, &mod->plane[0], mod) && mod->light == 0)
		find_normal_plane(mod, &mod->plane[0]);
	if (intersect_cone(r, &mod->cone, mod) && mod->light == 0)
		find_normal_cone(mod, &mod->cone);
}
