/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:46:53 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/09 16:07:39 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/file_parser.h"

static	int		get_height(const char *str_filename)
{
	int		fd;
	char	*line;
	size_t	height;

	height = 0;
	fd = open(str_filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		height += 1;
		free(line);
	}
	close(fd);
	return (height);
}

static	int		get_width(const char *str_filename)
{
	int		fd;
	char	*line;
	size_t	width;

	width = 0;
	fd = open(str_filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (width == 0)
			width = ft_strsplitcnt(line, ' ');
		free(line);
	}
	close(fd);
	return (width);
}

t_grid			*file_parser(const char *str)
{
	char	*line;
	t_grid	*grid;
	size_t	i_row;
	int		fd;

	grid = create_grid(get_width(str), get_height(str), str);
	i_row = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		add_row(&grid, i_row, line);
		i_row += 1;
		free(line);
	}
	return (grid);
}
