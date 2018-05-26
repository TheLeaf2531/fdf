/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:30:56 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/24 16:57:35 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_draw_line(t_image *img, t_vector2l start,
						t_vector2l end, unsigned int color)
{
	t_vector2l	s;
	t_vector2l	d;
	int			err;
	int			err_2;

	d.x = abs(end.x - start.x);
	d.y = abs(end.y - start.y);
	s.x = start.x < end.x ? 1 : -1;
	s.y = start.y < end.y ? 1 : -1;
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (start.x != end.x && start.y != end.y)
	{
		if (start.x >= 0 && start.y >= 0)
			fdf_put_pixel(img, color, start.x, start.y);
		err_2 = err;
		err = (err_2 > -d.x) ? err - d.y : err;
		start.x = (err_2 > -d.x) ? start.x + s.x : start.x;
		err = (err_2 < d.y) ? err + d.x : err;
		start.y = (err_2 < d.y) ? start.y + s.y : start.y;
	}
}
