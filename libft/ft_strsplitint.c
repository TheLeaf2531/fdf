/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:46:26 by vboissel          #+#    #+#             */
/*   Updated: 2018/04/18 17:36:20 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_strsplitint(char *str, int c)
{
	char	**str_tab;
	int 	*tab;
	size_t	size;
	size_t	i;

	if (str == NULL)
		return (NULL);
	str_tab = ft_strsplit(str, c);
	if (str_tab == NULL)
		return (NULL);
	i = 0;
	size = ft_strsplitcnt(str, c);
	tab = ft_memalloc(sizeof(int) * size);
	if (tab == NULL)
		return (NULL);
	while (i < size)
	{
		tab[i] = ft_atoi(str_tab[i]);
		ft_memdel((void**)&(str_tab[i]));
		i++;
	}
	ft_memdel((void**)str_tab);
	return (tab);
}