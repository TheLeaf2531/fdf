/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terrain.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:01:47 by vboissel          #+#    #+#             */
/*   Updated: 2018/04/18 19:50:01 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERRAIN_H
# define TERRAIN_H

# include "triangle.h"

typedef struct	s_terrain
{
	int			width;
	int			height;
	t_triangle	**triangles;
	size_t		size;
}				t_terrain;

t_terrain *create_terrain(int width, int height);

#endif
