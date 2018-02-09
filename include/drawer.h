/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:09:24 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/09 18:18:35 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWER_H
# define DRAWER_H

# include "../libft/libft.h"
# include "vector2.h"
# include "mlx.h"

void	draw_line(t_vector2 start, t_vector2 end, void *win_ptr, void *mlx_ptr);

#endif
