/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 18:08:15 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/25 17:46:20 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_scene			*fdf_create_scene(size_t width, size_t height, char *scene_name)
{
	t_scene *scene;

	if ((scene = ft_memalloc(sizeof(t_scene))) == NULL)
		return (NULL);
	if ((scene->window = fdf_init(width, height, scene_name)) == NULL)
		return (NULL);
	if ((scene->model = parse_file(scene_name)) == NULL)
		return (NULL);
	if ((scene->camera = fdf_create_camera()) == NULL)
		return (NULL);
	return (scene);
}