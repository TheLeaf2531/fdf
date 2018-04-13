/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:09:56 by vboissel          #+#    #+#             */
/*   Updated: 2018/04/13 20:54:44 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "matrix4x4.h"
#include "printer.h"
#include "parser.h"

int     main(int argc, char **argv)
{
	t_vector3 *vector;
	t_matrix4x4 *matrix_0;
    (void)argc;
    (void)argv;
	vector = new_vector3(0, 2 ,3);
	print_vector3(*vector);
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
	print_matrix4x4(*matrix_0);
	vector = multiply_v3_m4x4(&vector, matrix_0);
	print_vector3(*vector);
	//print_matrix4x4(*matrix_0); 	
	parse_file(argv[1]);
    return (0);
}