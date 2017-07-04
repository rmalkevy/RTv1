/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_lights(t_mod *mod)
{
	mod->lit[0].pos.x = 0;
	mod->lit[0].pos.y = -200;
	mod->lit[0].pos.z = -2500;
	mod->lit[0].intensity.red = 1;
	mod->lit[0].intensity.green = 1;
	mod->lit[0].intensity.blue = 1;
	mod->lit[1].pos.x = -1000;
	mod->lit[1].pos.y = -200;
	mod->lit[1].pos.z = -1500;
	mod->lit[1].intensity.red = 1;
	mod->lit[1].intensity.green = 1;
	mod->lit[1].intensity.blue = 1;
}

void	init_pixel(t_mod *mod, t_vector *pixel)
{
	t_vector	abs;
	double		a;

	abs.x = pixel->x - mod->r.start.x;
	abs.y = pixel->y - mod->r.start.y;
	abs.z = pixel->z - mod->r.start.z;
	if ((a = sqrt(vector_dot(&abs, &abs))))
	{
		mod->r.dir.x = abs.x / a;
		mod->r.dir.y = abs.y / a;
		mod->r.dir.z = abs.z / a;
	}
}

void	init_mod(t_mod *mod)
{
	int		i;
	void	(*scene)(t_mod *);

	i = -1;
	init_rot(mod);
	calculation_rotation(&mod[0].rot);
	scene = mod->scene;
	while (++i < THREAD)
	{
		scene(&mod[i]);
		init_lights(&mod[i]);
		mod[i].y_cur = (i + 1) * (HEIGHT / THREAD);
		mod[i].rot = mod[0].rot;
		mod[i].r.start.x = 0;
		mod[i].r.start.y = 0;
		mod[i].r.start.z = CAM_START;
		mod[i].cam_distance = 0;
	}
}
