/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 18:25:43 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/23 20:19:21 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		set_cam_mov(t_scene *s)
{
	size_t		i;
	t_vector3	pos_cam;

	i = 0;
	s->model->depht = 0;
	while (i < s->model->tris)
	{
		s->model->depht = s->model->triangle[i]->p0.z >
			s->model->depht ? s->model->triangle[i]->p0.z : s->model->depht;
		s->model->depht = s->model->triangle[i]->p1.z >
			s->model->depht ? s->model->triangle[i]->p1.z : s->model->depht;
		s->model->depht = s->model->triangle[i]->p2.z >
			s->model->depht ? s->model->triangle[i]->p2.z : s->model->depht;
		i++;
	}
	s->model->depht += 3;
	pos_cam = vec3_set(s->model->width * 0.5,
						s->model->height * 0.5, s->model->depht + 2);
	cam_set_position(&s->camera, pos_cam);
	pos_cam = vec3_set(0, 180, 0);
	cam_set_rotation(&s->camera, pos_cam);
}

int				fdf_set_loop(t_scene *scene)
{
	set_cam_mov(scene);
	mlx_do_key_autorepeaton(scene->window->mlx_ptr);
	mlx_key_hook(scene->window->win_ptr, &fdf_keyhook, scene);
	mlx_expose_hook(scene->window->win_ptr, &expose_hook, scene);
	mlx_loop(scene->window->mlx_ptr);
	return (0);
}
