/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_remove_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:06:51 by eklompus          #+#    #+#             */
/*   Updated: 2019/11/14 12:06:51 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_array_remove_all(t_ftarray *arr, void (*f)(void *))
{
	if (arr)
	{
		if (f)
		{
			while (arr->num_elems)
			{
				f(arr->data[arr->num_elems - 1]);
				arr->num_elems--;
			}
		}
		else
		{
			arr->num_elems = 0;
		}
		ft_memdel((void **)&arr->data);
		arr->max_elems = 0;
	}
}
