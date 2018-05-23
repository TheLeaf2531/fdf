/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m3_identity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 19:54:29 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/22 16:35:00 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_matrix3		m3_identity(void)
{
	return ((t_matrix3){{
		{(double)1.0, (double)0.0, (double)0.0},
		{(double)0.0, (double)1.0, (double)0.0},
		{(double)0.0, (double)0.0, (double)1.0}}
	});
}
