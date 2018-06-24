/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:28:28 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/24 15:58:31 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fdf_free_scene(t_scene **scene)
{
	ft_memdel((void**)&(*scene)->camera);
	ft_memdel((void**)&(*scene)->model->triangle);
	ft_memdel((void**)&(*scene)->model);
	mlx_destroy_window((*scene)->window->mlx_ptr, (*scene)->window->win_ptr);
	ft_memdel((void**)&(*scene)->window->mlx_ptr);
	ft_memdel((void**)&(*scene)->window);
	ft_memdel((void**)scene);
}

void			fdf_free_image(t_image **img)
{
	ft_memdel((void**)&(*img)->img_ptr);
	ft_memdel((void**)&(*img)->img);
	ft_memdel((void**)img);
}

t_scene			*fdf_create_scene(size_t width, size_t height, char *scene_name)
{
	t_scene		*s;

	if ((s = ft_memalloc(sizeof(t_scene))) == NULL)
		return (NULL);
	if ((s->model = parse_file(scene_name)) == NULL)
		return (NULL);
	if ((s->window = fdf_init(width, height, scene_name)) == NULL)
		return (NULL);
	if ((s->camera = fdf_create_camera()) == NULL)
		return (NULL);
	return (s);
}

t_image			*fdf_create_image(t_window *window)
{
	t_image	*image;

	if ((image = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if (!(image->img_ptr = mlx_new_image(window->mlx_ptr, WIDTH, HEIGHT)))
		return (NULL);
	if (!(image->img = (unsigned int *)mlx_get_data_addr(
			image->img_ptr,
			&image->bpp,
			&image->size_line,
			&image->endian)))
		return (NULL);
	fdf_fill_image(image, to_color(255, 255, 255, 0));
	return (image);
}

t_window		*fdf_init(size_t width, size_t height, char *window_name)
{
	t_window	*window;

	if ((window = ft_memalloc(sizeof(t_window))) == NULL)
		return (NULL);
	if ((window->mlx_ptr = mlx_init()) == NULL)
		return (NULL);
	if ((window->win_ptr = mlx_new_window(window->mlx_ptr,
										width, height, window_name)) == NULL)
		return (NULL);
	window->width = width;
	window->height = height;
	return (window);
}
