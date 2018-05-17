/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_printl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 19:18:43 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/17 19:19:37 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

void	v3_printl(t_vector3 v)
{
	printf("\n[%f] [%f] [%f] [%f]\n", v.x, v.y, v.z, v.w);
}