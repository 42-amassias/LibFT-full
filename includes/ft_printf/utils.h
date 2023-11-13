/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:16:23 by amassias          #+#    #+#             */
/*   Updated: 2023/11/13 17:02:39 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file utils.h
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @copyright Copyright (c) 2023
 */

#ifndef UTILS_H
# define UTILS_H

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

# include <stdarg.h>

/* ************************************************************************** */
/*                                                                            */
/* Defines                                                                    */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Bitflag that indicates if the formatter should use the `left justify`
 * (`-`) flag.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see s_format
 * @see ft_fprintf
 */
# define FMT_FLAG__LEFT_JUSTIFY 0b000001

/**
 * @brief Bitflag that indicates if the formatter should use the `force sign`
 * (`+`) flag.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see s_format
 * @see ft_fprintf
 */
# define FMT_FLAG__FORCE_SIGN 0b000010

/**
 * @brief Bitflag that indicates if the formatter should use the `align sign`
 * (`[space]`) flag.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see s_format
 * @see ft_fprintf
 */
# define FMT_FLAG__ALIGN_SIGN 0b000100

/**
 * @brief Bitflag that indicates if the formatter should use the `hex prefix`
 * (`#`) flag.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see s_format
 * @see ft_fprintf
 */
# define FMT_FLAG__HEX_PREFIX 0b001000

/**
 * @brief Bitflag that indicates if the formatter should use the `zero padding`
 * (`0`) flag.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see s_format
 * @see ft_fprintf
 */
# define FMT_FLAG__ZERO_PADDING 0b010000

/**
 * @brief Bitflag that indicates if the formatter should use the `precision`
 * field.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see s_format
 * @see ft_fprintf
 */
# define FMT_FLAG__USE_PRECISION 0b100000

/* ************************************************************************** */
/*                                                                            */
/* Structures                                                                 */
/*                                                                            */
/* ************************************************************************** */

/**
 * @struct s_format
 * @brief This structure represents a format. It will help the formatter to
 * contruct the correct string.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 */
struct s_format {
	/**
	 * @brief The `width` field.
	 * @see ft_fprintf
	 */
	int		width;

	/**
	 * @brief The `.precision` field.
	 * @see ft_fprintf
	 */
	int		precision;

	/**
	 * @brief A bitflag that represents what flags have been set and if the
	 * `.precision` field has been set.
	 * @see ft_fprintf
	 */
	char	flags;

	/**
	 * @brief The `specifier` field.
	 * @see ft_fprtinf
	 */
	char	specifier;
};

/* ************************************************************************** */
/*                                                                            */
/* Types                                                                      */
/*                                                                            */
/* ************************************************************************** */

/**
 * @typedef t_format
 * @see s_format
 */
typedef struct s_format	t_format;

/* ************************************************************************** */
/*                                                                            */
/* Utilities                                                                  */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Repeats `count` times the same character `c` on the file descriptor
 * `fd`.
 * @param fd The file descriptor on which to put `count` repetitions of `c`.
 * @param c The chatacter to repeat `count` times.
 * @param count The number of time to repeat `c`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	putnchar_fd(
			int fd,
			char c,
			int count);

/**
 * @brief Returns the greatest of `a` and `b`.
 * @param a An integer.
 * @param b An integer.
 * @return The greatest of `a` and `b`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		max(
			int a,
			int b);

/**
 * @brief Returns the lowest of `a` and `b`.
 * @param a An integer.
 * @param b An integer.
 * @return The lowest of `a` and `b`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		min(
			int a,
			int b);

/**
 * @brief Acts exactly as `ft_fprintf` except the argument list is passed as a
 * variadic list dirrectly.
 * @param fd The file descriptor on which to output the resulting formated
 * string.
 * @param fmt The format to use.
 * @param args A variadic list of arguments to format.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-11
 * @see ft_fprintf
 */
int		ft_vprintf(
			int fd,
			const char *fmt,
			va_list *args);

/* ************************************************************************** */
/*                                                                            */
/* Format flags                                                               */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Tells if `left justify` flag is set for the formatter.
 * @param fmt A format.
 * @return 0 if the flag is not set, any other value otherwise.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		fmt__left_justify(
			t_format *fmt);

