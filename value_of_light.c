/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_of_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** Lambert diffusion
*/

void	lambert(t_ray *light_ray, t_mod *mod)
{
	double lambert;

	lambert = vector_dot(&light_ray->dir, &mod->n);
	if (mod->shadow == 0)
	{
		mod->red += (0.8 - mod->cur_color.red) * pow(lambert, 15) * 0.9;
		mod->green += (0.8 - mod->cur_color.green) * pow(lambert, 15) * 0.9;
		mod->blue += (0.8 - mod->cur_color.blue) * pow(lambert, 15) * 0.9;
		mod->opacity *= (1 - pow(lambert, 2));
	}
}

void	color(t_mod *mod, t_light *current_light)
{
	mod->red = current_light->intensity.red * mod->cur_color.red;
	mod->green = current_light->intensity.green * mod->cur_color.green;
	mod->blue = current_light->intensity.blue * mod->cur_color.blue;
}

/*
** Find the value of the light at this point
*/

void	value_of_light(t_mod *mod)
{
	void		(*find_shadow)(t_mod *, t_ray *);
	t_ray		light_ray;
	t_light		current_light;
	t_vector	dist;

	find_shadow = mod->find_intersection;
	mod->shadow = 0;
	mod->light = 1;
	current_light = mod->lit[0];
	color(mod, &current_light);
	dist = vector_sub(&current_light.pos, &mod->new_start);
	mod->t = vector_len(&dist, &dist);
	if (vector_dot(&mod->n, &dist) <= 0.0f)
		return ;
	light_ray.start = mod->new_start;
	light_ray.dir = vector_normalize(&dist);
	find_shadow(mod, &light_ray);
	lambert(&light_ray, mod);
}
