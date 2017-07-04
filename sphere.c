/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** Find the normal for this new vector at the point of intersection
*/

void	find_normal_sphere(t_mod *mod, t_sphere *ball)
{
	t_vector scaled;

	scaled = vector_scale(mod->t, &mod->r.dir);
	mod->new_start = vector_add(&mod->r.start, &scaled);
	mod->n = vector_sub(&mod->new_start, &ball->pos);
	mod->n = vector_normalize(&mod->n);
}

/*
** Check if the ray and sphere intersect
** A = d * d, the vector dot product of the direction:
** a = vectorDot(r->dir, r->dir);
** We need a vector representing the distance between the start of
** the ray and the position of the circle.
** This is the term (p0 - c)
** dist = vector_sub(r->start, s->pos);
** 2d * (p0 - c)
** b = 2 * vectorDot(r->dir, dist);
** (p0 - c) * (p0 - c) - r^2
** c = vector_dot(dist, dist) - (s->radius * s->radius);
** Solving the discriminant
** discr = b * b - 4 * a * c;
** If the discriminant is negative, there are no real roots.
** Return false in that case as the ray misses the sphere.
** Return true in all other cases (can be one or two intersections)
** t represents the distance between the start of the ray and
** the point on the sphere where it intersects.
*/

int		intersect_sphere(t_ray *r, t_sphere *s, t_mod *mod)
{
	double discr;
	double sqrtdiscr;
	double t;

	mod->a = vector_dot(&r->dir, &r->dir);
	mod->dist = vector_sub(&r->start, &s->pos);
	mod->b = 2 * vector_dot(&r->dir, &mod->dist);
	mod->c = vector_dot(&mod->dist, &mod->dist) - s->sq_radius;
	discr = mod->b * mod->b - 4 * mod->a * mod->c;
	if (discr < 0)
		return (0);
	sqrtdiscr = sqrt(discr);
	mod->t0 = (-mod->b + sqrtdiscr) / 2;
	mod->t1 = (-mod->b - sqrtdiscr) / 2;
	t = min_distance(mod);
	if (t < mod->t && t > 0.00001)
	{
		mod->t = t;
		if (mod->light == 0)
			mod->cur_color = s->diffuse;
		mod->intersection++;
		mod->shadow = 1;
		return (1);
	}
	return (0);
}
