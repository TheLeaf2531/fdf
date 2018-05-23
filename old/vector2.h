/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 18:33:20 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/17 17:02:19 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

#include "libft/libft.h"

typedef	struct	s_vector2
{
	int		x;
	int		y;
}				t_vector2;

t_vector2		*new_vector2(int x, int y);

#endif
