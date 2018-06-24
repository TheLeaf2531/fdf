/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:07:04 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/24 15:57:50 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_list	*lst_val(char *file_name)
{
	t_list	*lst;
	t_list	*tmp;
	int		fd;
	char	*line;

	if ((fd = open(file_name, O_RDONLY)) <= 0)
		return (NULL);
	lst = NULL;
	while (get_next_line(fd, &line))
	{
		if (!check_line(line))
			return (NULL);
		tmp = ft_memalloc(sizeof(t_list));
		tmp->content = line;
		tmp->next = NULL;
		if (!lst)
			lst = tmp;
		else
			ft_lstaddend(&lst, tmp);
	}
	return (lst);
}

static int		**to_int(t_list *lst)
{
	t_list	*tmp;
	int		**val;
	size_t	i;
	size_t	lst_len;

	tmp = lst;
	lst_len = ft_lstlen(&tmp) + 1;
	if (!(val = ft_memalloc(sizeof(int*) * lst_len)))
		return (NULL);
	i = 0;
	while (tmp)
	{
		val[i] = ft_strsplitint(tmp->content, ' ');
		i++;
		tmp = tmp->next;
	}
	while (lst)
	{
		tmp = lst->next;
		free(lst->content);
		free(lst);
		lst = tmp;
	}
	return (val);
}

static void		free_valtab(int **tab, size_t height)
{
	size_t i;

	i = 0;
	while (i < height)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int		to_tris(int **val, t_model **m, size_t x, size_t y)
{
	size_t	i;

	i = 0;
	while (y < (*m)->height - 1)
	{
		if (x != (*m)->width - 1)
		{
			(*m)->triangle[i] = ft_memalloc(sizeof(t_triangle));
			(*m)->triangle[i]->p0 = vec3_set(x, y, val[y][x]);
			(*m)->triangle[i]->p1 = vec3_set(x, y + 1, val[y + 1][x]);
			(*m)->triangle[i++]->p2 = vec3_set(x + 1, y, val[y][x + 1]);
		}
		if (x != 0)
		{
			(*m)->triangle[i] = ft_memalloc(sizeof(t_triangle));
			(*m)->triangle[i]->p0 = vec3_set(x, y, val[y][x]);
			(*m)->triangle[i]->p1 = vec3_set(x - 1, y + 1, val[y + 1][x - 1]);
			(*m)->triangle[i++]->p2 = vec3_set(x, y + 1, val[y + 1][x]);
		}
		y = x == (*m)->width - 1 ? y + 1 : y;
		x = x == (*m)->width - 1 ? 0 : x + 1;
	}
	(*m)->tris = i;
	free_valtab(val, (*m)->height);
	return (1);
}

t_model			*parse_file(char *file_name)
{
	t_model		*model;
	t_list		*lst;
	t_list		*tmp;

	if (!(lst = lst_val(file_name)))
		return (NULL);
	if (!(model = ft_memalloc(sizeof(t_model))))
		return (NULL);
	tmp = lst;
	model->width = ft_strsplitcnt(lst->content, ' ');
	model->height = 0;
	while (tmp)
	{
		if (model->width != ft_strsplitcnt(tmp->content, ' '))
			return (NULL);
		tmp = tmp->next;
		model->height++;
	}
	if (model->height < 2 || !(model->triangle = ft_memalloc(
			sizeof(t_triangle) * (model->width - 1) * (model->height - 1) * 2))
			|| (!to_tris(to_int(lst), &model, 0, 0)))
		return (NULL);
	return (model);
}
