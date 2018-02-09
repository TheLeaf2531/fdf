/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:12:03 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/09 15:22:57 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_PARSER_H
# define FILE_PARSER_H

# include "../libft/libft.h"
# include "grid.h"
# include <stdio.h>

t_grid		*file_parser(const char	*str_filename);

#endif
