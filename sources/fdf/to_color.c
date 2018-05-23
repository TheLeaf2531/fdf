/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:58:36 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/21 17:11:54 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	to_color(unsigned int r, unsigned int g,
							unsigned int b, unsigned int a)
{
	unsigned int argb;

	argb = (
			(((a > 0xff) ? 0xff : a) << 24) |
			(((r > 0xff) ? 0xff : r) << 16) |
			(((g > 0xff) ? 0xff : g) << 8) |
			(((b > 0xff) ? 0xff : b))
	);
	return (argb);
}