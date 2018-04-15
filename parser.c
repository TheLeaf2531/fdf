/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:11:38 by vboissel          #+#    #+#             */
/*   Updated: 2018/04/16 01:53:32 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

t_vector3		*parse_file(char *file_name)
{
	t_vector3	*triangles;
	t_list		*file;
	t_list		*tmp;
	char		***tab;
	size_t		i;

	if ((file = read_file(file_name)) == NULL)
		return (NULL);
	if (check_file_validity(file) == 0)
		return (NULL);
	tmp = file;
	tab = malloc(sizeof(*tab) * (ft_lstlen(&tmp) + 1) + 1);
	i = 0;
	while (tmp != 0)
	{
		tab[i] = ft_strsplit(tmp->content, ' ');
		tmp = tmp->next;
		i++;
	}
	triangles = NULL;
	return (triangles);
}