/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:14:22 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/20 21:18:05 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "geometry.h"
# include "fdf.h"

typedef	struct	s_fdf_file
{
	size_t	width;
	size_t	height;
	t_list	*lines;
}				t_fdf_file;

t_model			*parse_file(char *file_name);
t_fdf_file		*read_file(int fd);
int				check_file(t_fdf_file *file);
t_model			*convert_file(t_fdf_file *file);

#endif
