/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testicouille.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:26:38 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/04 18:51:55 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "parser.h"
#include "fdf.h"

int		key_hook(int keycode, void *param)
{
	(void)param;
	printf("%d <- has been pressed \n", keycode);
	return (1);
}

int	expose_hook(void *param)
{
	t_scene		*scene;

	scene = param;
	fdf_draw_scene(scene);
	return (1);
}

int		kkey_hook(int keycode, void *param)
{
	t_scene		*scene;
	t_vector3	vec;
	t_vector3	pos;

	scene = param;
	vec = scene->camera->rotation;
	pos = scene->camera->position;
	if (keycode == 116)
	{
		pos.z += 2;
		cam_set_position(&scene->camera, pos);
		fdf_draw_scene(scene);
	}
	if (keycode == 121)
	{
		pos.z -= 2;
		cam_set_position(&scene->camera, pos);
		fdf_draw_scene(scene);
	}
	if (keycode == 123)
	{
		pos.x -= 2;
		cam_set_position(&scene->camera, pos);
		fdf_draw_scene(scene);
	}
	if (keycode == 124)
	{
		pos.x += 2;
		cam_set_position(&scene->camera, pos);
		fdf_draw_scene(scene);
	}
	if (keycode == 126)
	{
		pos.y += 2;
		cam_set_position(&scene->camera, pos);
		fdf_draw_scene(scene);
	}
	if (keycode == 125)
	{
		pos.y -= 2;
		cam_set_position(&scene->camera, pos);
		fdf_draw_scene(scene);
	}
	if (keycode == 91)
	{
		vec.y += 10;
		cam_set_rotation(&scene->camera, vec);

	fdf_draw_scene(scene);
	}
	if (keycode == 84)
	{
		vec.y = vec.y - 10 < 0 ? 360 - -(vec.y - 10) : vec.y - 10;
		cam_set_rotation(&scene->camera, vec);	

	fdf_draw_scene(scene);
	}
	if (keycode == 89)
	{
		vec.x += 10;
		cam_set_rotation(&scene->camera, vec);
	fdf_draw_scene(scene);
	}
	if (keycode == 83)
	{
		vec.x = vec.x - 10 < 0 ? 360 - -(vec.x - 10) : vec.x - 10;
		cam_set_rotation(&scene->camera, vec);	
	fdf_draw_scene(scene);
	}
	if (keycode == 92)
	{
		vec.z += 10;
		cam_set_rotation(&scene->camera, vec);
	fdf_draw_scene(scene);
	}
	if (keycode == 85)
	{
		vec.z = vec.z - 10 < 0 ? 360 - -(vec.z - 10) : vec.z - 10;
		cam_set_rotation(&scene->camera, vec);	
	fdf_draw_scene(scene);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_scene *scene;
	
	if (argc != 2)
		return (0);
	if ((scene = fdf_create_scene(WIDTH, HEIGHT, argv[1])) == NULL)
		return (-1);
	printf("kay\n");
	fdf_draw_scene(scene);
	mlx_key_hook(scene->window->win_ptr, &kkey_hook, scene);
	mlx_expose_hook(scene->window->win_ptr, &expose_hook, scene);
	mlx_loop(scene->window->mlx_ptr);
	return (0);
	
}