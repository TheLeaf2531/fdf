/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:05:59 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/23 18:18:34 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_matrix4	m4_translation(t_vector3 pos)
{
	return ((t_matrix4){
		{
			{(double)1.0, (double)0.0, (double)0.0, (double)0.0},
			{(double)0.0, (double)1.0, (double)0.0, (double)0.0},
			{(double)0.0, (double)0.0, (double)1.0, (double)0.0},
			{(double)pos.x, (double)pos.y, (double)pos.z, (double)0.0}
		}
	});
}

t_matrix4	m4_invert_translation(t_vector3 pos)
{
		return ((t_matrix4){
		{
			{(double)1.0, (double)0.0, (double)0.0, (double)0.0},
			{(double)0.0, (double)1.0, (double)0.0, (double)0.0},
			{(double)0.0, (double)0.0, (double)1.0, (double)0.0},
			{(double)-pos.x, (double)-pos.y, (double)-pos.z, (double)1.0}
		}
	});
}