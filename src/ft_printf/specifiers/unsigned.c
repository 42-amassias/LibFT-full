/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antoine Massias <massias.antoine.pro@gm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:33:38 by amassias          #+#    #+#             */
/*   Updated: 2024/05/11 17:59:23 by Antoine Mas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file unsigned.c
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-10-19
 * @copyright Copyright (c) 2023
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* ************************************************************************** */
/*                                                                            */
/* Defines                                                                    */
/*                                                                            */
/* ************************************************************************** */

#define BASE "0123456789"
#define PREFIX ""

/* ************************************************************************** */
/*                                                                            */
/* Header implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

int	printer__unsigned(
		int fd,
		va_list list,
		t_format *fmt)
{
	static t_number_base	_base = (t_number_base){
	{.size = sizeof(BASE) - 1, .str = BASE},
	{.size = sizeof(PREFIX) - 1, .str = PREFIX},
		0,
	};
	long long				n;

	n = (long long) va_arg(list, unsigned int);
	fmt->flags &= ~(FMT_FLAG__ALIGN_SIGN | FMT_FLAG__FORCE_SIGN);
	return (integer_printer_fd(fd, fmt, &_base, n));
}
