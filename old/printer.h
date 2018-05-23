/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:01:58 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/12 18:42:49 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H
# include "matrix4x4.h"
# include "vector3.h"
# include "vector2.h"
# include "libft/libft.h"

void	print_vector3(t_vector3 vector);
void	print_matrix4x4(t_matrix4x4 matrix);
void	print_vector2(t_vector2 v);

#endif
