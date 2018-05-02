/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4x4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 17:41:05 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/02 19:19:32 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix4x4.h"

t_matrix4x4		*multiply_m4x4(t_matrix4x4 *a, t_matrix4x4 *b)
{
	t_matrix4x4	*c;
	int			i_0;
	int			i_1;

	c = malloc(sizeof(t_matrix4x4));
	if (c == NULL)
		return (NULL);
	i_0 = 0;
	i_1 = 0;
	while (i_0 < 4)
	{
		c->t[i_0][i_1] = a->t[i_0][0] * b->t[0][i_1] +
						a->t[i_0][1] * b->t[1][i_1] +
						a->t[i_0][2] * b->t[2][i_1] +
						a->t[i_0][3] * b->t[3][i_1];
		i_0 = i_1 == 3 ? i_0 + 1 : i_1;
		i_1 = i_1 == 3 ? 0 : i_1;
	}
	return (c);
}

t_matrix4x4		*identity_m4x4()
{
	t_matrix4x4 *identity;

	identity = ft_memalloc(sizeof(t_matrix4x4));
	if (identity == NULL)
		return (NULL);
	identity->t[0][0] = 1;
	identity->t[0][1] = 0;
	identity->t[0][2] = 0;
	identity->t[0][3] = 0;
	identity->t[1][0] = 0;
	identity->t[1][1] = 1;
	identity->t[1][2] = 0;
	identity->t[1][3] = 0; 
	identity->t[2][0] = 0;
	identity->t[2][1] = 0;
	identity->t[2][2] = 1;
	identity->t[2][3] = 0;
	identity->t[3][0] = 0;
	identity->t[3][1] = 0;
	identity->t[3][2] = 0;
	identity->t[3][3] = 1;
	return (identity);
}
