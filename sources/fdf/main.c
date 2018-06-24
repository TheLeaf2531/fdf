/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:26:38 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/23 20:19:52 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_scene *scene;

	if (argc != 2)
		return (0);
	if ((scene = fdf_create_scene(WIDTH, HEIGHT, argv[1])) == NULL)
		return (-1);
	fdf_set_loop(scene);
	return (0);
}
