/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:09:45 by amassias          #+#    #+#             */
/*   Updated: 2023/11/13 17:21:38 by amassias         ###   ########.fr       */
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
 * @brief Function callback type that formats a specifier.
 * @param fd The file descriptor on which to put the formatted data.
 * @param va_list A variadic list from which to pull data.
 * @param fmt The format to use to format the data.
 * @return The number of characters put onto the file descriptor `fd`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
*/
typedef int	(*t_type_printer)(int, va_list *, t_format *);

/* ************************************************************************** */
/*                                                                            */
/* Helper prototypes                                                          */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Acts as `ft_atoi` except it does not recognize minus signs and does
 * not skip white spaces, stores its result into `*value_ptr` and sets
 * `*str_ptr` to the character following the number that has been read.
 * @param str_ptr A pointer to the string from which to pull a number.
 * @param value_ptr A pointer to where to store the number read from `*str_ptr`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_atoi
 */
static void	_read_number(
				const char **str_ptr,
				int *value_ptr);

/**
 * @brief Read and convert a text format (i.e. "0#12.2x") into a `s_format`.
 * It will also advance `*fmt_ptr` to the character after the specifier or, if
 * an error occured during the parsing of the format, to where it failed.<br>
 * This function will fail if it does not find a specifier or if the specifier
 * is not recognized.
 * @param fmt A pointer to a format to fill.
 * @param fmt_ptr A pointer to the string containing the format to parse.
 * @return 0 on success, any other value if an error occured.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 */
static int	_read_format(
				t_format *fmt,
				const char **fmt_ptr);

/**
 * @brief Read a format, advances `*fmt_ptr` right after the read format then
 * formats data from a variadic list.
 * @param fd The file descriptor on which to put the formated data.
 * @param fmt_ptr A pointer to a format string.
 * @param list A pointer to a variadic list from wich to pull data to format.
 * @param printers A list of functions to format each specifiers.
 * @return The number of characters put onto the file descriptor `fd`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 */
static int	_format(
				int fd,
				const char **fmt_ptr,
				va_list *list,
				t_type_printer *printers);

/**
 * @brief Builds a list of functions for each specifier.
 * @param printers The list to build.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 */
static void	_init_printers(
				t_type_printer *printers);

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

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
		length += _format(fd, &fmt, args, printers);
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
		fmt->flags |= FMT_FLAG__USE_PRECISION;
	}
	x = ft_strchr(SPECIFIERS, **fmt_ptr);
	if (!*(*fmt_ptr)++ || !x)
		return (1);
	fmt->specifier = *x;
	return (0);
}

static int	_format(
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
