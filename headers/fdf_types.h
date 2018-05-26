/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:51:56 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/26 17:54:02 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TYPES
# define FDF_TYPES

#include "geometry.h"

typedef	struct	s_triangle
{
	t_vector3	p0;
	t_vector3	p1;
	t_vector3	p2;
}				t_triangle;
typedef struct	s_camera
{
	int			width;
	int			height;
	double		cam_ratio;
	t_vector2	ratio;
	t_vector3	position;
	t_vector3	rotation;
}				t_camera;

typedef	struct	s_image
{
	void			*img_ptr;
	unsigned int	*img;
	int				bpp;
	int				size_line;
	int				endian;
}				t_image;

typedef	struct	s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	size_t	width;
	size_t	height;
}				t_window;

typedef	struct	s_model
{
	size_t		width;
	size_t		height;
	size_t		tris;
	t_triangle	*triangle;
}				t_model;

typedef struct	s_scene
{
	t_window	*window;
	t_camera	*camera;
	t_model		*model;
	t_image		*image;
}				t_scene;

#endif
