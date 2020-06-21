/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_delete_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:43:34 by eklompus          #+#    #+#             */
/*   Updated: 2019/11/17 17:43:35 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_array_delete_all(t_ftarray **arr, void (*f)(void *))
{
	if (arr)
	{
		ft_array_remove_all(*arr, f);
		ft_memdel((void **)arr);
	}
}
