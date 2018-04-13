/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:11:38 by vboissel          #+#    #+#             */
/*   Updated: 2018/04/13 21:22:10 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list		*read_file(char *file_name) 
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
	return (file);
}

int			check_file_validity(t_list	*file)
{
	size_t 	lenght;
	size_t	i;
	char	*line;
	i = 0;

	while (file != NULL)
	{
		line = file->content;
		while (line[i])
		{
			if (!ft_isspace(line[i]) && !ft_isdigit(line[i]))
				return (0);
			i++;
		}
		file = file->next;
	}
	return (1);
}

t_triangle	**parse_file(char *file_name)
{
	t_triangle	**triangles;
	t_list		*file;

	if ((file = read_file(file_name)) == NULL)
		return (NULL);
	if (check_file_validity(file) == 0)
		return (NULL);
	while (file != NULL)
	{
		printf("%s\n", file->content);
		file = file->next;
	}
	return (NULL);
}