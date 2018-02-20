/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 16:59:49 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/20 17:21:10 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector3.h"

t_vector3		*new_vector3(float x, float y, float z)
{
	t_vector3	*vector3;

	vector3 = (t_vector3*)malloc(sizeof(t_vector3));
	vector3->x = x;
	vector3->y = y;
	vector3->z = z;
	return (vector3);
}

void			set_vector3(t_vector3 *vector, float x, float y, float z)
{
	vector->x = x;
	vector->y = y;
	vector->z = z;
}

void			to_zero(t_vector3 *vector)
{
	vector->x = 0;
	vector->y = 0;
	vector->z = 0;
}

void			normalize(t_vector3 *vector)
{
	double	norme;

	norme = sqrt(pow(vector->x, 2) + pow(vector->y, 2) + pow(vector->z, 2));
	if (norme != 0)
	{
		vector->x /= norme;
		vector->y /= norme;
		vector->z /= norme;
	}
}
