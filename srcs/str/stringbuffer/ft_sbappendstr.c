/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbappend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 10:59:00 by eklompus          #+#    #+#             */
/*   Updated: 2020/08/23 10:59:00 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ftresult	ft_sbappendstr(t_sb *sb, const char *str)
{
	size_t	slen;
	char	*buf;
	char	*tbuf;
	size_t	need;

	slen = ft_strlen(str);
	need = sb->length + slen;
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
	ft_strcpy(sb->buf + sb->length, str);
	sb->length += slen;
	return FT_OK;
}