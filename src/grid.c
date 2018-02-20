/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:51:03 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/20 18:36:10 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/grid.h"
#include <stdio.h>

t_grid	*create_grid(size_t width, size_t height, const char *str_filename)
{
	t_grid	*grid;
	size_t	i;

	i = 0;
	grid = (t_grid*)malloc(sizeof(t_grid));
	grid->width_grid = width;
	grid->height_grid = height;
	grid->grid_name = ft_strdup(str_filename);
	grid->tab_val = malloc(sizeof(t_vector3*) * height);
	grid->rot = new_vector3(0, 0, 0);
	while (i < height)
	{
		grid->tab_val[i] = malloc(sizeof(t_vector3) * width);
		i += 1;
	}
	return (grid);
}

void	add_row(t_grid **grid, int i_row, char *str_line)
{
	size_t	i;
	char	**tab;

	i = 0;
	tab = ft_strsplit(str_line, ' ');
	(void)i_row;
	while (i < (*grid)->width_grid)
	{
		set_vector3(&(*grid)->tab_val[i_row][i], i, i_row, ft_atoi(tab[i]));
		free(tab[i]);
		tab[i] = NULL;
		i += 1;
	}
	free(tab);
}

void	free_grid(t_grid **grid)
{
	size_t y;
	size_t x;

	y = 0;
	x = 0;
	free((*grid)->grid_name);
	while (y < (*grid)->height_grid)
	{
		free((*grid)->tab_val[y]);
		y++;
	}
	free((*grid)->tab_val);
	free(*grid);
	grid = NULL;
}
