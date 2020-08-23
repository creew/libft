/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbappendchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 11:13:00 by eklompus          #+#    #+#             */
/*   Updated: 2020/08/23 11:13:00 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ftresult	ft_sbappendchar(t_sb *sb, char c)
{
	char	*buf;
	char	*tbuf;
	size_t	need;

	need = sb->length + 1;
	if (sb->size < need)
	{
		need = need + (need >> 1ul) + 1;
		buf = ft_strnew(need);
		if (buf == NULL)
			return FT_ENOMEM;
		ft_memcpy(buf, sb->buf, sb->length);
		tbuf = sb->buf;
		sb->buf = buf;
		ft_strdel(&tbuf);
		sb->size = need;
	}
	sb->buf[sb->length++] = c;
	sb->buf[sb->length] = 0;
	return FT_OK;
}
