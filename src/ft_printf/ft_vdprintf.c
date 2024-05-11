/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antoine Massias <massias.antoine.pro@gm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:09:45 by amassias          #+#    #+#             */
/*   Updated: 2024/05/11 18:01:31 by Antoine Mas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_vprintf.c
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-11
 * @copyright Copyright (c) 2023
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

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
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see ft_fprintf
*/
typedef int	(*t_type_printer)(int, va_list, t_format *);

/* ************************************************************************** */
/*                                                                            */
/* Helper prototypes                                                          */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief If `**str_ptr` is '*', it will pull an integer from the variadic list.
 * <br>Else, it acts as `ft_atoi` except it does not recognize minus signs and
 * does not skip white spaces, stores its result into `*value_ptr` and sets
 * `*str_ptr` to the character following the number that has been read.
 * @param str_ptr A pointer to the string from which to pull a number.
 * @param args A pointer to a variadic list from which to pull a number if
 * needed.
 * @param value_ptr A pointer to where to store the number read from `*str_ptr`.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see ft_atoi
 */
static void	_read_number(
				const char **str_ptr,
				va_list args,
				int *value_ptr);

/**
 * @brief Read and convert a text format (i.e. "0#*.2x") into a `s_format`.
 * It will also advance `*fmt_ptr` to the character after the specifier or, if
 * an error occured during the parsing of the format, to where it failed.<br>
 * This function will fail if it does not find a specifier or if the specifier
 * is not recognized.
 * @param fmt A pointer to a format to fill.
 * @param fmt_ptr A pointer to the string containing the format to parse.
 * @param args A variadic list from which to pull `width` and `precision` fields
 * if needed.
 * @return 0 on success, any other value if an error occured.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see ft_fprintf
 */
static int	_read_format(
				t_format *fmt,
				const char **fmt_ptr,
				va_list args);

/**
 * @brief Read a format, advances `*fmt_ptr` right after the read format then
 * formats data from a variadic list.
 * @param fd The file descriptor on which to put the formated data.
 * @param fmt_ptr A pointer to a format string.
 * @param list A pointer to a variadic list from wich to pull data to format.
 * @param printers A list of functions to format each specifiers.
 * @return The number of characters put onto the file descriptor `fd`.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see ft_fprintf
 */
static int	_format(
				int fd,
				const char **fmt_ptr,
				va_list list,
				t_type_printer *printers);

/**
 * @brief Builds a list of functions for each specifier.
 * @param printers The list to build.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
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

int	ft_vdprintf(
		int fd,
		const char *fmt,
		va_list args)
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
				va_list args,
				int *value_ptr)
{
	int	x;

	if (**str == '*')
	{
		++*str;
		*value_ptr = va_arg(args, int);
		return ;
	}
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
				const char **fmt_ptr,
				va_list args)
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
	_read_number(fmt_ptr, args, &fmt->width);
	if (**fmt_ptr && **fmt_ptr == '.')
	{
		++(*fmt_ptr);
		_read_number(fmt_ptr, args, &fmt->precision);
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
				va_list list,
				t_type_printer *printers)
{
	t_format		format;
	t_type_printer	printer;
	int				len;
	const char		*start;

	if (_read_format(&format, fmt_ptr, list))
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
	printers[ft_strchr(SPECIFIERS, 'c') - SPECIFIERS] = printer__char;
	printers[ft_strchr(SPECIFIERS, 's') - SPECIFIERS] = printer__string;
	printers[ft_strchr(SPECIFIERS, 'p') - SPECIFIERS] = printer__pointer;
	printers[ft_strchr(SPECIFIERS, 'd') - SPECIFIERS] = printer__decimal;
	printers[ft_strchr(SPECIFIERS, 'i') - SPECIFIERS] = printer__integer;
	printers[ft_strchr(SPECIFIERS, 'u') - SPECIFIERS] = printer__unsigned;
	printers[ft_strchr(SPECIFIERS, 'x') - SPECIFIERS] = printer__lo_hex;
	printers[ft_strchr(SPECIFIERS, 'X') - SPECIFIERS] = printer__up_hex;
}
