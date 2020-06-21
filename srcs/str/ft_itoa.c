/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:04:16 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/08 16:52:08 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*s;
	int		nb;
	int		len;

	nb = n;
	len = ft_intlen(n);
	if (!(s = ft_strnew(len)))
		return (NULL);
	s[len] = '\0';
	if (nb == 0)
		s[--len] = '0';
	else
	{
		while (nb)
		{
			s[--len] = (char)(ft_abs(nb % 10) + '0');
			nb /= 10;
		}
		if (n < 0)
			s[--len] = '-';
	}
	return (s);
}
