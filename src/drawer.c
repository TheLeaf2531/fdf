/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:09:14 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/19 17:16:01 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/drawer.h"

void	draw_line(t_vector2 start, t_vector2 end, void *win_ptr, void *mlx_ptr)
{
	t_vector2	s;
	t_vector2	d;
	int			err;
	int			err_2;

	d.x = abs(end.x - start.x);
	d.y = abs(end.y - start.y);
	s.x = start.x < end.x ? 1 : -1;
	s.y = start.y < end.y ? 1 : -1;
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (start.x != end.x && start.y != end.y)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, start.x, start.y, 0xFFFFFF);
		err_2 = err;
		if (err_2 > -d.x)
		{
			err -= d.y;
			start.x += s.x;
		}
		if (err_2 < d.y)
		{
			err += d.x;
			start.y += s.y;
		}
	}
}
