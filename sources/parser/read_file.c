/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:32:32 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/20 19:07:39 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_fdf_file	*read_file(int fd)
{
	t_fdf_file	*file;
	t_list		*tmp;
	char		*line;
	int			ret;

	if ((file = ft_memalloc(sizeof(t_fdf_file))) == NULL)
		return (NULL);
	file->height = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (file->lines == 0)
			file->lines = ft_lstnew(line, ft_strlen(line) + 1);
		else
		{
			tmp = ft_lstnew(line, ft_strlen(line) + 1);
			ft_lstaddend(&file->lines, tmp);
		}
		ft_strdel(&line);
		if (file->lines == 0)
			return (NULL);
		file->height += 1;
	}
	if (ret == -1)
		return (NULL);
	return (file);
}
