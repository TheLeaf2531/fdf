/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_inverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 20:04:31 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/22 16:39:43 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_matrix4		m4_inverse(t_matrix4 m)
{
	double		coef;
	t_matrix4	rot;

	coef = 1.0 / m4_determinant(m);
	rot = (t_matrix4){{
		{(double)(coef * (m.t[1][1] * m.t[2][2] - m.t[1][2] * m.t[2][1])),
		(double)(coef * (m.t[0][2] * m.t[2][1] - m.t[0][1] * m.t[2][2])),
		(double)(coef * (m.t[0][1] * m.t[1][2] - m.t[0][2] * m.t[1][1])),
		(double)0.0},
		{(double)(coef * (m.t[1][2] * m.t[2][0] - m.t[1][0] * m.t[2][2])),
		(double)(coef * (m.t[0][0] * m.t[2][2] - m.t[0][2] * m.t[2][0])),
		(double)(coef * (m.t[0][2] * m.t[1][0] - m.t[0][0] * m.t[1][2])),
		(double)0.0},
		{(double)(coef * (m.t[1][0] * m.t[2][1] - m.t[1][1] * m.t[2][0])),
		(double)(coef * (m.t[0][1] * m.t[2][0] - m.t[0][0] * m.t[2][1])),
		(double)(coef * (m.t[0][0] * m.t[1][1] - m.t[0][1] * m.t[1][0])),
		(double)0.0}, {(double)0.0, (double)0.0, (double)0.0, (double)1.0}}};
	rot.t[3][0] = -m.t[3][0] * rot.t[0][0] +
	-m.t[3][1] * rot.t[1][0] + -m.t[3][2] * rot.t[2][0];
	rot.t[3][1] = -m.t[3][0] * rot.t[0][1] +
	-m.t[3][1] * rot.t[1][1] + -m.t[3][2] * rot.t[2][1];
	rot.t[3][2] = -m.t[3][0] * rot.t[0][2] +
	-m.t[3][1] * rot.t[1][2] + -m.t[3][2] * rot.t[2][2];
	return (rot);
}
