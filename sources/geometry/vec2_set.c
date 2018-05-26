/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:36:25 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/24 16:53:54 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_vector2l	vec2l_set(long x, long y)
{
	return ((t_vector2l){(long)x, (long)y});
}

t_vector2i	vec2i_set(int x, int y)
{
	return ((t_vector2i){x, y});
}

t_vector2	vec2_set(double x, double y)
{
	return ((t_vector2){(double)x, (double)y});
}
