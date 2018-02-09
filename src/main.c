/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:28:48 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/09 16:36:27 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../libft/libft.h"
#include "../include/main.h"
#include "../include/file_checker.h"
#include "../include/file_parser.h"
#include <stdio.h>

int		main(int argc, char const *argv[])
{
	t_grid	*grid;
	size_t	x;
	size_t	y;

	if (argc != 2)
		return (0);
	x = 0;
	y = 0;
	grid = file_parser(argv[1]);
	free_grid(&grid);
	return (0);
}
