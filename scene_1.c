/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	scene_1(t_mod *mod)
{
	mod->ball[0].pos.x = 0;
	mod->ball[0].pos.y = 0;
	mod->ball[0].pos.z = -300;
	mod->ball[0].radius = 100;
	mod->ball[0].sq_radius = mod->ball[0].radius * mod->ball[0].radius;
	mod->ball[0].diffuse.red = 0.8;
	mod->ball[0].diffuse.green = 0.1;
	mod->ball[0].diffuse.blue = 0.1;
}

/*
** Find closest intersection
*/

void	find_closest_intersection_scene_1(t_mod *mod, t_ray *r)
{
	if (intersect_sphere(r, &mod->ball[0], mod) && mod->light == 0)
		find_normal_sphere(mod, &mod->ball[0]);
}
