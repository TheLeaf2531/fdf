/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:32:28 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/20 17:21:52 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <math.h>
# include "drawer.h"
# include "vector3.h"
# include "vector2.h"

typedef enum	e_type_cam
{
	parallel,
	conic,
	isometric
}				t_type_cam;

typedef struct	s_camera
{
	t_vector3	*pos;
	t_vector3	*rot;
	t_type_cam	type;
}				t_camera;

t_camera		*create_cam(t_vector3 pos, t_vector3 rot, int type_cam);

#endif
