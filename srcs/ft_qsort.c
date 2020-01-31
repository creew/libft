/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 09:32:28 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/31 09:32:29 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compare function return negative value if first elem less than second,
** and positive value if first greater than second
*/

static void		qsort_swap(t_qsort *qs, char *d1, char *d2)
{
	size_t			elem_size;
	int				itmp;
	char			ctmp;

	elem_size = qs->elem_size;
	while (elem_size >= sizeof(itmp))
	{
		itmp = *(int *)d1;
		*(int *)d1 = *(int *)d2;
		*(int *)d2 = itmp;
		elem_size -= sizeof(itmp);
		d1 += sizeof(itmp);
		d2 += sizeof(itmp);
	}
	while (elem_size-- > 0)
	{
		ctmp = *d1;
		*d1++ = *d2;
		*d2++ = ctmp;
	}
}

static void		qsort_int(t_qsort *qs, size_t start, size_t end)
{
	char	*pivot;
	size_t	i;
	size_t	j;
	char	*ppos;

	if (start < end)
	{
		j = start - 1;
		i = 0;
		ppos = (char *)qs->arr + start * qs->elem_size;
		pivot = (char *)qs->arr + end * (qs->elem_size - 1);
		while (++j <= end)
		{
			if (qs->cmp(ppos, pivot) < 0 && j != i)
				qsort_swap(qs, ppos, (char *)qs->arr + i++ * qs->elem_size);
			ppos += qs->elem_size;
		}
		qsort_swap(qs, (char *)qs->arr + i * qs->elem_size, pivot);
		qsort_int(qs, start, i);
		qsort_int(qs, i + 1, end);
	}
}

void			ft_qsort(void *arr, size_t arr_size, size_t elem_size,
						int (*cmp)(const void *, const void *))
{
	t_qsort		qs;

	qs.arr = arr;
	qs.elem_size = elem_size;
	qs.cmp = cmp;
	qsort_int(&qs, 0, arr_size - 1);
}
