/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:29:05 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/05 16:26:05 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_image			*fdf_create_image(t_window *window)
{
	t_image	*image;

	if ((image = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if (!(image->img_ptr = mlx_new_image(window->mlx_ptr, WIDTH, HEIGHT)))
		return (NULL);
	if ((image->img = (unsigned int *)mlx_get_data_addr(
			image->img_ptr,
			&image->bpp, 
			&image->size_line, 
			&image->endian
	)) == NULL)
		return (NULL);
	return (image);
}
