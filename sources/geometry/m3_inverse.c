/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3_inverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:27:59 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/17 17:30:33 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_matrix3		m3_inverse(t_matrix3 m)
{
	double coef;

	coef = 1 / m3_determinant(m);
	return ((t_matrix3){
			(double)(coef * (m.t[1][1]*m.t[2][2] - m.t[1][2]*m.t[2][1])),
			(double)(coef * (m.t[0][2]*m.t[2][1] - m.t[0][1]*m.t[2][2])),
			(double)(coef * (m.t[0][1]*m.t[1][2] - m.t[0][2]*m.t[1][1])),
			(double)(coef * (m.t[1][2]*m.t[2][0] - m.t[1][0]*m.t[2][2])),
			(double)(coef * (m.t[0][0]*m.t[2][2] - m.t[0][2]*m.t[2][0])),
			(double)(coef * (m.t[0][2]*m.t[1][0] - m.t[0][0]*m.t[1][2])),
			(double)(coef * (m.t[1][0]*m.t[2][1] - m.t[1][1]*m.t[2][0])),
			(double)(coef * (m.t[0][1]*m.t[2][0] - m.t[0][0]*m.t[2][1])),
			(double)(coef * (m.t[0][0]*m.t[1][1] - m.t[0][1]*m.t[1][0])),
	});
}