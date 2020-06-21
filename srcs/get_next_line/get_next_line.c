/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:02:39 by eklompus          #+#    #+#             */
/*   Updated: 2020/02/25 11:02:43 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdlib.h>
#include "get_next_line.h"

static int		check_last(t_fddata *cur, char **line)
{
	char	*newline;
	int		pos;

	pos = cur->tail_pos;
	if (!(newline = ft_memndup(cur->tail + pos, (cur->tail_len - pos) + 1)))
		return (-1);
	newline[cur->tail_len - pos] = '\0';
	*line = newline;
	cur->tail_pos = cur->tail_len;
	cur->eof = 1;
	return (1);
}

static int		find_in_tail(t_fddata *cur, char **line, int last)
{
	int		pos;
	char	*posn;
	char	*newline;
	long	len;

	pos = cur->tail_pos;
	if ((posn = ft_memchr(cur->tail + pos, '\n', cur->tail_len - pos)))
	{
		len = posn - (cur->tail + pos);
		if (posn - cur->tail != cur->tail_len - 1 || last)
		{
			if (!(newline = ft_memndup(cur->tail + pos, len + 1)))
				return (-1);
			newline[len] = '\0';
			*line = newline;
			cur->tail_pos += (int)(len + 1);
			return (1);
		}
	}
	if (last && pos != cur->tail_len)
		return (check_last(cur, line));
	return (0);
}

static int		find_next(t_fddata *cur, char **line)
{
	char	buf[BUFF_SIZE];
	int		res;
	char	*newdata;
	int		old_len;

	if (cur->eof)
		return (0);
	if ((res = find_in_tail(cur, line, 0)) != 0)
		return (res);
	while ((res = read(cur->fd, buf, BUFF_SIZE)) > 0)
	{
		old_len = cur->tail_len - cur->tail_pos;
		if (!(newdata = (char *)malloc(res + old_len)))
			return (-1);
		ft_memcpy(newdata, cur->tail + cur->tail_pos, old_len);
		ft_memcpy(newdata + old_len, buf, res);
		ft_memdel((void **)&cur->tail);
		cur->tail_len = res + old_len;
		cur->tail = newdata;
		cur->tail_pos = 0;
		if ((res = find_in_tail(cur, line, 0)) != 0)
			return (res);
	}
	return (res < 0 ? -1 : find_in_tail(cur, line, 1));
}

static int		free_data(int res, t_fddata **prev, t_fddata *cur)
{
	t_fddata	*next;

	if (res <= 0)
	{
		next = cur->next;
		ft_memdel((void **)&cur->tail);
		ft_memdel((void **)&cur);
		*prev = next;
	}
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	static t_fddata	*fd_root;
	t_fddata		*cur;
	t_fddata		**prev;
	int				res;

	prev = &fd_root;
	cur = fd_root;
	while (cur)
	{
		if (cur->fd == fd)
			break ;
		prev = &cur->next;
		cur = cur->next;
	}
	if (!cur)
	{
		prev = &fd_root;
		if ((cur = ft_memalloc(sizeof(t_fddata))) == NULL)
			return (-1);
		cur->fd = fd;
		cur->next = fd_root;
		fd_root = cur;
	}
	res = find_next(cur, line);
	return (free_data(res, prev, cur));
}
