/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 10:51:00 by eklompus          #+#    #+#             */
/*   Updated: 2020/08/23 10:51:00 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sb	*ft_sbnew(size_t size)
{
	t_sb	*sb;

	sb = ft_memalloc(sizeof(t_sb));
	if (sb == NULL)
		return NULL;
	if (ft_sbinit(sb, size) != FT_OK)
	{
		ft_memdel((void **)&sb);
		return NULL;
	}
	return (sb);
}
