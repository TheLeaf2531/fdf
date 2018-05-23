/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terrain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:15:07 by vboissel          #+#    #+#             */
/*   Updated: 2018/04/18 19:48:10 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terrain.h"

t_terrain *create_terrain(int wdth, int hght)
{
	t_terrain	*terrain;
	size_t		i;

	terrain = ft_memalloc(sizeof(t_terrain));
	terrain->width = wdth;
	terrain->height = hght;
	terrain->size = (hght - 1) * (2 * wdth - 2);
	i = 0;
	terrain->triangles = ft_memalloc(sizeof(t_triangle) * terrain->size);
	while (i < terrain->size)
	{
		terrain->triangles[i] = ft_memalloc(sizeof(t_triangle));
		i++;
	}
	return (terrain);
}