/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:45:14 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/20 18:19:16 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H

# include "../libft/libft.h"
# include "../include/vector3.h"

typedef	struct	s_grid
{
	char		*grid_name;
	size_t		width_grid;
	size_t		height_grid;
	t_vector3	**tab_val;
	t_vector3	*rot;
}				t_grid;

t_grid			*create_grid(size_t width, size_t height,
				const char *str_filename);
void			add_row(t_grid **grid, int i_row, char *str_line);
void			free_grid(t_grid **grid);

#endif
