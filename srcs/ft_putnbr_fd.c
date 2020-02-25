/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:45:24 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/04 19:23:17 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	char	buf[16];
	int		nb;
	int		len;

	nb = n;
	len = ft_intlen(n);
	buf[len] = 0;
	if (nb == 0)
		buf[--len] = '0';
	else
	{
		while (nb)
		{
			buf[--len] = (char)(ft_abs(nb % 10) + '0');
			nb /= 10;
		}
		if (n < 0)
			buf[--len] = '-';
	}
	ft_putstr_fd(buf, fd);
}
