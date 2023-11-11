/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:09:45 by amassias          #+#    #+#             */
/*   Updated: 2023/11/11 19:40:42 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_vprintf.c
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-11
 * @copyright Copyright (c) 2023
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* ************************************************************************** */
/*                                                                            */
/* Defines                                                                    */
/*                                                                            */
/* ************************************************************************** */

#define SPECIFIERS "cspdiuxX%"
#define FLAGS "-+ #0"

/* ************************************************************************** */
/*                                                                            */
/* Types                                                                      */
/*                                                                            */
/* ************************************************************************** */

/**
 * @typedef t_type_printer
 * @param fd
 * @param va_list
 * @param fmt
 * @return
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
*/
typedef int	(*t_type_printer)(int, va_list *, t_format *);

/* ************************************************************************** */
/*                                                                            */
/* Helper prototypes                                                          */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * @param str 
 * @param value_ptr 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
static void	_read_number(
				const char **str,
				int *value_ptr);

/**
 * @brief 
 * @param fmt 
 * @param fmt_ptr 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
static int	_read_format(
				t_format *fmt,
				const char **fmt_ptr);

/**
 * @brief 
 * @param fmt_ptr 
 * @param list 
 * @param printers 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
static int	_handle(
				int fd,
				const char **fmt_ptr,
				va_list *list,
				t_type_printer *printers);

/**
 * @brief 
 * @param printers 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
static void	_init_printers(
				t_type_printer *printers);

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * @param fd 
 * @param fmt 
 * @param ... 
 * @return int 
 * @author amassias (amsssias@student.42lehavre.fr)
 * @date 2023-11-11
 * @todo Make documentation.
 */
int	ft_vprintf(
		int fd,
		const char *fmt,
		va_list *args)
{
	int				length;
	t_type_printer	printers[8];

	length = 0;
	_init_printers(printers);
	while (*fmt)
	{
		if (*fmt++ != '%')
		{
			++length;
			ft_putchar_fd(fmt[-1], fd);
			continue ;
		}
		length += _handle(fd, &fmt, args, printers);
	}
	return (length);
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

static void	_read_number(
				const char **str,
				int *value_ptr)
{
	int	x;

	x = 0;
	while (**str && ft_isdigit(**str))
	{
		x = 10 * x + **str - '0';
		++(*str);
	}
	*value_ptr = x;
}

static int	_read_format(
				t_format *fmt,
				const char **fmt_ptr)
{
	char	*x;

	ft_bzero(fmt, sizeof(t_format));
	while (1)
	{
		x = ft_strchr(FLAGS, *(*fmt_ptr));
		if (!x)
			break ;
		++(*fmt_ptr);
		*((char *)&fmt->flags) |= 1 << (x - FLAGS);
	}
	_read_number(fmt_ptr, &fmt->width);
	if (**fmt_ptr && **fmt_ptr == '.')
	{
		++(*fmt_ptr);
		_read_number(fmt_ptr, &fmt->precision);
		fmt->flags |= FMT_FLAG__PRECISION;
	}
	x = ft_strchr(SPECIFIERS, **fmt_ptr);
	if (!*(*fmt_ptr)++ || !x)
		return (1);
	fmt->specifier = *x;
	return (0);
}

static int	_handle(
				int fd,
				const char **fmt_ptr,
				va_list *list,
				t_type_printer *printers)
{
	t_format		format;
	t_type_printer	printer;
	int				len;
	const char		*start;

	if (_read_format(&format, fmt_ptr))
	{
		start = *fmt_ptr;
		while (*start != '%')
			--start;
		len = *fmt_ptr - start;
		while (start < *fmt_ptr)
			ft_putchar_fd(*start++, fd);
		return (len);
	}
	if (format.specifier == '%')
	{
		ft_putchar_fd('%', fd);
		return (1);
	}
	printer = printers[ft_strchr(SPECIFIERS, format.specifier) - SPECIFIERS];
	return (printer(fd, list, &format));
}

static void	_init_printers(
				t_type_printer *printers)
{
	printers[0] = _char_printer;
	printers[1] = _string_printer;
	printers[2] = _pointer_printer;
	printers[3] = _decimal_printer;
	printers[4] = _integer_printer;
	printers[5] = _unsigned_printer;
	printers[6] = _lo_hex_printer;
	printers[7] = _up_hex_printer;
}
