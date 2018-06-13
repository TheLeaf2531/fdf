/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:23:24 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/09 17:00:33 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void       fdf_free_scene(t_scene **scene)
{
    ft_memdel((void**)&(*scene)->camera);
	ft_memdel((void**)&(*scene)->model->triangle);
	ft_memdel((void**)&(*scene)->model);
	mlx_destroy_window((*scene)->window->mlx_ptr, (*scene)->window->win_ptr);
    ft_memdel((void**)&(*scene)->window->mlx_ptr);
	ft_memdel((void**)&(*scene)->window);
	ft_memdel((void**)scene);
}
