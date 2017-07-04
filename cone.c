/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	find_normal_cone(t_mod *mod, t_cone *cone)
{
	t_vector scaled;
	t_vector b;
	t_vector a;

	scaled = vector_scale(mod->t, &mod->r.dir);
	mod->new_start = vector_add(&mod->r.start, &scaled);
	b = vector_sub(&mod->new_start, &cone->r.start);
	a = vector_scale(vector_cos(&b, &cone->r.dir), &cone->r.dir);
	mod->n = vector_sub(&b, &a);
	scaled = vector_mult(&b, &mod->n);
	mod->n = vector_mult(&scaled, &b);
	mod->n = vector_normalize(&mod->n);
}

void	find_abc_for_cone(t_ray *r, t_cone *cone, t_mod *mod)
{
	double		dot[2];
	t_vector	mult[2];
	t_vector	sub[2];
	t_vector	delta_p;

	delta_p = vector_sub(&r->start, &cone->r.start);
	dot[A] = vector_dot(&r->dir, &cone->r.dir);
	mult[A] = vector_scale(dot[A], &cone->r.dir);
	sub[A] = vector_sub(&r->dir, &mult[A]);
	dot[B] = vector_dot(&delta_p, &cone->r.dir);
	mult[B] = vector_scale(dot[B], &cone->r.dir);
	sub[B] = vector_sub(&delta_p, &mult[B]);
	mod->a = cone->sq_cos * vector_dot(&sub[A], &sub[A]);
	mod->a -= cone->sq_sin * dot[A] * dot[A];
	mod->b = 2 * cone->sq_cos * vector_dot(&sub[A], &sub[B]);
	mod->b -= 2 * cone->sq_sin * dot[A] * dot[B];
	mod->c = cone->sq_cos * vector_dot(&sub[B], &sub[B]);
	mod->c -= cone->sq_sin * dot[B] * dot[B];
}

/*
** Check if the ray and cone intersect
*/

int		intersect_cone(t_ray *r, t_cone *cone, t_mod *mod)
{
	double discr;
	double sqrtdiscr;
	double t;

	find_abc_for_cone(r, cone, mod);
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
			mod->cur_color = cone->diffuse;
		mod->intersection++;
		mod->shadow = 1;
		return (1);
	}
	return (0);
}
