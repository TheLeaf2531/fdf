/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyhook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:41:25 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/23 20:18:17 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				expose_hook(void *param)
{
	t_scene		*scene;

	scene = param;
	fdf_draw_scene(scene);
	return (1);
}

static void		mv_cam(int key, t_scene *scene)
{
	t_vector3		pos;
	const	double	spd = 0.5;
	double			depht;

	depht = scene->model->depht;
	pos = scene->camera->position;
	if (key == xp_sub)
		pos.x += spd;
	if (key == xp_add)
		pos.x -= spd;
	if (key == yp_add)
		pos.y += spd;
	if (key == yp_sub)
		pos.y -= spd;
	if (key == zp_add)
		pos.z += spd;
	if (key == zp_sub && pos.z - spd > depht)
		pos.z -= spd;
	cam_set_position(&scene->camera, pos);
	fdf_draw_scene(scene);
}

static void		rt_cam(int key, t_scene *scene)
{
	t_vector3		rot;
	const	double	spd = 10;

	rot = scene->camera->rotation;
	if (key == xr_add)
		rot.x += spd;
	if (key == xr_sub)
		rot.x = rot.x - spd < 0 ? 360 - -(rot.x - spd) : rot.x - spd;
	if (key == yr_add)
		rot.y += spd;
	if (key == yr_sub)
		rot.y = rot.y - spd < 0 ? 360 - -(rot.y - spd) : rot.y - spd;
	if (key == zr_add)
		rot.z += spd;
	if (key == zr_sub)
		rot.z = rot.z - spd < 0 ? 360 - -(rot.z - spd) : rot.z - spd;
	cam_set_rotation(&scene->camera, rot);
	fdf_draw_scene(scene);
}

int				fdf_keyhook(int key, void *param)
{
	t_scene *scene;

	scene = param;
	if (key == esc)
	{
		fdf_free_scene(&scene);
		exit(0);
	}
	if (key == xp_add || key == xp_sub || key == yp_add ||
		key == yp_sub || key == zp_add || key == zp_sub)
	{
		mv_cam(key, scene);
	}
	if (key == xr_add || key == xr_sub || key == yr_add ||
		key == yr_sub || key == zr_add || key == zr_sub)
	{
		rt_cam(key, scene);
	}
	return (0);
}
