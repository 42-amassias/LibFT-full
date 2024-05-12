/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antoine Massias <massias.antoine.pro@gm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 05:25:18 by amassias          #+#    #+#             */
/*   Updated: 2024/05/12 16:52:27 by Antoine Mas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file pointer.c
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

#include <stdint.h>

/* ************************************************************************** */
/*                                                                            */
/* Defines                                                                    */
/*                                                                            */
/* ************************************************************************** */

#define BASE "0123456789abcdef"
#define PREFIX "0x"

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

int	printer__pointer(
		int fd,
		va_list args,
		t_format *fmt)
{
	static t_number_base	_base = (t_number_base){
	{.size = sizeof(BASE) - 1, .str = BASE},
	{.size = sizeof(PREFIX) - 1, .str = PREFIX},
		0,
	};
	uintptr_t				n;

	n = (uintptr_t) va_arg(args, void *);
	if (n == 0)
		return (string_printer_fd(fd, fmt, "(nil)"));
	fmt->flags |= FMT_FLAG__PREFIX;
	return (integer_printer_fd(fd, fmt, &_base, n));
}
