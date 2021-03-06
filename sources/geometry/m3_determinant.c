/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3_determinant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1008/05/06 09:47:54 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/16 19:57:18 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

double		m3_determinant(t_matrix3 m)
{
	return ((double)m.t[0][0] * m.t[1][1] * m.t[2][2] +
					m.t[0][1] * m.t[1][2] * m.t[2][0] +
					m.t[0][2] * m.t[1][2] * m.t[2][1] -
					m.t[0][0] * m.t[1][2] * m.t[2][1] -
					m.t[0][1] * m.t[1][0] * m.t[2][2] -
					m.t[0][2] * m.t[1][1] * m.t[2][0]);
}
