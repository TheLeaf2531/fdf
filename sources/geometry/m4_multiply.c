/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_multiply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:06:32 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/16 18:21:17 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_matrix4		m4_multiply(t_matrix4 a, t_matrix4 b)
{
	t_matrix4	c;
	int			y;
	int			x;

	y = 0;
	x = 0;
	while (y < 4)
	{
		c.t[y][x] = a.t[y][0] * b.t[0][x] +
					a.t[y][1] * b.t[1][x] +
					a.t[y][2] * b.t[2][x] +
					a.t[y][3] * b.t[3][x];
		y = x == 3 ? y + 1 : y;
		x = x == 3 ? 0 : x + 1;
	}
	return (c);
}
