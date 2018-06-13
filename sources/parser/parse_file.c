/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:07:04 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/12 19:42:41 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static  int check_line(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]) && !ft_isspace(str[i]))
        {
            printf("Ca deconne pour la ligne : %s\n", str);
            printf("Et pour le charactere numero %zu\n", i);
            return (0);
        }
        i++;
    }
    return (1);
}

t_list      *lst_val(char *file_name)
{
    t_list  *lst;
    t_list  *tmp;
    int     *tab;
    int     fd;
    char    *line;

    if ((fd = open(file_name, O_RDONLY)) <= 0)
        return (NULL);
    lst = NULL;
    while (get_next_line(fd, &line))
    {
        if (!check_line(line))
            return (NULL);
        tmp = ft_memalloc(sizeof(t_list));
        tmp->content = ft_strsplitint(line, ' ', &tmp->content_size);
        tmp->next = NULL;    
        if (!lst)
            lst = tmp;
        else
            ft_lstaddend(&lst, tmp);
        ft_strdel(&line);
    }
    return (lst);
}

int  to_tris(t_list *lst, t_model **model)
{
	t_list	*tmp;
	size_t	i;
	double	x;
	double	y;

	i = 0;
	x = 0;
	y = 0;
	if(!((*model)->triangle = ft_memalloc(sizeof(t_triangle) * (width - 1) * (height - 1) * 2)))
		return (0);
	tmp = lst;
	while (tmp)
	{
		while (x < model->width)
		{
			(*model)->triangle[i]->p0 = vec3_set(x, y, (tmp->content + x));
			(*model)->triangle[i]->p1 = vec3_set(x, y, (tmp->content + x));
			(*model)->triangle[i]->p2 = vec3_set(x, y + 1, (tmp->content + x + 1));
			
			x++;
		}
		y++;
	}
	return (1);
}

t_model			*parse_file(char *file_name)
{
    t_model		*model;
    t_list		*lst;
    t_list		*tmp;
    size_t		size;

    if (!(lst = lst_val(file_name)))
        return (NULL);
	if (!(model = ft_memalloc(sizeof(t_model))))
		return (NULL);
    tmp = lst;
	model->width = tmp->content_size;
	model->height = 0;
    while (tmp)
    {
        if (model->width != tmp->content_size)
            return (NULL); 
		tmp = tmp->next;
		model->height++;
	}
	if (model->height < 2)
		return (NULL);
	printf("Width : %zu, Height : %zu\n", model->width, model->height);
    return (NULL);
}