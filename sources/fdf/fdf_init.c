/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:28:28 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/21 16:36:28 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_window	*fdf_init(size_t width, size_t height, char *window_name)
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