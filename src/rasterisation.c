/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 17:40:17 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/20 19:11:28 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rasterisation.h"

void 	model_to_world(t_grid *grid)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	while (y < grid->height_grid)
	{
		y = x < grid->width_grid - 1 ? y : y + 1;
		x = x < grid->width_grid - 1 ? x + 1 : 0;
	}
}
