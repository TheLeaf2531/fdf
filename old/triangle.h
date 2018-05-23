/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:49:47 by vboissel          #+#    #+#             */
/*   Updated: 2018/04/16 19:41:47 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "vector3.h"

typedef	struct	s_triangle
{
	t_vector3	*p0;
	t_vector3	*p1;
	t_vector3	*p2;
}				t_triangle;

#endif
