/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 19:28:39 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/23 18:04:27 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "geometry.h"
# include "mlx.h"
# include "libft.h"

typedef struct	s_camera
{
	int			width;
	int			height;
	t_vector2	ratio;
	t_vector3	position;
	t_vector3	rotation;
}				t_camera;

typedef	struct	s_image
{
	void			*img_ptr;
	unsigned int	*img;
	int				width;
	int				height;
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

typedef	struct	s_triangle
{
	t_vector3	p0;
	t_vector3	p1;
	t_vector3	p2;
}				t_triangle;

typedef	struct	s_model
{
	size_t		width;
	size_t		height;
	size_t		tris;
	t_triangle	*triangle;
}				t_model;

t_window		*fdf_init(size_t width, size_t height, char *window_name);

unsigned int	to_color(unsigned int r, unsigned int g,
							unsigned int b, unsigned int a);
t_image			*fdf_new_image(t_window *window, int width, int height);
void			fdf_fill_image(t_image *image, unsigned int color);
void			fdf_put_pixel(t_image *image, unsigned int color, int x, int y);
void			fdf_draw_line(t_image *img, t_vector2i s,
								t_vector2i e, unsigned int color);

void			cam_set_position(t_camera **cam, t_vector3 pos);
void			cam_set_rotation(t_camera **cam, t_vector3 rot);
#endif
