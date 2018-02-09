/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:20:06 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/08 18:20:33 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/file_checker.h"

static int		check_chars_validity(char *line)
{
	size_t	char_cnt;
	int		ret;

	ret = 0;
	char_cnt = 0;
	char_cnt += ft_striterc(line, &ft_isspace);
	char_cnt += ft_striterc(line, &ft_isdigit);
	char_cnt += ft_striterc(line, &ft_issign);
	if (char_cnt != ft_strlen(line))
		ret = -1;
	return (ret);
}

static int		check_chars_position(char *line)
{
	char	**splitted_line;
	int		ret;
	size_t	i_val;
	size_t	i;

	i = 0;
	i_val = 0;
	ret = 0;
	splitted_line = ft_strsplit(line, ' ');
	while (splitted_line[i_val] && ret == 0)
	{
		if (ft_issign(splitted_line[i_val][i]))
			i++;
		while (ft_isdigit(splitted_line[i_val][i]))
			i++;
		if (ft_strlen(splitted_line[i_val]) != i)
			ret = -1;
		i_val++;
		i = 0;
	}
	i_val = 0;
	while (splitted_line[i_val])
		free(splitted_line[i_val++]);
	free(splitted_line);
	return (ret);
}

int				check_validity(const char *str_filename)
{
	int			fd;
	char		*line;
	int			ret;

	ret = 0;
	fd = open(str_filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (check_chars_validity(line) == -1)
			ret = -1;
		if (check_chars_position(line) == -1)
			ret = -1;
		free(line);
	}
	close(fd);
	return (ret);
}
