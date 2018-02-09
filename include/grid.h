/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:45:14 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/09 16:08:26 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H

# include "../libft/libft.h"

typedef	struct	s_grid
{
	char	*grid_name;
	size_t	width_grid;
	size_t	height_grid;
	int		**tab_val;
}				t_grid;

t_grid			*create_grid(size_t width, size_t height,
				const char *str_filename);
void			add_row(t_grid **grid, int row_index, char *str_line);
void			free_grid(t_grid **grid);

#endif
