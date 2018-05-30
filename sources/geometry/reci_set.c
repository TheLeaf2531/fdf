/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reci_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:40:16 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/27 20:44:05 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_rectanglei reci_set(int minx, int miny, int maxx, int maxy)
{
    return ((t_rectanglei){
        (t_vector2i){minx, miny},
        (t_vector2i){maxx, maxy}
    });
}