/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testicouille.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:26:38 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/12 18:57:55 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "geometry.h"
#include "parser.h"
//#include "fdf.h"


int	expose_hook(void *param)
{
	t_scene		*scene;

	scene = param;
	fdf_draw_scene(scene);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	parse_file(argv[1]);
	printf("Parsing done\n");
	/*
	t_scene *scene;

	if ((scene = fdf_create_scene(WIDTH, HEIGHT, argv[1])) == NULL)
		return (-1);
	//printf("%zu\n", sizeof(t_scene));
	fdf_draw_scene(scene);
	mlx_key_hook(scene->window->win_ptr, &fdf_keyhook, scene);
	mlx_expose_hook(scene->window->win_ptr, &expose_hook, scene);
	mlx_loop(scene->window->mlx_ptr);
	*/
	while (1)
		;
	return (0);
}