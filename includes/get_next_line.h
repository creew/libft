/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:04:29 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/19 19:29:41 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE (512000)

typedef struct s_fddata
{
	struct s_fddata	*next;
	int				fd;
	char			*tail;
	int				tail_len;
	int				tail_pos;
	char			eof;
}				t_fddata;

int				get_next_line(const int fd, char **line);

#endif
