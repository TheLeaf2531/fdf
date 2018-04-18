/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:11:38 by vboissel          #+#    #+#             */
/*   Updated: 2018/04/18 19:45:00 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "printer.h"

t_list			*read_file(char *file_name) 
{
	int		fd;
	int		ret;
	char	*line;
	t_list	*file;
	t_list	*tmp;

	fd = open(file_name, O_RDONLY);
	if (fd < -1)
		return (NULL);
	if ((ret = get_next_line(fd, &line)) <= 0)
		return (NULL);
	file = ft_lstnew(line, ft_strlen(line) + 1);
	tmp = file;
	ft_strdel(&line);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		tmp->next = ft_lstnew(line, ft_strlen(line) + 1);
		tmp = tmp->next;
		ft_strdel(&line);
	}
	if (ret == -1)
		return (NULL);
	return (file);
}

int				check_file_validity(t_list	*file)
{
	size_t	i;
	char	*line;
	size_t		nbr_v;

	i = 0;
	nbr_v = 0;
	while (file != NULL)
	{
		line = file->content;
		nbr_v = nbr_v == 0 ? ft_strsplitcnt(line, ' ') : nbr_v;
		if (nbr_v != ft_strsplitcnt(line, ' '))
			return (0);
		while (line[i])
		{
			if (!ft_isspace(line[i]) && !ft_isdigit(line[i]) &&
				!ft_issign(line[i]))
				return (0);
			i++;
		}
		i = 0;
		file = file->next;
	}
	return (1);
}

int				**to_tab_int(t_list *file, size_t height)
{
	int			**tab;
	size_t		y;

	y = 0;
	tab = ft_memalloc(sizeof(int*) * height);
	while (y < height)
	{
		tab[y]= ft_strsplitint(file->content, ' ');
		file = file->next;
		y++;
	}
	return (tab);
}

t_triangle		**gen_triangles(t_terrain *terrain, int **tab)
{
	int		x;
	int		y;
	size_t 	i;

	x = 0;
	y = 0;
	i = 0;
	while (y < terrain->height && x < terrain->width )
	{
		if (x + 1 != terrain->width && y + 1 != terrain->height)
		{
			terrain->triangles[i]->p0 = new_vector3(x, y, tab[y][x]);
			terrain->triangles[i]->p1 = new_vector3(x + 1, y, tab[y][x + 1]);
			terrain->triangles[i++]->p2 = new_vector3(x, y + 1, tab[y + 1][x]);
		}
		if (x != 0 && y + 1 != terrain->height)
		{
			terrain->triangles[i]->p0 = new_vector3(x, y, tab[y][x]);
			terrain->triangles[i]->p1 = new_vector3(x, y + 1, tab[y + 1][x]);
			terrain->triangles[i++]->p2 = new_vector3(x - 1, y + 1, tab[y + 1][x - 1]);
		}
		y = x == terrain->width - 1 ? y + 1 : y;
		x = x == terrain->width - 1 ? 0 : x + 1;
	}
	return (terrain->triangles);
}

t_terrain		*parse_file(char *file_name)
{
	t_terrain	*terrain;
	t_list		*file;
	int			**tab_int;

	terrain = NULL;
	if ((file = read_file(file_name)) == NULL)
		return (NULL);
	if (check_file_validity(file) == 0)
		return (NULL);
	terrain = create_terrain(ft_strsplitcnt(file->content, ' '),
								ft_lstlen(&file) + 1);
	tab_int = to_tab_int(file, terrain->height);
	terrain->triangles = gen_triangles(terrain, tab_int);
	return (terrain);
}