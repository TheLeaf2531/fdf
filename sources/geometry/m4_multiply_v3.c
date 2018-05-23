/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_multiply_v3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:50:39 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/18 18:07:13 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_vector3		m4_multiply_v3(t_matrix4 m, t_vector3 v)
{
	t_vector3 v_m;

	v_m = (t_vector3){
		m.t[0][0] * v.x + m.t[1][0] * v.y + m.t[2][0] * v.z + m.t[3][0],
		m.t[0][1] * v.x + m.t[1][1] * v.y + m.t[2][1] * v.z + m.t[3][1],
		m.t[0][2] * v.x + m.t[1][2] * v.y + m.t[2][2] * v.z + m.t[3][2],
		m.t[0][3] * v.x + m.t[1][3] * v.y + m.t[2][3] * v.z + m.t[3][3]
	};
	return ((t_vector3){
		v_m.x / v_m.w,
		v_m.y / v_m.w,
		v_m.z / v_m.w,
		(double)1.0
	});
}
