/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_cam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 18:13:33 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/26 19:13:48 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_camera	*fdf_create_camera()
{
	t_camera	*camera;

	if ((camera = ft_memalloc(sizeof(t_camera))) == NULL)
		return (NULL);
	camera->position = vec3_set(-10, -10, -10);
	camera->rotation = vec3_set(0, 0, 0);
	camera->cam_ratio = WIDTH / HEIGHT;
	return (camera); 
}