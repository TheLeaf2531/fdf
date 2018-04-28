/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:38:57 by vboissel          #+#    #+#             */
/*   Updated: 2018/04/28 17:54:41 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera	*create_camera(void)
{
	t_camera	*camera;

	camera = ft_memalloc(sizeof(t_camera));
	camera->focal = FOCAL;
	camera->z_near = NEAR_CLIPPING_PLANE;
	camera->z_far = FAR_CLIPPING_PLANE;
	camera->fov = FOV;
	return (camera);
}