/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:43:53 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/20 17:22:12 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/camera.h"

t_camera		*create_cam(t_vector3 pos, t_vector3 rot, int type_cam)
{
	t_camera	*camera;

	camera = malloc(sizeof(camera));
	camera->pos = new_vector3(pos.x, pos.y, pos.z);
	camera->rot = new_vector3(rot.x, rot.y, rot.z);
	camera->type = type_cam;
	return (camera);
}
