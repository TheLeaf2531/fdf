/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 16:57:16 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/20 18:18:45 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>

typedef	struct	s_vector3
{
	float	x;
	float	y;
	float	z;
}				t_vector3;

t_vector3		*new_vector3(float x, float y, float z);
void			to_zero(t_vector3 *vector);
void			set_vector3(t_vector3 *vector, float x, float y, float z);
void 			normalize(t_vector3 *vector);

#endif
