/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_euler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:57:49 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/23 20:21:57 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_matrix4		m4_euler(t_vector3 r)
{
	r = vec3_to_radians(r);
	return ((t_matrix4){{
			{(double)(cos(r.x) * cos(r.y)),
			(double)(cos(r.y) * sin(r.x)),
			(double)(-sin(r.y)),
			(double)0.0},
			{(double)(cos(r.x) * sin(r.y) * sin(r.z) - cos(r.z) * sin(r.x)),
			(double)(cos(r.x) * cos(r.z) + sin(r.x) * sin(r.y) * sin(r.z)),
			(double)(cos(r.y) * sin(r.z)),
			(double)0.0},
			{(double)(cos(r.x) * cos(r.z) * sin(r.y) + sin(r.x) * sin(r.z)),
			(double)(cos(r.z) * sin(r.x) * sin(r.y) - cos(r.x) * sin(r.z)),
			(double)(cos(r.y) * cos(r.z)),
			(double)0.0},
			{(double)0.0, (double)0.0, (double)0.0, (double)1.0}
	}});
}
