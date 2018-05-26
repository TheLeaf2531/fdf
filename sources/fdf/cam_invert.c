/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_invert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 17:53:22 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/26 17:34:42 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix4   cam_invert(t_camera *camera)
{
    t_matrix4   rot_inv;
    t_matrix4   pos_inv;

    rot_inv = m4_euler(camera->rotation);
    rot_inv = m4_inverse(rot_inv);
    pos_inv = (t_matrix4){{
        {(double)1.0, (double)0.0, (double)0.0, (double)0.0},
        {(double)0.0, (double)1.0, (double)0.0, (double)0.0},
        {(double)0.0, (double)0.0, (double)1.0, (double)0.0},
        {-camera->position.x, -camera->position.y, -camera->position.z,
        (double)1.0}}};
    return (m4_multiply(rot_inv, pos_inv));
}