/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_as_m3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:32:21 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/22 16:37:13 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_matrix3		m4_as_m3(t_matrix4 m)
{
	return ((t_matrix3){{
		{m.t[0][0], m.t[0][1], m.t[0][2]},
		{m.t[1][0], m.t[1][1], m.t[1][2]},
		{m.t[2][0], m.t[2][1], m.t[2][2]}
	}});
}
