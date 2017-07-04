/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	scene_2(t_mod *mod)
{
	mod->cyl[0].r.start.x = 0;
	mod->cyl[0].r.start.y = 0;
	mod->cyl[0].r.start.z = -200;
	mod->cyl[0].r.dir.x = 0;
	mod->cyl[0].r.dir.y = -1;
	mod->cyl[0].r.dir.z = 0;
	mod->cyl[0].radius = 50;
	mod->cyl[0].sq_radius = mod->cyl[0].radius * mod->cyl[0].radius;
	mod->cyl[0].diffuse.red = 0.1;
	mod->cyl[0].diffuse.green = 0.1;
	mod->cyl[0].diffuse.blue = 0.8;
}

void	find_closest_intersection_scene_2(t_mod *mod, t_ray *r)
{
	if (intersect_cylinder(r, &mod->cyl[0], mod) && mod->light == 0)
		find_normal_cylinder(mod, &mod->cyl[0]);
}
