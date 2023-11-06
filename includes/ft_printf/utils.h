/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:16:23 by amassias          #+#    #+#             */
/*   Updated: 2023/11/06 13:10:00 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
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
 * @brief 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
# define FMT_FLAG__LEFT_JUSTIFY 0b000001

/**
 * @brief 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
# define FMT_FLAG__FORCE_SIGN 0b000010

/**
 * @brief 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
# define FMT_FLAG__ALIGN_SIGN 0b000100

/**
 * @brief 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
# define FMT_FLAG__HEX_PREFIX 0b001000

/**
 * @brief 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
# define FMT_FLAG__ZERO_PADDING 0b010000

/**
 * @brief 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
# define FMT_FLAG__PRECISION 0b100000

/* ************************************************************************** */
/*                                                                            */
/* Structures                                                                 */
/*                                                                            */
/* ************************************************************************** */

/**
 * @struct s_format
 * @brief 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
struct s_format {
	int		width;
	int		precision;
	char	flags;
	char	specifier;
};

/* ************************************************************************** */
/*                                                                            */
/* Types                                                                      */
/*                                                                            */
/* ************************************************************************** */

/**
 * @typedef t_format
 * @brief 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
typedef struct s_format	t_format;

/* ************************************************************************** */
/*                                                                            */
/* Utilities                                                                  */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * @param c 
 * @param count 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
void	putnchar(char c, int count);

/**
 * @brief 
 * @param a 
 * @param b 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		max(int a, int b);

/**
 * @brief 
 * @param a 
 * @param b 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		min(int a, int b);

/* ************************************************************************** */
/*                                                                            */
/* Format flags                                                               */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * @param fmt 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		fmt__left_justify(t_format *fmt);

/**
 * @brief 
 * @param fmt 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		fmt__force_sign(t_format *fmt);

/**
 * @brief 
 * @param fmt 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		fmt__align_sign(t_format *fmt);

/**
 * @brief 
 * @param fmt 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		fmt__hex_prefix(t_format *fmt);

/**
 * @brief 
 * @param fmt 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		fmt__zero_padding(t_format *fmt);

/**
 * @brief 
 * @param fmt 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		fmt__precision(t_format *fmt);

/* ************************************************************************** */
/*                                                                            */
/* Type printers                                                              */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * @param fmt 
 * @param n 
 * @param u 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		hex_printer(t_format *fmt, size_t n, int u);

/**
 * @brief 
 * @param fmt 
 * @param str 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		string_printer(t_format *fmt, char *str);

/**
 * @brief 
 * @param fmt 
 * @param n 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		number_printer(t_format *fmt, long n);

/* ************************************************************************** */
/*                                                                            */
/* Specifier printers                                                         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * @param list 
 * @param fmt 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		_char_printer(va_list *list, t_format *fmt);

/**
 * @brief 
 * @param list 
 * @param fmt 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		_string_printer(va_list *list, t_format *fmt);

/**
 * @brief 
 * @param list 
 * @param fmt 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		_pointer_printer(va_list *list, t_format *fmt);

/**
 * @brief 
 * @param list 
 * @param fmt 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		_decimal_printer(va_list *list, t_format *fmt);

/**
 * @brief 
 * @param list 
 * @param fmt 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		_integer_printer(va_list *list, t_format *fmt);

/**
 * @brief 
 * @param list 
 * @param fmt 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		_unsigned_printer(va_list *list, t_format *fmt);

/**
 * @brief 
 * @param list 
 * @param fmt 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		_lo_hex_printer(va_list *list, t_format *fmt);

/**
 * @brief 
 * @param list 
 * @param fmt 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		_up_hex_printer(va_list *list, t_format *fmt);

#endif