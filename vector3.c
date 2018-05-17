/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:42:19 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/17 18:53:25 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "libft/libft.h"

t_vector3		*new_vector3(double x, double y, double z)
{
	t_vector3 *v;

	if ((v = malloc(sizeof(t_vector3))) == NULL)
		return (NULL);
	v->x = x;
	v->y = y;
	v->z = z;
	v->w = 1;
	return (v);
}

double			magnitude(t_vector3 v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

void			normalize(t_vector3 *v)
{
	float norm;
	float factor;

	norm = v->x * v->x + v->y * v->y + v->z * v->z;
	if (norm > 0)
	{
		factor = 1 / sqrt(norm);
		v->x *= factor;
		v->y *= factor;
		v->z *= factor;
	}
}

t_vector3		*multiply_v3_m4x4(t_vector3 v, t_matrix4x4 m)
{
	t_vector3 *nv;

	nv = malloc(sizeof(t_vector3));
	if (nv == NULL)
		return (NULL);
	nv->x = m.t[0][0] * v.x + m.t[0][1] * v.y +
			m.t[0][2] * v.z + m.t[0][3];
	nv->y = m.t[1][0] * v.x + m.t[1][1] * v.y +
			m.t[1][2] * v.z + m.t[1][3];
	nv->z = m.t[2][0] * v.x + m.t[2][1] * v.y +
			m.t[2][2] * v.z + m.t[2][3];
	nv->w = m.t[3][0] * v.x + m.t[3][1] * v.y +
			m.t[3][2] * v.z + m.t[3][3];
	return (nv);
}

t_vector3		*multiply_m4x4_v3(t_matrix4x4 m, t_vector3 v)
{
	t_vector3 *nv;

	nv = malloc(sizeof(t_vector3));
	if (nv == NULL)
		return (NULL);

	nv->x = v.x * m.t[0][0] + v.y * m.t[1][0] + v.z * m.t[2][0] + m.t[3][0];
	nv->y = v.x * m.t[0][1] + v.y * m.t[1][1] + v.z * m.t[2][1] + m.t[3][1];
	nv->z = v.x * m.t[0][2] + v.y * m.t[1][2] + v.z * m.t[2][2] + m.t[3][2];
	nv->w = v.x * m.t[0][3] + v.y * m.t[1][3] + v.z * m.t[2][3] + m.t[3][3];
	nv->x /= nv->w;
	nv->y /= nv->w;
	nv->z /= nv->w;
	return (nv);
}
