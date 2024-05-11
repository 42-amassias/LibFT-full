/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antoine Massias <massias.antoine.pro@gm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 03:58:39 by amassias          #+#    #+#             */
/*   Updated: 2024/05/11 17:59:10 by Antoine Mas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file string.c
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

#define NULL_STRING "(null)"

/* ************************************************************************** */
/*                                                                            */
/* Header implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

int	printer__string(
		int fd,
		va_list list,
		t_format *fmt)
{
	char	*str;

	str = va_arg(list, char *);
	if (str)
		return (string_printer_fd(fd, fmt, str));
	if (!fmt__use_precision(fmt)
		|| (unsigned long) fmt->precision + 1 >= sizeof(NULL_STRING))
		return (string_printer_fd(fd, fmt, (char *) NULL_STRING));
	return (string_printer_fd(fd, fmt, (char *) ""));
}
