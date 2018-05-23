/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testicouille.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:26:38 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/23 19:27:16 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"
#include "parser.h"
#include "fdf.h"

void	print_triangle(t_triangle t)
{
	v3_printl(t.p0);
	v3_printl(t.p1);
	v3_printl(t.p2);
}

int		is_neg(t_vector2i v)
{
	if (v.x < 0 || v.y < 0)
		return (1);
	return (0);
}

void	vec2_printl(t_vector2 v)
{
	printf("[%f,;%f]\n", v.x, v.y);
}

void	vec2i_printl(t_vector2i v)
{
	printf("[%d,;%d]\n", v.x, v.y);
}

t_vector2i	compute_coordinate(t_camera *camera, t_matrix4 cam_inv, t_vector3 p)
{
	t_vector3	p_camera;
	t_vector2	ps;
	t_vector2	p_NDC;

	//printf("Original :\n");
	//v3_printl(p);
	p_camera = m4_multiply_v3(cam_inv, p);
	//printf("Camera   :\n");
	//v3_printl(p_camera);
	ps.x = p_camera.x / -p_camera.z;
	ps.y = p_camera.y / -p_camera.z;
	//vec2_printl(ps);
	p_NDC.x = (ps.x + camera->ratio.x * 0.5) / camera->ratio.x;
	p_NDC.y = (ps.y + camera->ratio.y * 0.5) / camera->ratio.y;
	return ((t_vector2i){
		(int)(p_NDC.x * camera->width),
		(int)((1 - p_NDC.y) * camera->height)
	});
}

void	display_model(t_model *model, t_camera *camera, t_image *img)
{
	size_t		i;
	t_vector2i	p0;
	t_vector2i	p1;
	t_vector2i	p2;
	t_matrix4	cam_inv;
	unsigned	int	color;

	color = to_color(0, 0, 0, 0);
	i = 0;
	cam_inv = m4_multiply(m4_inverse(m4_euler(camera->rotation)), m4_invert_translation(camera->position));
	m4_printl(cam_inv);
	while (i < model->tris)
	{
		printf("\nTRIANGLE %zu\n", i);
		//print_triangle(model->triangle[i]);
		
		printf("---- P00 ----\n");
		p0 = compute_coordinate(camera, cam_inv, model->triangle[i].p0);
		vec2i_printl(p0);
		printf("---- p01 ----\n");
		p1 = compute_coordinate(camera, cam_inv, model->triangle[i].p1);
		vec2i_printl(p1);
		printf("---- p02 ----\n");
		p2 = compute_coordinate(camera, cam_inv, model->triangle[i].p2);
		vec2i_printl(p2);
		if (!is_neg(p0) || !is_neg(p1))
			fdf_draw_line(img, p0, p1, color);
		if (!is_neg(p1) || !is_neg(p2))
			fdf_draw_line(img, p1, p2, color);
		if (!is_neg(p2) || !is_neg(p0))
			fdf_draw_line(img, p2, p0, color);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_model			*model;
	t_window		*window;
	t_image			*img;
	t_camera		*camera;

	if (argc != 5)
		return (-1);
	printf("Start parsing\n");
	if ((model = parse_file(argv[1])) == NULL)
		return (-1);
	printf("Parsing OK\n");
	printf("tris : %zu, height : %zu, width : %zu\n", model->tris, model->height, model->width);
	printf("Init window\n");
	if ((window = fdf_init(1024, 1024, "fdf_test")) == NULL)
		return(-1);
	printf("Window OK\n");
	printf("color test : %u\n", to_color(255,215,0,0));
	img = fdf_new_image(window, 1024, 1024);
	printf("bpp : %d | size_line %d | endian %d\n", img->bpp, img->size_line, img->endian);
	fdf_fill_image(img, to_color(224, 224, 224, 0));
	if ((camera = ft_memalloc(sizeof(t_camera))) == NULL)
		return (-1);
	cam_set_position(&camera, vec3_set(0, 0, 0));
	cam_set_rotation(&camera, vec3_set(ft_atoi(argv[2]), ft_atoi(argv[3]), ft_atoi(argv[4])));
	camera->width = 1024;
	camera->height = 1024;
	camera->ratio = vec2_set(2, 2);
	display_model(model, camera, img);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, img->img_ptr, 0, 0);
	mlx_loop(window->mlx_ptr);
	return (0);
}