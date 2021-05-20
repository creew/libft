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

/**
 * Копирование последних данных в строку
 *
 * @param cur - структура для текущего fd
 * @param line - указатель на строку для возврата
 * @param last - флаг, является ли вызов последним
 * @return  -1 - ошибка выделения памяти
 * 			1 - успех
 */
static int	check_last(t_fddata *cur, char **line, int last)
{
	char	*newline;
	int		pos;

	pos = cur->tail_pos;
	if (last && pos != cur->tail_len)
	{
		newline = ft_memalloc(cur->tail_len - pos + 1);
		if (!newline)
			return (-1);
		ft_memcpy(newline, cur->tail + pos, cur->tail_len - pos);
		newline[cur->tail_len - pos] = '\0';
		*line = newline;
		cur->tail_pos = cur->tail_len;
		cur->eof = 1;
		return (1);
	}
	return (0);
}

/**
 * Находит строку в массиве данных
 *
 * @param cur - структура для текущего fd
 * @param line - указатель на строку для возврата
 * @param last - флаг, является ли вызов последним
 * @param res - результат вызова функции read
 * @return	0 - строка не найдена
 * 			1 - строка найдена, записана в **line
 * 			-1 - ошибка
 */
static int	find_in_tail(t_fddata *cur, char **line, int last, int res)
{
	int		pos;
	char	*posn;
	char	*newline;
	long	len;

	if (res < 0)
		return (-1);
	pos = cur->tail_pos;
	posn = ft_memchr(cur->tail + pos, '\n', cur->tail_len - pos);
	if (posn)
	{
		len = posn - (cur->tail + pos);
		if (posn - cur->tail != cur->tail_len - 1 || last)
		{
			newline = ft_memalloc(len + 1);
			if (!newline)
				return (-1);
			ft_memcpy(newline, cur->tail + pos, len);
			newline[len] = '\0';
			*line = newline;
			cur->tail_pos += (int)(len + 1);
			return (1);
		}
	}
	return (check_last(cur, line, last));
}

/**
 * Ищет строку, при необходимости читает данные
 * @param cur - структура для текущего fd
 * @param line - указатель на строку для возврата
 * @param res - dirty hack
 * @return	0 - строка не найдена
 * 			1 - строка найдена, записана в **line
 * 			-1 - ошибка
 */
static int	find_next(t_fddata *cur, char **line, int res)
{
	char	buf[BUFF_SIZE];
	char	*newdata;

	res = find_in_tail(cur, line, 0, 1);
	if (res != 0)
		return (res);
	res = read(cur->fd, buf, BUFF_SIZE);
	while (res > 0)
	{
		newdata = (char *)malloc(res + cur->tail_len - cur->tail_pos);
		if (!newdata)
			return (-1);
		ft_memcpy(newdata, cur->tail + cur->tail_pos,
			cur->tail_len - cur->tail_pos);
		ft_memcpy(newdata + cur->tail_len - cur->tail_pos, buf, res);
		ft_memdel((void **)&cur->tail);
		cur->tail_len = res + cur->tail_len - cur->tail_pos;
		cur->tail = newdata;
		cur->tail_pos = 0;
		res = find_in_tail(cur, line, 0, 1);
		if (res != 0)
			return (res);
		res = read(cur->fd, buf, BUFF_SIZE);
	}
	return (find_in_tail(cur, line, 1, res));
}

static int	free_data(int res, t_fddata **prev, t_fddata *cur)
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

int	get_next_line(const int fd, char **line)
{
	static t_fddata	*fd_root;
	t_fddata		*cur;
	t_fddata		**prev;

	prev = &fd_root;
	cur = fd_root;
	while (cur && cur->fd != fd)
	{
		prev = &cur->next;
		cur = cur->next;
	}
	if (!cur)
	{
		prev = &fd_root;
		cur = ft_memalloc(sizeof(t_fddata));
		if (cur == NULL)
			return (-1);
		cur->fd = fd;
		cur->next = fd_root;
		fd_root = cur;
	}
	if (cur->eof)
		return (free_data(0, prev, cur));
	return (free_data(find_next(cur, line, 0), prev, cur));
}
