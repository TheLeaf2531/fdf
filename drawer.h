/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:50:05 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/14 18:51:10 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWER_H
# define DRAWER_H

# include "mlx.h"
# include "vector2.h"

void	draw_line(t_vector2 start, t_vector2 end, void *win_ptr, void *mlx_ptr);

#endif