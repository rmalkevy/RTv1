/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		init_rot(t_mod *mod)
{
	int i;

	i = -1;
	while (++i < THREAD)
	{
		mod[i].rot.angl_x = 0;
		mod[i].rot.angl_y = 0;
		mod[i].rot.angl_z = 0;
	}
}

void		calculation_rotation(t_rot *rot)
{
	rot->cy_cz = cos(rot->angl_y) * cos(rot->angl_z);
	rot->sy_sx = sin(rot->angl_y) * sin(rot->angl_x);
	rot->cy_sz_cx = cos(rot->angl_y) * sin(rot->angl_z) * cos(rot->angl_x);
	rot->sum1 = rot->sy_sx - rot->cy_sz_cx;
	rot->cy_sz_sx = cos(rot->angl_x) * sin(rot->angl_z) * sin(rot->angl_x);
	rot->sy_cx = sin(rot->angl_y) * cos(rot->angl_x);
	rot->sum2 = rot->cy_sz_sx + rot->sy_cx;
	rot->sz = sin(rot->angl_z);
	rot->cz_cx = cos(rot->angl_z) * cos(rot->angl_x);
	rot->cz_sx = -cos(rot->angl_z) * sin(rot->angl_x);
	rot->sy_cz = -sin(rot->angl_y) * cos(rot->angl_z);
	rot->sy_sz_cx = sin(rot->angl_y) * sin(rot->angl_z) * cos(rot->angl_x);
	rot->cy_cx = cos(rot->angl_y) * cos(rot->angl_x);
	rot->sx_cy = sin(rot->angl_x) * cos(rot->angl_y);
	rot->sum3 = rot->sy_sz_cx + rot->sx_cy;
	rot->sx_sy_sz = sin(rot->angl_x) * sin(rot->angl_y) * sin(rot->angl_z);
	rot->sum4 = rot->cy_cx - rot->sx_sy_sz;
}

t_vector	rot_coordinate(t_rot *rot, t_vector *v)
{
	double	x;
	double	y;
	double	z;

	x = v->x;
	y = v->y;
	z = v->z;
	v->x = x * rot->cy_cz + y * rot->sum1 + z * rot->sum2;
	v->y = x * rot->sz + y * rot->cz_cx + z * rot->cz_sx;
	v->z = x * rot->sy_cz + y * rot->sum3 + z * rot->sum4;
	return (*v);
}
