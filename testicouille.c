/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testicouille.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:26:38 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/26 19:33:06 by vboissel         ###   ########.fr       */
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

int		kkey_hook(int keycode, void *param)
{
	t_scene		*scene;
	t_vector3	vec;

	//printf("%d\n", keycode);
	scene = param;
	vec = scene->camera->rotation;	
	if (keycode == 91)
	{
		vec.y += 1;
		cam_set_rotation(&scene->camera, vec);

	fdf_draw_scene(scene);
	}
	if (keycode == 84)
	{
		vec.y = vec.y == 0 ? vec.y : vec.y - 1;
		cam_set_rotation(&scene->camera, vec);	

	fdf_draw_scene(scene);
	}
	if (keycode == 89)
	{
		vec.x += 1;
		cam_set_rotation(&scene->camera, vec);
	fdf_draw_scene(scene);
	}
	if (keycode == 83)
	{
		vec.x = vec.x == 0 ? vec.x : vec.x - 1;
		cam_set_rotation(&scene->camera, vec);	
	fdf_draw_scene(scene);
	}
	if (keycode == 92)
	{
		vec.z += 1;
		cam_set_rotation(&scene->camera, vec);
	fdf_draw_scene(scene);
	}
	if (keycode == 85)
	{
		vec.z = vec.z == 0 ? vec.z : vec.z - 1;
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
	fdf_draw_scene(scene);
	mlx_key_hook(scene->window->win_ptr, &kkey_hook, scene);
	mlx_loop(scene->window->mlx_ptr);
	return (0);
	
}