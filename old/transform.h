/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:27:16 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/14 18:32:25 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "matrix4x4.h"
# include "vector3.h"

float		convert_to_rad(float degrees);
float		convert_to_deg(float radians);
t_matrix4x4	*rotate_x(t_matrix4x4 **m, float angle);
t_matrix4x4	*rotate_y(t_matrix4x4 **m, float angle);
t_matrix4x4	*rotate_z(t_matrix4x4 **m, float angle);

#endif