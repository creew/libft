/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringbuffer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 10:53:00 by eklompus          #+#    #+#             */
/*   Updated: 2020/08/23 10:53:00 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGBUFFER_H
# define STRINGBUFFER_H

# include "errors.h"

typedef struct s_sb {
	size_t	size;
	size_t	length;
	char	*buf;
}				t_sb;

t_ftresult	ft_sbappendstr(t_sb *sb, const char *str);
t_ftresult	ft_sbappendchar(t_sb *sb, char c);
void		ft_sbclear(t_sb *sb);
void		ft_sbdelete(t_sb **sb);
char		*ft_sbget(t_sb *sb);
t_ftresult	ft_sbinit(t_sb *sb, size_t size);
size_t		ft_sblen(t_sb *sb);
t_sb		*ft_sbnew(size_t size);
void		ft_sbremove(t_sb *sb);

#endif
