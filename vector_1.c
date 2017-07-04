/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:19:15 by rmalkevy          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** Normalize vector and return the resulting vector
*/

t_vector	vector_normalize(t_vector *n)
{
	double temp;

	temp = vector_dot(n, n);
	if (temp != 0)
		temp = 1.0f / sqrt(temp);
	return (vector_scale(temp, n));
}

/*
** Multiply two vectors and return the resulting vector
*/

t_vector	vector_mult(t_vector *v1, t_vector *v2)
{
	t_vector result;

	result.x = v1->y * v2->z - v1->z * v2->y;
	result.y = v1->z * v2->x - v1->x * v2->z;
	result.z = v1->x * v2->y - v1->y * v2->x;
	return (result);
}

/*
** Find cos of two vectors
*/

double		vector_cos(t_vector *v1, t_vector *v2)
{
	double a;
	double b;
	double c;
	double cos;

	a = vector_dot(v1, v2);
	b = vector_dot(v1, v1);
	c = vector_dot(v2, v2);
	cos = a / (b * c);
	return (cos);
}

/*
** Find sin of two vectors
*/

double		vector_sin(t_vector *v1, t_vector *v2)
{
	double cos;
	double sin;

	cos = vector_cos(v1, v2);
	sin = sqrt(1 - cos * cos);
	return (sin);
}
