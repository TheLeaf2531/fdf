/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_set_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:35:03 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/22 15:36:54 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cam_set_rotation(t_camera **cam, t_vector3 rot)
{
	(*cam)->rotation.x = rot.x;
	(*cam)->rotation.y = rot.y;
	(*cam)->rotation.z = rot.z;
}