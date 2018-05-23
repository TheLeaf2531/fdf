/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 17:49:43 by vboissel          #+#    #+#             */
/*   Updated: 2018/05/20 21:15:12 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			check_file(t_fdf_file *file)
{
	size_t	width;
	size_t	i;
	char	*str;
	t_list	*tmp;

	tmp = file->lines;
	width = ft_strsplitcnt(file->lines->content, ' ');
	while (tmp)
	{
		str = tmp->content;
		i = 0;
		if (width != ft_strsplitcnt(str, ' '))
			return (-1);
		while (str[i])
		{
			if (!ft_isspace(str[i]) && !ft_isdigit(str[i]) &&
				!ft_issign(str[i]))
				return (-1);
			i++;
		}
		tmp = tmp->next;
	}
	return (width);
}
