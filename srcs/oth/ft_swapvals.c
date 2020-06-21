/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapvals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:53:41 by eklompus          #+#    #+#             */
/*   Updated: 2020/02/25 11:53:41 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function swaps values between first and second pointers with size elem_size
*/

void		ft_swapvals(char *d1, char *d2, size_t elem_size)
{
	int				itmp;
	char			ctmp;

	if (d1 != d2)
	{
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
}
