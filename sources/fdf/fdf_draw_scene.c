/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:10:48 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/24 19:37:18 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				fdf_fill_image(t_image *image, unsigned int color)
{
	size_t	img_size;
	size_t	i;

	img_size = WIDTH * HEIGHT;
	i = 0;
	while (i < img_size)
	{
		image->img[i] = color;
		i++;
	}
}

void				fdf_put_pixel(t_image *image,
						unsigned int color, int x, int y)
{
	if (y * HEIGHT + x > HEIGHT * WIDTH)
		return ;
	image->img[y * HEIGHT + x] = color;
}

static t_vector3	compute_point(t_matrix4 cam_inv, t_vector3 p)
{
	t_vector3	p_camera;
	t_vector2	ps;
	t_vector3	p_cp;

	p_camera = m4_multiply_v3(cam_inv, p);
	p_camera.z = p_camera.z == 0 ? -0.01 : p_camera.z;
	ps.x = p_camera.x / (-p_camera.z);
	ps.y = p_camera.y / (-p_camera.z);
	p_cp.x = (ps.x + 2 * 0.5) / 2;
	p_cp.y = (ps.y + 2 * 0.5) / 2;
	p_cp.x = nearbyint(p_cp.x * WIDTH);
	p_cp.y = nearbyint((1 - p_cp.y) * HEIGHT);
	p_cp.z = p_camera.z;
	p_cp.w = ((p_cp.x <= 0 || p_cp.x >= WIDTH) ||
				(p_cp.y <= 0 || p_cp.y >= WIDTH) ||
				p_cp.z <= 0) ? 0 : 1;
	return (p_cp);
}

static void			draw_tri(t_matrix4 cam_inv, t_image *img, t_triangle t)
{
	t_triangle	triangle;

	triangle.p0 = compute_point(cam_inv, t.p0);
	triangle.p1 = compute_point(cam_inv, t.p1);
	triangle.p2 = compute_point(cam_inv, t.p2);
	if (triangle.p0.w || triangle.p1.w)
		fdf_draw_line(img, (t_vector2l){triangle.p0.x, triangle.p0.y},
							(t_vector2l){triangle.p1.x, triangle.p1.y},
							to_color(255, 255, 255, 0));
	if (triangle.p1.w || triangle.p2.w)
		fdf_draw_line(img, (t_vector2l){triangle.p1.x, triangle.p1.y},
							(t_vector2l){triangle.p2.x, triangle.p2.y},
							to_color(255, 255, 255, 0));
	if (triangle.p2.w || triangle.p0.w)
		fdf_draw_line(img, (t_vector2l){triangle.p2.x, triangle.p2.y},
							(t_vector2l){triangle.p0.x, triangle.p0.y},
							to_color(255, 255, 255, 0));
}

int					fdf_draw_scene(t_scene *sc)
{
	size_t		i;
	t_matrix4	cam_inv;

	if ((sc->image = fdf_create_image(sc->window)) == NULL)
		return (-1);
	i = 0;
	cam_inv = cam_invert(sc->camera);
	while (i < sc->model->tris)
	{
		draw_tri(cam_inv, sc->image, *sc->model->triangle[i]);
		i++;
	}
	mlx_put_image_to_window(sc->window->mlx_ptr,
		sc->window->win_ptr, sc->image->img_ptr, 0, 0);
	mlx_destroy_image(sc->window->mlx_ptr, sc->image);
	return (0);
}
