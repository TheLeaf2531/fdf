/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:49:47 by vboissel          #+#    #+#             */
/*   Updated: 2018/04/13 20:13:48 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "vector3.h"

typedef	struct	s_triangle
{
	t_vector3	v0;
	t_vector3	v1;
	t_vector3	v2;
}				t_triangle;

#endif
