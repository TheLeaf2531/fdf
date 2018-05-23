/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:39:59 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/22 15:55:02 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

double		to_radians(double ang)
{
	return (ang * PI / 180.0);
}

double		to_degrees(double ang)
{
	return (ang * (180 / PI));
}

t_vector3	vec3_to_radians(t_vector3 rot)
{
	return ((t_vector3){
		(double)(rot.x * PI / 180.0),
		(double)(rot.y * PI / 180.0),
		(double)(rot.z * PI / 180.0),
		(double)0.0
	});
}

t_vector3	vec3_to_degrees(t_vector3 rot)
{
	return ((t_vector3){
		(double)(rot.x * (180 / PI)),
		(double)(rot.y * (180 / PI)),
		(double)(rot.z * (180 / PI)),
		(double)0.0
	});
}
