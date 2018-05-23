/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:10:31 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/15 17:09:44 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include <math.h>
# include "matrix4x4.h"

typedef struct	s_vector3
{
	double x;
	double y;
	double z;
	double w;
}				t_vector3;

t_vector3		*new_vector3(double x, double y, double z);
double			magnitude(t_vector3 vector);
void			normalize(t_vector3 *vector);
t_vector3		*multiply_v3_m4x4(t_vector3 v, t_matrix4x4 m);
t_vector3		*multiply_m4x4_v3(t_matrix4x4 m, t_vector3 v);

#endif
