/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:10:48 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/27 17:32:14 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	vec2l_print(t_vector2l v)
{
	printf("%d, %d\n", v.x, v.y);
}

void	print_triangle(t_triangle t)
{
	v3_printl(t.p0);
	v3_printl(t.p1);
	v3_printl(t.p2);
}

static t_vector2l	compute_coordinate(t_camera *camera, t_matrix4 cam_inv, t_vector3 p)
{
	t_vector3	p_camera;
	t_vector2	ps;
	t_vector2	p_NDC;

	p_camera = m4_multiply_v3(cam_inv, p);
	ps.x = p_camera.x / -p_camera.z;
	ps.y = p_camera.y / -p_camera.z;
	p_NDC.x = (ps.x + 2 * 0.5) / 2;
	p_NDC.y = (ps.y + 2 * 0.5) / 2;
	return ((t_vector2l){
		(long)(p_NDC.x * WIDTH),
		(long)((1 - p_NDC.y) * HEIGHT)
	});
}

static int			is_out_of_bound(t_vector2l p0, t_vector2l p1)
{
	int p0_out;
	int p1_out;

	p0_out = 0;
	p1_out = 0;
	if ((p0.x <= 0 || p0.y <= 0) || (p0.x > WIDTH || p0.y > HEIGHT))
		p0_out = 1;
	if ((p1.x <= 0 || p1.y <= 0) || (p1.x > WIDTH || p1.y > HEIGHT))
		p1_out = 1;
	return ((p0_out && p1_out));
}

int				fdf_draw_scene(t_scene *sc)
{
	t_matrix4	inv;
	size_t		i;
	t_vector2l	p0;
	t_vector2l	p1;
	t_vector2l	p2;
	
	inv = cam_invert(sc->camera);
	i = 0;
	if ((sc->image = fdf_create_image(sc->window)) == NULL)
		return (-1);
	fdf_fill_image(sc->image, to_color(255,255,255,0));
	while (i < sc->model->tris)
	{
		p0 = compute_coordinate(sc->camera, inv, sc->model->triangle[i].p0);
		p1 = compute_coordinate(sc->camera, inv, sc->model->triangle[i].p1);
		p2 = compute_coordinate(sc->camera, inv, sc->model->triangle[i].p2);
		if (!is_out_of_bound(p0, p1))
			fdf_draw_line(sc->image, p0, p1, to_color(0,0,0,0));
		if (!is_out_of_bound(p1, p2))
			fdf_draw_line(sc->image, p1, p2, to_color(0,0,0,0));
		if (!is_out_of_bound(p2, p0))
			fdf_draw_line(sc->image, p2, p0, to_color(0,0,0,0));
		i++;
	}
	mlx_put_image_to_window(sc->window->mlx_ptr, sc->window->win_ptr, sc->image->img_ptr, 0, 0);
	fdf_free_image(&sc->image);
	return (0);
}
