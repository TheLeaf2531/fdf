/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:28:48 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/09 18:45:12 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../libft/libft.h"
#include "../include/main.h"
#include "../include/file_checker.h"
#include "../include/file_parser.h"
#include "../include/vector2.h"
#include "../include/drawer.h"
#include <stdio.h>

typedef	struct	s_window
{
	void 	*mlx_ptr;
	void 	*win_ptr;
}				t_window;

int		mouse_test(int button, int x, int y, void *param)
{
	static		t_vector2 *start;
	static		t_vector2 *end;
	t_window	*win;

	win = param;
	if (!start)
	{
		start = malloc(sizeof(t_vector2));
		end = malloc(sizeof(t_vector2));
		start->x = -1;
		end->x = -1;
		start->y = -1;
		end->y = -1;
	}
	if (start->x < 0)
	{
		start->x = x;
		start->y = y;
	}
	else
	{
		end->x = x;
		end->y = y;
		draw_line(*start, *end, win->win_ptr, win->mlx_ptr);
	}
	printf("button : %d, x : %d, y : %d\n", button, x, y);
	return (0);
}

int		main(int argc, char const *argv[])
{
	t_grid		*grid;
	t_window	*window;

	if (argc != 4)
		return (0);
	grid = file_parser(argv[1]);
	window = malloc(sizeof(t_window));
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, ft_atoi(argv[2]),
				ft_atoi(argv[3]), grid->grid_name);
	free_grid(&grid);
	mlx_mouse_hook(window->win_ptr, mouse_test, window);
	mlx_loop(window->mlx_ptr);
	return (0);
}
