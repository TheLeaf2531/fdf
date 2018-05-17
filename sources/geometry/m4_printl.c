/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_printl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:03:20 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/16 18:20:17 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

void		m4_printl(t_matrix4 m)
{
	printf("\n[%f,%f,%f,%f]\n", m.t[0][0], m.t[0][1], m.t[0][2], m.t[0][3]);
	printf("[%f,%f,%f,%f]\n", m.t[1][0], m.t[1][1], m.t[1][2], m.t[1][3]);
	printf("[%f,%f,%f,%f]\n", m.t[2][0], m.t[2][1], m.t[2][2], m.t[2][3]);
	printf("[%f,%f,%f,%f]\n", m.t[3][0], m.t[3][1], m.t[3][2], m.t[3][3]);
}
