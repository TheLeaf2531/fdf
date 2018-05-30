/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:23:15 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/27 17:26:44 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void        fdf_free_image(t_image **img)
{
    ft_memdel((void**)&(*img)->img_ptr);
    ft_memdel((void**)&(*img)->img);
    ft_memdel((void**)img);
}