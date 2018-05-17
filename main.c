/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:09:56 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/17 19:27:13 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "vector2.h"
#include "terrain.h"
#include "matrix4x4.h"
#include "printer.h"
#include "parser.h"
#include "transform.h"
#include <math.h>
#include "mlx.h"


int		compute_stuff(t_matrix4x4 *m, t_vector3 p_world, t_vector2 **p_img)
{
	t_vector3	*p_camera;
	float			ps_x;
	float			ps_y;
	float			pNDC_x;
	float			pNDC_y;
	//printf("\n-----\n");
	//printf("p_world :");
	//print_vector3(p_world);
	p_camera = multiply_m4x4_v3(*m, p_world);
	//printf("p_camera :");
	//print_vector3(*p_camera);
	ps_x = p_camera->x / -p_camera->z;
	ps_y = p_camera->y / -p_camera->z;
	//printf("ps_x : %f | ps_y : %f\n", ps_x, ps_y);
	pNDC_x = (ps_x + 2 * 0.5) / 2;
	pNDC_y = (ps_y + 2 * 0.5) / 2;
	//printf("pNDC_x : %f | pNDC_y : %f\n", pNDC_x, pNDC_y );
	*p_img = new_vector2((int)(pNDC_x * 512), (int)((1 - pNDC_y) * 512));
	//print_vector2(**p_img);
	//printf("-----\n");
	return (1);
}

int     main(int argc, char **argv)
{
	(void)argv;
	(void)argc;

	t_matrix4x4 *matrix;
	t_vector3	*vec;
	matrix = ft_memalloc(sizeof(t_matrix4x4));
	vec = new_vector3(-0.5,0.5,-0.5);
	*matrix = (t_matrix4x4){{
		{(double)0.718762, (double)0.615033, (double)-0.324214, (double)0.0},
		{(double)-0.393732, (double)0.744416, (double)0.539277, (double)0.0},
		{(double)0.573024, (double)-0.259959, (double)0.777216, (double)0.0},
		{(double)0.526967, (double)1.254234, (double)-2.532150, (double)1.0}}
	};
	matrix = invert_m4x4(matrix);
	print_matrix4x4(*matrix);
	vec = multiply_m4x4_v3(*matrix, *vec);
	print_vector3(*vec);
	/*
	t_vector3 *vector;
	t_matrix4x4 *matrix_0;
	t_terrain	*terrain;
	size_t		i;
	void			*mlx_ptr;
	void			*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 512, 512, "fdf");
    (void)argc;
	vector = new_vector3(-0.5, 0.5 ,-0.5);
	i = 0;
	matrix_0 = identity_m4x4();
	matrix_0 = rotate_x(&matrix_0, 90);
	matrix_0->t[3][2] = -10;
	
	terrain = parse_file(argv[1]);
	if(terrain == NULL)
		return (-1);
	matrix_0 = invert_m4x4(matrix_0);
	printf("<svg version=\"1.1\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" xmlns=\"http://www.w3.org/2000/svg\" height=\"1920\" width=\"1080\">\n");
	while (i < terrain->size)
	{
		t_vector2 *p0;
		t_vector2 *p1;
		t_vector2 *p2;
	
		compute_stuff(matrix_0, *(terrain->triangles[i]->p0), &p0);
		compute_stuff(matrix_0, *(terrain->triangles[i]->p1), &p1);
		compute_stuff(matrix_0, *(terrain->triangles[i]->p2), &p2);

		printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" style=\"stroke:rgb(0,0,0);stroke-width:1\" />\n", p0->x, p0->y, p1->x, p1->y);
		printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" style=\"stroke:rgb(0,0,0);stroke-width:1\" />\n", p1->x, p1->y, p2->x, p2->y);
		printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" style=\"stroke:rgb(0,0,0);stroke-width:1\" />\n", p2->x, p2->y, p0->x, p0->y);
		i++;
	}
	printf("</svg>\n");
	
	
	printf ("Terrain width : %d\n", terrain->width);
	printf ("Terrain height : %d\n", terrain->height);
	while (i < terrain->size)
	{
		printf("------- TRIANGLE %zu -------\n", i);
		printf("p0 : (%f, %f, %f)\n",
			terrain->triangles[i]->p0->x,
			terrain->triangles[i]->p0->y,
			terrain->triangles[i]->p0->z);
		printf("p1 : (%f, %f, %f)\n",
			terrain->triangles[i]->p1->x,
			terrain->triangles[i]->p1->y,
			terrain->triangles[i]->p1->z);
		printf("p2 : (%f, %f, %f)\n",
			terrain->triangles[i]->p2->x,
			terrain->triangles[i]->p2->y,
			terrain->triangles[i]->p2->z);
		i++;
	}
	mlx_loop(mlx_ptr);*/
    return (0);
}