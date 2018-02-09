/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:31:22 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/07 16:16:24 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_file(t_file **file)
{
	if (*file)
	{
		free((*file)->c_line);
		free((*file)->n_lines);
		free(*file);
		*file = NULL;
	}
	file = NULL;
}

int		prelim_checks(const int fd, t_file **file, char **line)
{
	if (fd < 0)
		return (-1);
	if (&(*line) == 0)
		return (-1);
	if (*file && fd != (*file)->fd)
		free_file(&(*file));
	if (!(*file))
	{
		if (((*file) = malloc(sizeof(t_file))) == NULL)
			return (-1);
		(*file)->c_line = ft_strnew(0);
		(*file)->n_lines = ft_strnew(0);
		(*file)->fd = fd;
	}
	return (0);
}

int		fill_file(t_file **file, char *buf)
{
	char	*tmp_str;

	if ((tmp_str = ft_strjoin((*file)->n_lines, buf)) == NULL)
		return (-1);
	if (ft_strlenc(tmp_str, '\n') == ft_strlen(tmp_str) && ft_strlen(buf) != 0)
	{
		free((*file)->n_lines);
		if (((*file)->n_lines = ft_strdup(tmp_str)) == NULL)
			return (-1);
		free(tmp_str);
		return (1);
	}
	free((*file)->c_line);
	free((*file)->n_lines);
	(*file)->c_line = ft_strsub(tmp_str, 0, ft_strlenc(tmp_str, '\n'));
	(*file)->n_lines = ft_strsub(tmp_str, ft_strlenc(tmp_str, '\n') + 1,
	ft_strlen(tmp_str));
	free(tmp_str);
	if (!(*file)->c_line || !(*file)->n_lines)
		return (-1);
	return (0);
}

int		read_file(t_file **file)
{
	char	buf[BUFF_SIZE + 1];
	long	ret;

	ft_bzero(buf, BUFF_SIZE + 1);
	ret = read((*file)->fd, buf, BUFF_SIZE);
	if (ret < 0)
		return (-1);
	if (ret > 0)
	{
		while (fill_file(&(*file), buf) != 0)
		{
			ft_bzero(buf, BUFF_SIZE + 1);
			ret = read((*file)->fd, buf, BUFF_SIZE);
		}
		return (1);
	}
	if (ft_strlen((*file)->n_lines) > 0)
	{
		fill_file(&(*file), buf);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_file	*file;
	int				res;

	if (prelim_checks(fd, &file, line))
	{
		free_file(&file);
		return (-1);
	}
	res = read_file(&file);
	if (res == -1)
	{
		free_file(&file);
		*line = ft_strnew(0);
		return (-1);
	}
	if (res == 1)
	{
		*line = ft_strdup(file->c_line);
		if (ft_strlen(file->n_lines) == 0)
			free_file(&file);
		return (1);
	}
	free_file(&file);
	return (0);
}
