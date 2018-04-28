/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:09:56 by vboissel          #+#    #+#             */
/*   Updated: 2018/04/28 16:43:19 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "terrain.h"
#include "matrix4x4.h"
#include "printer.h"
#include "parser.h"

int     main(int argc, char **argv)
{
	t_vector3 *vector;
	t_matrix4x4 *matrix_0;
	t_terrain	*terrain;
	size_t		i;

    (void)argc;
    (void)argv;
	vector = new_vector3(0, 2 ,3);
	i = 0;
	//print_vector3(*vector);
	matrix_0 = malloc(sizeof(t_matrix4x4));
	matrix_0->t[0][0] = 1;
	matrix_0->t[0][1] = 0;
	matrix_0->t[0][2] = 0;
	matrix_0->t[0][3] = 3;
	matrix_0->t[1][0] = 0;
	matrix_0->t[1][1] = 1;
	matrix_0->t[1][2] = 0;
	matrix_0->t[1][3] = 3; 
	matrix_0->t[2][0] = 0;
	matrix_0->t[2][1] = 0;
	matrix_0->t[2][2] = 1;
	matrix_0->t[2][3] = 3;
	matrix_0->t[3][0] = 0;
	matrix_0->t[3][1] = 0;
	matrix_0->t[3][2] = 0;
	matrix_0->t[3][3] = 1;
	//print_matrix4x4(*matrix_0);
	//vector = multiply_v3_m4x4(&vector, matrix_0);
	//print_vector3(*vector);
	//print_matrix4x4(*matrix_0);
	printf("Start parsing\n");
	terrain = parse_file(argv[1]);
	if(terrain == NULL)
		return (-1);
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
    return (0);
}