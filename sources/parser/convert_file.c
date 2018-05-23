/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 18:52:22 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/22 16:40:50 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void		gen_triangles(t_model **model, int **tab)
{
	size_t		x;
	size_t		y;
	size_t		i;

	x = 0;
	y = 0;
	i = 0;
	while (y < (*model)->height && x < (*model)->width)
	{
		if (x + 1 != (*model)->width && y + 1 != (*model)->height)
		{
			(*model)->triangle[i].p0 = vec3_set(x, y, tab[y][x]);
			(*model)->triangle[i].p1 = vec3_set(x + 1, y, tab[y][x + 1]);
			(*model)->triangle[i++].p2 = vec3_set(x, y + 1, tab[y + 1][x]);
		}
		if (x != 0 && y + 1 != (*model)->height)
		{
			(*model)->triangle[i].p0 = vec3_set(x, y, tab[y][x]);
			(*model)->triangle[i].p1 = vec3_set(x, y + 1, tab[y + 1][x]);
			(*model)->triangle[i++].p2 = vec3_set(x - 1, y + 1,
													tab[y + 1][x - 1]);
		}
		y = x == (*model)->width - 1 ? y + 1 : y;
		x = x == (*model)->width - 1 ? 0 : x + 1;
	}
}

static void		free_valtab(int ***tab, size_t height)
{
	while (height != 0)
	{
		free((*tab)[(int)height - 1]);
		height--;
	}
	free(*tab);
}

t_model			*convert_file(t_fdf_file *file)
{
	t_model	*model;
	int		**tab;
	t_list	*tmp;
	size_t	i;

	if ((tab = ft_memalloc(sizeof(int*) * file->height)) == NULL)
		return (NULL);
	tmp = file->lines;
	i = 0;
	while (tmp)
	{
		tab[i] = ft_strsplitint(tmp->content, ' ');
		i++;
		tmp = tmp->next;
	}
	if ((model = ft_memalloc(sizeof(t_model))) == NULL)
		return (NULL);
	i = (file->height - 1) * (2 * file->width - 2);
	if ((model->triangle = ft_memalloc(sizeof(t_triangle) * i)) == NULL)
		return (NULL);
	model->height = file->height;
	model->width = file->width;
	gen_triangles(&model, tab);
	free_valtab(&tab, model->height);
	return (model);
}
