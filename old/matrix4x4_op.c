/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4x4_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:07:15 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/22 15:43:03 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

float	convert_to_rad(float degrees)
{
	return (degrees * 3.1415926 / 180);
}

float	convert_to_deg(float radians)
{
	return (radians * (180 / 3.1415926));
}


t_matrix4x4	*rotate_x(t_matrix4x4 **m, float angle)
{
	t_matrix4x4 *rot;

	rot = identity_m4x4();
	angle = convert_to_rad(angle);
	rot->t[1][1] = cos(angle);
	rot->t[1][2] = -sin(angle);
	rot->t[2][1] = sin(angle);
	rot->t[2][2] = cos(angle);
	multiply_m4x4(m, rot);
	ft_memdel((void **)&rot);
	return (*m);
}

t_matrix4x4	*rotate_y(t_matrix4x4 **m, float angle)
{
	t_matrix4x4 *rot;

	rot = identity_m4x4();
	angle = convert_to_rad(angle);
	rot->t[0][0] = cos(angle);
	rot->t[0][1] = -sin(angle);
	rot->t[1][0] = sin(angle);
	rot->t[1][1] = cos(angle);
	multiply_m4x4(m, rot);
	ft_memdel((void **)&rot);
	return (*m);
}

t_matrix4x4	*rotate_z(t_matrix4x4 **m, float angle)
{
	t_matrix4x4 *rot;

	rot = identity_m4x4();
	angle = convert_to_rad(angle);
	rot->t[0][0] = cos(angle);
	rot->t[0][2] = sin(angle);
	rot->t[2][0] = -sin(angle);
	rot->t[2][2] = cos(angle);
	multiply_m4x4(m, rot);
	ft_memdel((void **)&rot);
	return (*m);
}

/*
t_matrix4x4	*scale(t_matrix4x4 *m, t_vector3 scl)
{
	t_matrix4x4 *rot;

	rot = identity_m4x4();
	return (rot);
}

t_matrix4x4	*translate(t_matrix4x4 *m, t_vector3 coord)
{
	t_matrix4x4 *rot;

	rot = identity_m4x4();
	return (rot);
}*/