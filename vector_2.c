/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** Find lenght of vector
*/

double		vector_len(t_vector *v1, t_vector *v2)
{
	double a;

	a = vector_dot(v1, v2);
	return (sqrt(a));
}

/*
** Subtract two vectors and return the resulting vector
*/

t_vector	vector_sub(t_vector *v1, t_vector *v2)
{
	t_vector result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

/*
** Multiply two vectors and return the resulting scalar (dot product)
*/

double		vector_dot(t_vector *v1, t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

/*
** Calculate Vector x Scalar and return resulting Vector
*/

t_vector	vector_scale(double t, t_vector *v)
{
	t_vector result;

	result.x = v->x * t;
	result.y = v->y * t;
	result.z = v->z * t;
	return (result);
}

/*
** Add two vectors and return the resulting vector
*/

t_vector	vector_add(t_vector *v1, t_vector *v2)
{
	t_vector result;

	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return (result);
}
