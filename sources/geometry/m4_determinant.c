/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_determinant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:43:10 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/16 19:56:24 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

double			m4_determinant(t_matrix4 m)
{
	return ((double)m.t[0][3] * m.t[1][2] * m.t[2][1] * m.t[3][0] -
					m.t[0][2] * m.t[1][3] * m.t[2][1] * m.t[3][0] -
					m.t[0][3] * m.t[1][1] * m.t[2][2] * m.t[3][0] +
					m.t[0][1] * m.t[1][3] * m.t[2][2] * m.t[3][0] +
					m.t[0][2] * m.t[1][1] * m.t[2][3] * m.t[3][0] -
					m.t[0][1] * m.t[1][2] * m.t[2][3] * m.t[3][0] -
					m.t[0][3] * m.t[1][2] * m.t[2][0] * m.t[3][1] +
					m.t[0][2] * m.t[1][3] * m.t[2][0] * m.t[3][1] +
					m.t[0][3] * m.t[1][0] * m.t[2][2] * m.t[3][1] -
					m.t[0][0] * m.t[1][3] * m.t[2][2] * m.t[3][1] -
					m.t[0][2] * m.t[1][0] * m.t[2][3] * m.t[3][1] +
					m.t[0][0] * m.t[1][2] * m.t[2][3] * m.t[3][1] +
					m.t[0][3] * m.t[1][1] * m.t[2][0] * m.t[3][2] -
					m.t[0][1] * m.t[1][3] * m.t[2][0] * m.t[3][2] -
					m.t[0][3] * m.t[1][0] * m.t[2][1] * m.t[3][2] +
					m.t[0][0] * m.t[1][3] * m.t[2][1] * m.t[3][2] +
					m.t[0][1] * m.t[1][0] * m.t[2][3] * m.t[3][2] -
					m.t[0][0] * m.t[1][1] * m.t[2][3] * m.t[3][2] -
					m.t[0][2] * m.t[1][1] * m.t[2][0] * m.t[3][3] +
					m.t[0][1] * m.t[1][2] * m.t[2][0] * m.t[3][3] +
					m.t[0][2] * m.t[1][0] * m.t[2][1] * m.t[3][3] -
					m.t[0][0] * m.t[1][2] * m.t[2][1] * m.t[3][3] -
					m.t[0][1] * m.t[1][0] * m.t[2][2] * m.t[3][3] +
					m.t[0][0] * m.t[1][1] * m.t[2][2] * m.t[3][3]);
}