/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4x4_invert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:13:26 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/02 19:19:12 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix4x4.h"

t_matrix4x4		*swap_row(t_matrix4x4 *m, int r1, int r2)
{
	t_matrix4x4	temp;
	int			x;

	x = 0;
	while (x < 4)
	{
		temp.t[r1][x] = m->t[r1][x];
		temp.t[r2][x] = m->t[r2][x];
		x++;
	}
	x = 0;
	while (x < 4)
	{
		m->t[r1][x] = temp.t[r2][x];
		m->t[r2][x] = temp.t[r1][x];
		x++;
	}
	return (m);
}

void			invert_2(t_matrix4x4 **m, t_matrix4x4 **inv, int k)
{
	int		i;
	int		tmp;
	float	coeff;

	i = -1;
	while (++i < 4)
	{
		if (i != k)
		{
			coeff = (*m)->t[i][k];
			if (coeff != 0)
			{
				tmp = -1;
				while (++tmp < 4)
				{
					(*m)->t[i][tmp] -= coeff * (*m)->t[k][tmp];
					(*inv)->t[i][tmp] -= coeff * (*inv)->t[k][tmp];
				}
			}
		}
	}
}

int				invert_1_5(t_matrix4x4 **m, t_matrix4x4 **inv)
{
	int		k;
	int		i;
	int		bgst;

	k = -1;
	while (++k < 4)
	{
		if ((*m)->t[k][k] == 0)
		{
			bgst = k;
			i = -1;
			while (++i < 4)
			{
				if (fabs((*m)->t[i][k]) > fabs((*m)->t[bgst][k]))
					bgst = i;
			}
			swap_row(*inv, k, bgst);
			swap_row(*m, k, bgst);
		}
	}
	return (0);
}

int				invert_1(t_matrix4x4 **m, t_matrix4x4 **inv)
{
	int		k;
	int		i;
	float	pivot;

	k = -1;
	while (++k < 4)
	{
		i = -1;
		pivot = (*m)->t[k][k];
		while (++i < 4)
		{
			(*m)->t[k][i] /= pivot;
			(*inv)->t[k][i] /= pivot;
		}
		invert_2(m, inv, k);
	}
	return (0);
}

t_matrix4x4		*invert_m4x4(t_matrix4x4 *m)
{
	int			row;
	int			column;
	t_matrix4x4 *inv;

	if ((inv = identity_m4x4()) == NULL)
		return (NULL);
	if (invert_1(&m, &inv) == -1)
		return (NULL);
	row = -1;
	while (++row < 4)
	{
		column = -1;
		while (++column < 4)
		{
			m->t[row][column] /= m->t[row][row];
			inv->t[row][column] /= m->t[row][row];
		}
	}
	ft_memdel((void**)&m);
	return (inv);
}
