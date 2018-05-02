/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4x4.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 17:10:16 by vboissel          #+#    #+#             */
/*   Updated: 2018/04/30 18:48:29 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX4X4_H
# define MATRIX4X4_H
# include "libft/libft.h"
# include <stdio.h>
# include <math.h>

typedef struct	s_matrix4x4
{
	float t[4][4];
}				t_matrix4x4;

t_matrix4x4		*multiply_m4x4(t_matrix4x4 *a, t_matrix4x4 *b);
t_matrix4x4		*identity_m4x4();
t_matrix4x4		*invert_m4x4(t_matrix4x4 *m);
t_matrix4x4		*swap_row(t_matrix4x4 *m, int r1, int r2);

#endif
