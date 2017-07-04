/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	find_normal_cylinder(t_mod *mod, t_cylinder *cyl)
{
	t_vector scaled;
	t_vector b;
	t_vector a;
	t_vector rv;

	scaled = vector_scale(mod->t, &mod->r.dir);
	mod->new_start = vector_add(&mod->r.start, &scaled);
	b = vector_sub(&mod->new_start, &cyl->r.start);
	a = vector_scale(vector_dot(&b, &cyl->r.dir), &cyl->r.dir);
	rv = vector_sub(&b, &a);
	mod->n = vector_normalize(&rv);
}

void	find_abc_for_cylynder(t_ray *r, t_cylinder *cyl, t_mod *mod)
{
	double		dot;
	t_vector	mult;
	t_vector	sub1;
	t_vector	sub2;
	t_vector	delta_p;

	dot = vector_dot(&r->dir, &cyl->r.dir);
	mult = vector_scale(dot, &cyl->r.dir);
	sub1 = vector_sub(&r->dir, &mult);
	delta_p = vector_sub(&r->start, &cyl->r.start);
	dot = vector_dot(&delta_p, &cyl->r.dir);
	mult = vector_scale(dot, &cyl->r.dir);
	sub2 = vector_sub(&delta_p, &mult);
	mod->a = vector_dot(&sub1, &sub1);
	mod->b = 2 * vector_dot(&sub1, &sub2);
	mod->c = vector_dot(&sub2, &sub2) - cyl->sq_radius;
}

/*
** Check if the ray and cylinder intersect
*/

int		intersect_cylinder(t_ray *r, t_cylinder *cyl, t_mod *mod)
{
	double	discr;
	double	sqrtdiscr;
	double	t;

	find_abc_for_cylynder(r, cyl, mod);
	discr = mod->b * mod->b - 4 * mod->a * mod->c;
	if (discr < 0)
		return (0);
	sqrtdiscr = sqrt(discr);
	mod->t0 = (-mod->b + sqrtdiscr) / (2 * mod->a);
	mod->t1 = (-mod->b - sqrtdiscr) / (2 * mod->a);
	t = min_distance(mod);
	if (t < mod->t && t > 0.00001)
	{
		mod->t = t;
		if (mod->light == 0)
			mod->cur_color = cyl->diffuse;
		mod->intersection++;
		mod->shadow = 1;
		return (1);
	}
	return (0);
}
