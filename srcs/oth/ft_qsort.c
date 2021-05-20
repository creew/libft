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

static void	qsort_int(t_qsort *qs, int start, int end)
{
	char	*pivot;
	int		i;
	int		j;
	char	*ppos;

	if (start < end)
	{
		j = start - 1;
		i = start;
		ppos = (char *)qs->arr + start * qs->elem_size;
		pivot = (char *)qs->arr + end * qs->elem_size;
		while (++j < end)
		{
			if (qs->cmp(ppos, pivot) < 0)
				ft_swapvals(ppos, (char *)qs->arr + (i++) * qs->elem_size,
					qs->elem_size);
			ppos += qs->elem_size;
		}
		ft_swapvals((char *)qs->arr + i * qs->elem_size, pivot, qs->elem_size);
		qsort_int(qs, start, i - 1);
		qsort_int(qs, i + 1, end);
	}
}

void	ft_qsort(void *arr, size_t arr_size, size_t elem_size,
			int (*cmp)(const void *, const void *))
{
	t_qsort		qs;

	qs.arr = arr;
	qs.elem_size = elem_size;
	qs.cmp = cmp;
	qsort_int(&qs, 0, (int)arr_size - 1);
}
