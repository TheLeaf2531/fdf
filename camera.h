/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:38:59 by vboissel          #+#    #+#             */
/*   Updated: 2018/04/28 17:54:32 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <math.h>
# include "libft/libft.h"
# include "matrix4x4.h"

# define FOCAL 35
# define INCH_TO_MM 25.4
# define NEAR_CLIPPING_PLANE 0.1
# define FAR_CLIPPING_PLANE 1000
# define FOV 90

typedef	struct	s_camera
{
	t_matrix4x4	transform;
	float		focal;
	float		z_near;
	float		z_far;
	float		fov;
}				t_camera;

t_camera	*create_camera(void);

#endif