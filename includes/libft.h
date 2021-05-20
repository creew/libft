/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:48:17 by eklompus          #+#    #+#             */
/*   Updated: 2019/10/06 17:36:48 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "get_next_line.h"
# include "array.h"
# include "lst.h"
# include "str.h"
# include "out.h"
# include "errors.h"

# define FT_INTMAX	(2147483647)

# define FT_LONGMAX	(9223372036854775807)

# define FT_EOF (-2)

typedef unsigned long	t_bzero_elem;

typedef struct s_qsort
{
	void	*arr;
	size_t	elem_size;
	int		(*cmp)(const void *, const void *);
}	t_qsort;

typedef t_ftarray		t_ftstack;

typedef t_list			t_ftqueue;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memrealloc(void *data, size_t old_size, size_t new_size);
void			*ft_memndup(const void *mem, size_t size);
void			ft_intmove(int *dst, int *src, size_t size);
int				ft_getc(int fd);
int				ft_stack_init(t_ftstack *stack, size_t init_val);
int				ft_stack_pop(t_ftstack *stack, void **data);
int				ft_stack_push(t_ftstack *stack, void *data);
void			ft_stack_delall(t_ftstack *stack, void (*f)(void *));
size_t			ft_stack_size(t_ftstack *stack);
int				ft_queue_add(t_ftqueue **queue, void *data);
int				ft_queue_poll(t_ftqueue **queue, void **data);
int				ft_abs(int a);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
void			ft_bubble_sort(void *arr, size_t arr_size, size_t elem_size,
					int (*cmp)(const void *, const void *));
void			*ft_calloc(size_t count, size_t size);
void			ft_voidcpy(void **dst, void **src, size_t size);
void			ft_qsort(void *arr, size_t arr_size, size_t elem_size,
					int (*cmp)(const void *, const void *));
size_t			ft_intlen(int n);
void			ft_swapvals(char *d1, char *d2, size_t elem_size);
#endif
