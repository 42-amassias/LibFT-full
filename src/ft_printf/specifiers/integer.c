/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antoine Massias <massias.antoine.pro@gm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:33:38 by amassias          #+#    #+#             */
/*   Updated: 2024/05/11 17:58:51 by Antoine Mas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file integer.c
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

int	printer__integer(
		int fd,
		va_list list,
		t_format *fmt)
{
	static t_number_base	_base = (t_number_base){
	{.size = sizeof(BASE) - 1, .str = BASE},
	{.size = sizeof(PREFIX) - 1, .str = PREFIX},
		1,
	};
	long long				n;

	n = (long long) va_arg(list, int);
	return (integer_printer_fd(fd, fmt, &_base, n));
}
