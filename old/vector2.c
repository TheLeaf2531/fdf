/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 18:35:21 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/12 18:37:48 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector2.h"

t_vector2	*new_vector2(int x, int y)
{
	t_vector2 *vector2;

	vector2 = ft_memalloc(sizeof(t_vector2));
	vector2->x = x;
	vector2->y = y;
	return (vector2);
}