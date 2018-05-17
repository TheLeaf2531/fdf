/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:49:16 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/14 18:56:28 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"

void	draw_line(t_vector2 start, t_vector2 end, void *win_ptr, void *mlx_ptr)
{
	t_vector2	s;
	t_vector2	d;
	int			err;
	int			err_2;
	void		*img_ptr;

	img_ptr = mlx_new_image(mlx_ptr, 512, 512);
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