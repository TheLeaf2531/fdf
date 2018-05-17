/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:00:38 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/12 18:46:51 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"

void	print_vector3(t_vector3 v)
{
	//printf("\n[%f]\n[%f]\n[%f]\n[%f]\n", v.x, v.y, v.z, v.w);
	printf("\n[%f] [%f] [%f] [%f]\n", v.x, v.y, v.z, v.w);
}

void	print_matrix4x4(t_matrix4x4 m)
{
	printf("\n[%f,%f,%f,%f]\n", m.t[0][0], m.t[0][1], m.t[0][2], m.t[0][3]);
	printf("[%f,%f,%f,%f]\n", m.t[1][0], m.t[1][1], m.t[1][2], m.t[1][3]);
	printf("[%f,%f,%f,%f]\n", m.t[2][0], m.t[2][1], m.t[2][2], m.t[2][3]);
	printf("[%f,%f,%f,%f]\n", m.t[3][0], m.t[3][1], m.t[3][2], m.t[3][3]);
}

void	print_vector2(t_vector2 v)
{
	printf("[%d] [%d]\n", v.x, v.y);
}