/**
 * @brief Tells if `force sign` flag is set for the formatter.
 * @param fmt A format.
 * @return 0 if the flag is not set, any other value otherwise.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		fmt__force_sign(
			t_format *fmt);

/**
 * @brief Tells if `align sign` flag is set for the formatter.
 * @param fmt A format.
 * @return 0 if the flag is not set, any other value otherwise.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		fmt__align_sign(
			t_format *fmt);

/**
 * @brief Tells if `hex prefix` flag is set for the formatter.
 * @param fmt A format.
 * @return 0 if the flag is not set, any other value otherwise.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		fmt__hex_prefix(
			t_format *fmt);

/**
 * @brief Tells if `zero padding` flag is set for the formatter.
 * @param fmt A format.
 * @return 0 if the flag is not set, any other value otherwise.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		fmt__zero_padding(
			t_format *fmt);

/**
 * @brief Tells if `use precision` flag is set for the formatter.
 * @param fmt A format.
 * @return 0 if the flag is not set, any other value otherwise.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		fmt__use_precision(
			t_format *fmt);

/* ************************************************************************** */
/*                                                                            */
/* Type printers                                                              */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Using the specified format `fmt`, puts a formatted hexadecimal number
 * `n` to the file descriptor `fd`.
 * @param fd The file descriptor on which to put the formatted hexadecimal
 * number `n`.
 * @param fmt The format to use.
 * @param n The hexadecimal number to format.
 * @param u Flag to indicate if the hexadecimal letters should be uppercase or
 * lowercase.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 * @todo Get rid of the `u` variable as it can be determined from the format.
 */
int		hex_printer_fd(
			int fd,
			t_format *fmt,
			size_t n,
			int u);

/**
 * @brief Using the specified format, puts a formatted string `str` to the file
 * descriptor `fd`.
 * @param fd The file descriptor on which to put the formatted string.
 * @param fmt The format to use.
 * @param str The string to format.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 */
int		string_printer_fd(
			int fd,
			t_format *fmt,
			char *str);

/**
 * @brief Using the specified format, puts a formatted decimal number `n` to the
 * file descriptor `fd`.
 * @param fd The file descriptor on which to put the formatted decimal number.
 * @param fmt The format to use.
 * @param n The decimal number to format.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 */
int		number_printer_fd(
			int fd,
			t_format *fmt,
			long n);

/* ************************************************************************** */
/*                                                                            */
/* Specifier printers                                                         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Formatter for the `c` specifier.
 * @param fd The file descriptor on which to put the formatted character.
 * @param list The variadic list from which to pull the character to be
 * formatted.
 * @param fmt The format to use.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 */
int		_char_printer(
			int fd,
			va_list *list,
			t_format *fmt);

/**
 * @brief Formatter for the `s` specifier.
 * @param fd The file descriptor on which to put the formatted string.
 * @param list The variadic list from which to pull the string to be formatted.
 * @param fmt The format to use.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 */
int		_string_printer(
			int fd,
			va_list *list,
			t_format *fmt);

/**
 * @brief Formatter for the `p` specifier.
 * @param fd A file descriptor on which to put the formatted pointer address.
 * @param list The variadic list from which to pull the pointer address to be
 * formatted.
 * @param fmt The format to use.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 */
int		_pointer_printer(
			int fd,
			va_list *list,
			t_format *fmt);

/**
 * @brief Formatter for the `d` specifier.
 * @param fd A file descriptor on which to put the formatted decimal number.
 * @param list The variadic list from which to pull the decimal number to be
 * formatted.
 * @param fmt The format to use.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 */
int		_decimal_printer(
			int fd,
			va_list *list,
			t_format *fmt);

/**
 * @brief Formatter for the `i` specifier.
 * @param fd A file descriptor on which to put the formatted integer.
 * @param list The variadic list from which to pull the integer to be formatted.
 * @param fmt The format to use.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 */
int		_integer_printer(
			int fd,
			va_list *list,
			t_format *fmt);

/**
 * @brief Formatter for the `u` specifier.
 * @param fd A file descriptor on which to put the formatted unsigned number.
 * @param list The variadic list from which to pull the unsigned number to be
 * formatted.
 * @param fmt The format to use.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 */
int		_unsigned_printer(
			int fd,
			va_list *list,
			t_format *fmt);

/**
 * @brief Formatter for the `x` specifier.
 * @param fd A file descriptor on which to put the formatted lowercase
 * hexadecimal number.
 * @param list The variadic list from which to pull the lowercase hexadecimal
 * number to be formatted.
 * @param fmt The format to use.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 */
int		_lo_hex_printer(
			int fd,
			va_list *list,
			t_format *fmt);

/**
 * @brief Formatter for the `X` specifier.
 * @param fd A file descriptor on which to put the formatted uppercase
 * hexadecimal number.
 * @param list The variadic list from which to pull the uppercase hexadecimal
 * number to be formatted.
 * @param fmt The format to use.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 */
int		_up_hex_printer(
			int fd,
			va_list *list,
			t_format *fmt);

#endif