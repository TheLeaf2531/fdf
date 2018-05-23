/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:24:24 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/21 18:26:32 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void			fdf_put_pixel(t_image *image, unsigned int color, int x, int y)
{
	if (y * image->height + x > image->height * image->width)
		return ;
	image->img[y * image->height + x] = color;
}