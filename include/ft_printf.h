/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:16:23 by amassias          #+#    #+#             */
/*   Updated: 2024/11/25 18:23:32 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_printf.h
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @copyright Copyright (c) 2023
 */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>

/* ************************************************************************** */
/*                                                                            */
/* Defines                                                                    */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Bitflag that indicates if the formatter should use the `left justify`
 * (`-`) flag.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see s_format
 * @see ft_fprintf
 */
# define FMT_FLAG__LEFT_JUSTIFY 0b000001

/**
 * @brief Bitflag that indicates if the formatter should use the `force sign`
 * (`+`) flag.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see s_format
 * @see ft_fprintf
 */
# define FMT_FLAG__FORCE_SIGN 0b000010

/**
 * @brief Bitflag that indicates if the formatter should use the `align sign`
 * (`[space]`) flag.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see s_format
 * @see ft_fprintf
 */
# define FMT_FLAG__ALIGN_SIGN 0b000100

/**
 * @brief Bitflag that indicates if the formatter should use the `prefix` (`#`)
 * flag.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see s_format
 * @see ft_fprintf
 */
# define FMT_FLAG__PREFIX 0b001000

/**
 * @brief Bitflag that indicates if the formatter should use the `zero padding`
 * (`0`) flag.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see s_format
 * @see ft_fprintf
 */
# define FMT_FLAG__ZERO_PADDING 0b010000

/**
 * @brief Bitflag that indicates if the formatter should use the `precision`
 * field.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
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
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see ft_fprintf
 */
struct s_format
{
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

/**
 * @struct s_number_base
 * @brief This structure represents a base.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-16
 */
struct s_number_base
{
	struct s_base
	{
		/**
		 * @brief The number of digits in this base.
		 */
		int				size;
		/**
		 * @brief The digits of this base.
		 */
		const char		*str;
	}	base;
	struct s_prefix
	{
		/**
		 * @brief The numbers of characters in the prefix.
		 */
		int			size;
		/**
		 * @brief The prefix.
		 */
		const char	*str;
	}	prefix;
	int	has_sign;
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
typedef struct s_format			t_format;

/**
 * @typedef t_number_base
 * @see s_number_base
 */
typedef struct s_number_base	t_number_base;

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
typedef int						(*t_type_printer)(int, va_list, t_format *);

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
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 */
void	putnchar_fd(
			int fd,
			char c,
			int count);

/* ************************************************************************** */
/*                                                                            */
/* Format flags                                                               */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Tells if `left justify` flag is set for the formatter.
 * @param fmt A format.
 * @return 0 if the flag is not set, any other value otherwise.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 */
int		fmt__left_justify(
			t_format *fmt);

/**
 * @brief Tells if `force sign` flag is set for the formatter.
 * @param fmt A format.
 * @return 0 if the flag is not set, any other value otherwise.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 */
int		fmt__force_sign(
			t_format *fmt);

/**
 * @brief Tells if `align sign` flag is set for the formatter.
 * @param fmt A format.
 * @return 0 if the flag is not set, any other value otherwise.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 */
int		fmt__align_sign(
			t_format *fmt);

/**
 * @brief Tells if `hex prefix` flag is set for the formatter.
 * @param fmt A format.
 * @return 0 if the flag is not set, any other value otherwise.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 */
int		fmt__prefix(
			t_format *fmt);

/**
 * @brief Tells if `zero padding` flag is set for the formatter.
 * @param fmt A format.
 * @return 0 if the flag is not set, any other value otherwise.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 */
int		fmt__zero_padding(
			t_format *fmt);

/**
 * @brief Tells if `use precision` flag is set for the formatter.
 * @param fmt A format.
 * @return 0 if the flag is not set, any other value otherwise.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
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
 * @brief Using the specified format, puts a formatted string `str` to the file
 * descriptor `fd`.
 * @param fd The file descriptor on which to put the formatted string.
 * @param fmt The format to use.
 * @param str The string to format.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see ft_fprintf
 * @see s_format
 */
int		string_printer_fd(
			int fd,
			t_format *fmt,
			char *str);

/**
 * @brief Using the specified format `fmt` and base `base`, puts a formatted
 * integer `n` to the file descriptor `fd`.
 * @param fd The file descriptor on which to put the formatted integer.
 * @param fmt The format to use.
 * @param base The base to use.
 * @param n The decimal number to format.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see ft_fprintf
 * @see s_format
 * @see s_number_base
 */
int		integer_printer_fd(
			int fd,
			t_format *fmt,
			t_number_base *base,
			long long n);

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
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see ft_fprintf
 */
int		printer__char(
			int fd,
			va_list list,
			t_format *fmt);

/**
 * @brief Formatter for the `s` specifier.
 * @param fd The file descriptor on which to put the formatted string.
 * @param list The variadic list from which to pull the string to be formatted.
 * @param fmt The format to use.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see ft_fprintf
 */
int		printer__string(
			int fd,
			va_list list,
			t_format *fmt);

/**
 * @brief Formatter for the `p` specifier.
 * @param fd A file descriptor on which to put the formatted pointer address.
 * @param list The variadic list from which to pull the pointer address to be
 * formatted.
 * @param fmt The format to use.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see ft_fprintf
 */
int		printer__pointer(
			int fd,
			va_list list,
			t_format *fmt);

/**
 * @brief Formatter for the `d` specifier.
 * @param fd A file descriptor on which to put the formatted decimal number.
 * @param list The variadic list from which to pull the decimal number to be
 * formatted.
 * @param fmt The format to use.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see ft_fprintf
 */
int		printer__decimal(
			int fd,
			va_list list,
			t_format *fmt);

/**
 * @brief Formatter for the `i` specifier.
 * @param fd A file descriptor on which to put the formatted integer.
 * @param list The variadic list from which to pull the integer to be formatted.
 * @param fmt The format to use.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see ft_fprintf
 */
int		printer__integer(
			int fd,
			va_list list,
			t_format *fmt);

/**
 * @brief Formatter for the `u` specifier.
 * @param fd A file descriptor on which to put the formatted unsigned number.
 * @param list The variadic list from which to pull the unsigned number to be
 * formatted.
 * @param fmt The format to use.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see ft_fprintf
 */
int		printer__unsigned(
			int fd,
			va_list list,
			t_format *fmt);

/**
 * @brief Formatter for the `x` specifier.
 * @param fd A file descriptor on which to put the formatted lowercase
 * hexadecimal number.
 * @param list The variadic list from which to pull the lowercase hexadecimal
 * number to be formatted.
 * @param fmt The format to use.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see ft_fprintf
 */
int		printer__lo_hex(
			int fd,
			va_list list,
			t_format *fmt);

/**
 * @brief Formatter for the `X` specifier.
 * @param fd A file descriptor on which to put the formatted uppercase
 * hexadecimal number.
 * @param list The variadic list from which to pull the uppercase hexadecimal
 * number to be formatted.
 * @param fmt The format to use.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @see ft_fprintf
 */
int		printer__up_hex(
			int fd,
			va_list list,
			t_format *fmt);

#endif