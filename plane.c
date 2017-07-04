/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	find_normal_plane(t_mod *mod, t_plane *plane)
{
	t_vector	scaled;

	mod->n = plane->n;
	scaled = vector_scale(mod->t, &mod->r.dir);
	mod->new_start = vector_add(&mod->r.start, &scaled);
}

int		intersect_plane(t_ray *r, t_plane *p, t_mod *mod)
{
	double a;
	double b;

	if (!(a = vector_dot(&p->n, &r->dir)))
		return (0);
	b = -(vector_dot(&p->n, &r->start) + p->d);
	if ((mod->t0 = b / a) > 0.0000001)
	{
		if (mod->t0 < mod->t)
		{
			mod->t = mod->t0;
			if (mod->light == 0)
				mod->cur_color = p->diffuse;
			mod->intersection++;
			mod->shadow = 1;
			return (1);
		}
	}
	return (0);
}
