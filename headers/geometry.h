/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:13:30 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/24 19:31:29 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include <math.h>

# define PI	3.14159265359

typedef	struct	s_vector2i
{
	int		x;
	int		y;
}				t_vector2i;

typedef	struct	s_vector2l
{
	int		x;
	int		y;
}				t_vector2l;

typedef	struct	s_vector2
{
	long double		x;
	long double		y;
}				t_vector2;

typedef struct	s_vector3
{
	long double x;
	long double y;
	long double z;
	long double w;
}				t_vector3;

typedef struct	s_matrix3
{
	double t[3][3];
}				t_matrix3;

typedef struct	s_matrix4
{
	long double t[4][4];
}				t_matrix4;

typedef struct	s_rectanglei
{
	t_vector2i	max;
	t_vector2i	min;
}				t_rectanglei;

t_vector2		vec2_set(double x, double y);
t_vector2i		vec2i_set(int x, int y);
t_vector2l		vec2l_set(long x, long y);

t_vector3		vec3_set(double x, double y, double z);
double			vec3_magnitude(t_vector3 v);
t_vector3		vec3_normalize(t_vector3 vec);
t_vector3		vec3_to_radians(t_vector3 rot);
t_vector3		vec3_to_degrees(t_vector3 rot);

t_matrix3		m3_identity(void);
double			m3_determinant(t_matrix3 m);
t_matrix3		m3_inverse(t_matrix3 m);

t_matrix4		m4_identity(void);
t_matrix4		m4_multiply(t_matrix4 a, t_matrix4 b);
t_matrix4		m4_swap_row(t_matrix4 m, int r1, int r2);
double			m4_determinant(t_matrix4 m);
t_matrix4		m4_inverse(t_matrix4 m);
t_matrix3		m4_as_m3(t_matrix4 m);
t_vector3		m4_multiply_v3(t_matrix4 m, t_vector3 v);
t_matrix4		m4_euler(t_vector3 rot);
t_matrix4		m4_translation(t_vector3 pos);
t_matrix4		m4_invert_translation(t_vector3 pos);

t_rectanglei	reci_set(int minx, int miny, int maxx, int maxy);

double			to_radians(double ang);
double			to_degrees(double ang);

#endif
