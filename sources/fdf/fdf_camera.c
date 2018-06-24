/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:21:13 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/22 16:48:10 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_camera	*fdf_create_camera(void)
{
	t_camera	*camera;

	if ((camera = ft_memalloc(sizeof(t_camera))) == NULL)
		return (NULL);
	camera->position = vec3_set(0, 0, -20);
	camera->rotation = vec3_set(0, 0, 0);
	camera->cam_ratio = WIDTH / HEIGHT;
	return (camera);
}

t_matrix4	cam_invert(t_camera *camera)
{
	t_matrix4	rot_inv;
	t_matrix4	pos_inv;

	rot_inv = m4_euler(camera->rotation);
	rot_inv = m4_inverse(rot_inv);
	pos_inv = (t_matrix4){{
		{(double)1.0, (double)0.0, (double)0.0, (double)0.0},
		{(double)0.0, (double)1.0, (double)0.0, (double)0.0},
		{(double)0.0, (double)0.0, (double)1.0, (double)0.0},
		{-camera->position.x, -camera->position.y, -camera->position.z,
		(double)1.0}}};
	return (m4_multiply(pos_inv, rot_inv));
}

void		cam_set_position(t_camera **cam, t_vector3 pos)
{
	(*cam)->position.x = pos.x;
	(*cam)->position.y = pos.y;
	(*cam)->position.z = pos.z;
}

void		cam_set_rotation(t_camera **cam, t_vector3 rot)
{
	(*cam)->rotation.x = rot.x;
	(*cam)->rotation.y = rot.y;
	(*cam)->rotation.z = rot.z;
}
