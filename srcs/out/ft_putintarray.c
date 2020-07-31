//
// Created by eklompus on 8/1/20.
//
#include "libft.h"

void ft_putintarray(int *arr, size_t size, char *name) {
	size_t	pos;
	size_t	last_size;

	if (name != NULL)
	{
		ft_putstr(name);
		ft_putstr(": ");
	}
	ft_putstr("{");
	if (size > 0)
	{
		pos = -1;
		last_size = size - 1;
		while (++pos < last_size)
		{
			ft_putnbr(arr[pos]);
			ft_putstr(", ");
		}
		ft_putnbr(arr[last_size]);
	}
	ft_putendl("}");
}