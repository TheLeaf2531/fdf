/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 20:48:52 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/23 17:44:12 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_model		*parse_file(char *file_name)
{
	t_fdf_file	*file;
	t_model		*model;
	t_list		*tmp;
	size_t		size;

	if ((file = read_file(open(file_name, O_RDONLY))) == NULL)
		return (NULL);
	if ((file->width = check_file(file)) == -1)
		return (NULL);
	size = (file->height - 1) * (2 * file->width - 2);
	model = convert_file(file);
	model->tris = size;
	while (file->lines)
	{
		ft_strdel((char**)&(file->lines->content));
		tmp = file->lines;
		file->lines = file->lines->next;
		ft_memdel((void**)&tmp);
	}
	ft_memdel((void**)&(file->lines));
	ft_memdel((void**)&(file));
	return (model);
}
