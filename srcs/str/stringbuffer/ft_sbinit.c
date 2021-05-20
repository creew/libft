/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 11:37:00 by eklompus          #+#    #+#             */
/*   Updated: 2020/08/23 11:37:00 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ftresult	ft_sbinit(t_sb *sb, size_t size)
{
	char	*buf;

	if (size == 0)
		size = 64;
	buf = ft_strnew(size);
	if (buf == NULL)
		return (FT_ENOMEM);
	sb->size = size;
	sb->buf = buf;
	sb->length = 0;
	return (FT_OK);
}
