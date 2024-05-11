/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antoine Massias <massias.antoine.pro@gm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 06:55:10 by amassias          #+#    #+#             */
/*   Updated: 2024/05/11 18:07:48 by Antoine Mas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file hex_up.c
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

#define BASE "0123456789ABCDEF"
#define PREFIX "0X"

/* ************************************************************************** */
/*                                                                            */
/* Header implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

int	printer__up_hex(
		int fd,
		va_list args,
		t_format *fmt)
{
	static t_number_base	_base = (t_number_base){
	{.size = sizeof(BASE) - 1, .str = BASE},
	{.size = sizeof(PREFIX) - 1, .str = PREFIX},
		0,
	};
	long long				x;

	x = (long long) va_arg(args, unsigned int);
	fmt->flags &= ~(FMT_FLAG__ALIGN_SIGN | FMT_FLAG__FORCE_SIGN);
	return (integer_printer_fd(fd, fmt, &_base, x));
}
