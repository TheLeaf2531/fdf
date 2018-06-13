/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:30:56 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/07 15:58:09 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void fdf_bresenham(t_image *img, t_vector2l strt,
			t_vector2l end, unsigned int color)
{
	t_vector2l	s;
	t_vector2l	d;
	int			err;
	int			err_2;

	d.x = abs(end.x - strt.x);
	d.y = abs(end.y - strt.y);
	s.x = strt.x < end.x ? 1 : -1;
	s.y = strt.y < end.y ? 1 : -1;
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (strt.x != end.x && strt.y != end.y)
	{
		if (strt.x > 0 && strt.y > 0 && strt.x < WIDTH && strt.y < HEIGHT)
			fdf_put_pixel(img, color, strt.x, strt.y);
		err_2 = err;
		err = (err_2 > -d.x) ? err - d.y : err;
		strt.x = (err_2 > -d.x) ? strt.x + s.x : strt.x;
		err = (err_2 < d.y) ? err + d.x : err;
		strt.y = (err_2 < d.y) ? strt.y + s.y : strt.y;
	}
}

static void fdf_vertical(t_image *img, t_vector2l strt,
	t_vector2l end, unsigned int color)
{
	t_vector2l swp;
	
	if (strt.y > end.y)
	{
		swp = strt;
		strt = end;
		end = swp;
	}
	while (strt.y <= end.y)
	{
		if (strt.y > 0 && strt.y < HEIGHT)
			fdf_put_pixel(img, color, strt.x, strt.y);
		strt.y += 1;
	}
}

static void fdf_horizontal(t_image *img, t_vector2l strt,
	t_vector2l end, unsigned int color)
{
	t_vector2l swp;

	if (strt.x > end.x)
	{
		swp = strt;
		strt = end;
		end = swp;
	}
	while (strt.x <= end.x)
	{
		if (strt.x > 0 && strt.x < HEIGHT)
			fdf_put_pixel(img, color, strt.x, strt.y);
		strt.x += 1;
	}

}


void	fdf_draw_line(t_image *img, t_vector2l strt,
						t_vector2l end, unsigned int color)
{
	if ((strt.x != end.x) && (strt.y != end.y))
		fdf_bresenham(img, strt, end, color);
	if (strt.x == end.x)
		fdf_vertical(img, strt, end, color);
	if (strt.y == end.y)
		fdf_horizontal(img, strt, end, color);
}
