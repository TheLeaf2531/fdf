/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:51:55 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/16 18:20:05 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_vector3			vec3_normalize(t_vector3 vec)
{
	float factor;

	factor = 1.0 / sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	return ((t_vector3)
	{
		vec.x * factor,
		vec.y * factor,
		vec.z * factor,
		vec.w
	});
}
