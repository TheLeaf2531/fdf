/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:08:33 by vboissel          #+#    #+#             */
/*   Updated: 2018/04/13 20:52:11 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft/libft.h"
# include "vector3.h"
# include "triangle.h"

t_triangle	**parse_file(char *file_name);

#endif
