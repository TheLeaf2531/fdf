/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 19:28:39 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/07 16:01:06 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "geometry.h"
# include "fdf_types.h"
# include "parser.h"
# include "mlx.h"

# define HEIGHT 1280
# define WIDTH	1280
# define ASPECT_RATIO 2

t_window		*fdf_init(size_t width, size_t height, char *window_name);
t_scene			*fdf_create_scene(size_t width, size_t height, char *scene_name);
unsigned int	to_color(unsigned int rmlx, unsigned int g,
							unsigned int b, unsigned int a);
t_image			*fdf_create_image(t_window *window);
void			fdf_fill_image(t_image *image, unsigned int color);
void			fdf_put_pixel(t_image *image, unsigned int color, int x, int y);
void			fdf_draw_line(t_image *img, t_vector2l start,
							t_vector2l end, unsigned int color);
void			cam_set_position(t_camera **cam, t_vector3 pos);
void			cam_set_rotation(t_camera **cam, t_vector3 rot);
t_camera		*fdf_create_camera();
t_matrix4   	cam_invert(t_camera *camera);
int				fdf_draw_scene(t_scene *sc);
void        	fdf_free_image(t_image **img);
void       		fdf_free_scene(t_scene **scene);
int     		fdf_keyhook(int key, void *param);

#endif
