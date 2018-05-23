/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_set_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:32:58 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/22 15:37:00 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cam_set_position(t_camera **cam, t_vector3 pos)
{
	(*cam)->position.x = pos.x;
	(*cam)->position.y = pos.y;
	(*cam)->position.z = pos.z;
}