/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:16:20 by eklompus          #+#    #+#             */
/*   Updated: 2019/11/13 16:16:20 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_array_add(t_ftarray *arr, void *data)
{
	void	**newarr;
	void	**old;
	size_t	new_size;

	if (arr->num_elems >= arr->max_elems)
	{
		new_size = arr->max_elems + (arr->max_elems >> 1ul) + 1;
		newarr = ft_calloc(new_size, sizeof(void *));
		if (!newarr)
			return (FT_ENOMEM);
		if (arr->data)
			ft_voidcpy(newarr, arr->data, arr->max_elems);
		old = arr->data;
		arr->data = newarr;
		arr->max_elems = new_size;
		ft_memdel((void **)&old);
	}
	arr->data[arr->num_elems++] = data;
	return (FT_OK);
}
