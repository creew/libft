/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 11:19:00 by eklompus          #+#    #+#             */
/*   Updated: 2020/08/23 11:19:00 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef enum	e_ftresult
{
	FT_OK,
	FT_ERROR,
	FT_ENOMEM,
	FT_INDEX_OUT_OF_BOUNDS,
	FT_NULL_POINTER
}				t_ftresult;

typedef enum	e_ftatoiresult
{
	FT_ATOI_OK = 0,
	FT_ATOI_OVERFLOW = 1,
	FT_ATOI_EMPTY_ARG = 2,
	FT_ATOI_WRONG_CHAR = 3
}				t_ftatoiresult;

#endif
