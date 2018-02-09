/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:09:14 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/09 19:22:34 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/drawer.h"
#include <stdio.h>

void	draw_line(t_vector2 start, t_vector2 end, void *win_ptr, void *mlx_ptr)
{
	int			erreur;
	t_vector2	d;

	(void)win_ptr;
	(void)mlx_ptr;
	erreur = end.x - start.x;
	d.x = 2 * erreur;
	d.y = (end.y - start.y) * 2;
	while (start.x <= end.x)
	{
		printf("%d, %d\n", start.x, start.y);
		mlx_pixel_put(mlx_ptr, win_ptr, start.x, start.y, 16777215);
		start.x = start.x + 1;
		erreur = erreur - d.y;
		if (erreur <= 0)
		{
			start.y = start.y + 1;
			erreur = erreur + d.x;
		}
	}
}
