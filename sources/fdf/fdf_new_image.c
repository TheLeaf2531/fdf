/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_new_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:10:21 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/21 18:19:16 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_image			*fdf_new_image(t_window *window, int width, int height)
{
	t_image	*image;

	if ((image = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if (!(image->img_ptr = mlx_new_image(window->mlx_ptr, width, height)))
		return (NULL);
	if ((image->img = (unsigned int *)mlx_get_data_addr(
			image->img_ptr,
			&image->bpp, 
			&image->size_line, 
			&image->endian
	)) == NULL)
		return (NULL);
	image->width = width;
	image->height = height;
	return (image);
}
