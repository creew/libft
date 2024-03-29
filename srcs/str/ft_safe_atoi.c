/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:30:57 by eklompus          #+#    #+#             */
/*   Updated: 2019/11/04 14:30:57 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	process_atoi(const char *arg, int *res, int is_neg)
{
	int	val;

	val = (unsigned char)*arg++;
	while (val)
	{
		if (val < '0' || val > '9')
			return (FT_ATOI_WRONG_CHAR);
		val = (val - '0') * is_neg;
		if (*res > FT_INTMAX / 10
			|| (*res == FT_INTMAX / 10 && val > FT_INTMAX % 10))
			return (FT_ATOI_OVERFLOW);
		if (*res < (-FT_INTMAX - 1) / 10
			|| (*res == (-FT_INTMAX - 1) / 10 && val < (-FT_INTMAX - 1) % 10))
			return (FT_ATOI_OVERFLOW);
		*res = *res * 10;
		*res = *res + val;
		val = (unsigned char)*arg++;
	}
	return (FT_ATOI_OK);
}

/*
**	Безопасная реализация функции ft_atoi
**	@param arg - строка содержащая значение
**	@param res - указатель на int, в который будет записано числовое
** значение при успешном выполнении
**	@return
**		FT_ATOI_OK - успешное выполнение<br>
**		FT_ATOI_EMPTY_ARG - была передана пустая строка<br>
**		FT_ATOI_WRONG_CHAR - в строке были нечисловые символы<br>
**		FT_ATOI_OVERFLOW - переданное значение выходит за пределы int<br>
*/

int	ft_safe_atoi(const char *arg, int *res)
{
	int		is_neg;

	*res = 0;
	is_neg = 1;
	if (*arg == '+' || *arg == '-')
	{
		if (*arg == '-')
			is_neg = -1;
		arg++;
	}
	if (*arg == '\0')
		return (FT_ATOI_EMPTY_ARG);
	return (process_atoi(arg, res, is_neg));
}
