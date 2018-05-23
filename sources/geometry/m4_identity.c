/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_identity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:05:13 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/22 16:38:33 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_matrix4		m4_identity(void)
{
	return ((t_matrix4){{
		{(double)1.0, (double)0.0, (double)0.0, (double)0.0},
		{(double)0.0, (double)1.0, (double)0.0, (double)0.0},
		{(double)0.0, (double)0.0, (double)1.0, (double)0.0},
		{(double)0.0, (double)0.0, (double)0.0, (double)1.0}
	}});
}
