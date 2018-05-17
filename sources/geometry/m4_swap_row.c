/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_swap_row.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:39:34 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/16 18:20:14 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_matrix4		m4_swap_row(t_matrix4 m, int r1, int r2)
{
	t_matrix4	temp;
	int			x;

	temp = m;
	x = 0;
	while (x < 4)
	{
		temp.t[r1][x] = m.t[r2][x];
		temp.t[r2][x] = m.t[r1][x];
		x++;
	}
	return (temp);
}
