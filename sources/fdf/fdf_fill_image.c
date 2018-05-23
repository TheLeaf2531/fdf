/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fill_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:19:34 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/21 18:24:11 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_fill_image(t_image *image, unsigned int color)
{
	size_t	img_size;
	size_t	i;

	img_size = image->width * image->height;
	i = 0;
	while (i < img_size)
	{
		image->img[i] = color;
		i++;
	}
}