/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 06:36:08 by amassias          #+#    #+#             */
/*   Updated: 2023/11/13 16:07:54 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file hex.c
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
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

/**
 * @brief 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
#define U_CHARSET "0123456789ABCDEF0X"

/**
 * @brief 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
#define L_CHARSET "0123456789abcdef0x"

/* ************************************************************************** */
/*                                                                            */
/* Helper prototypes                                                          */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * @param n 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
static int	_len(
				size_t n);

/**
 * @brief 
 * @param charset 
 * @param n 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
static void	_print_hex_fd(
				int fd,
				const char *charset,
				size_t n);

/**
 * @brief 
 * @param fd
 * @param fmt 
 * @param n 
 * @param u 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
static void	_print_fd(
				int fd,
				t_format *fmt,
				size_t n,
				int u);

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

int	hex_printer_fd(
		int fd,
		t_format *fmt,
		size_t n,
		int u)
{
	int	number_size;
	int	prefix;

	if (fmt__use_precision(fmt) && fmt->precision == 0 && n == 0)
		number_size = 0;
	else
		number_size = _len(n);
	fmt->precision -= number_size;
	if (n == 0)
		fmt->flags &= ~FMT_FLAG__HEX_PREFIX;
	prefix = 2 * fmt__hex_prefix(fmt);
	if (prefix)
		fmt->width -= 2;
	if (fmt__zero_padding(fmt)
		&& !fmt__left_justify(fmt)
		&& !fmt__use_precision(fmt))
		fmt->precision = fmt->width - number_size;
	fmt->precision = max(0, fmt->precision);
	fmt->width = max(0, fmt->width - number_size - fmt->precision);
	_print_fd(fd, fmt, n, u);
	return (prefix + number_size + fmt->width + fmt->precision);
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

static int	_len(
				size_t n)
{
	int	len;

	len = 1;
	while (n > 0xf)
	{
		++len;
		n >>= 4;
	}
	return (len);
}

static void	_print_hex_fd(
				int fd,
				const char *charset,
				size_t n)
{
	if (n > 0xf)
		_print_hex_fd(fd, charset, n >> 4);
	ft_putchar_fd(charset[n & 0xf], fd);
}

static void	_print_fd(
				int fd,
				t_format *fmt,
				size_t n,
				int u)
{
	char	*charset;

	charset = L_CHARSET;
	if (u)
		charset = U_CHARSET;
	if (!fmt__left_justify(fmt))
		putnchar_fd(fd, ' ', fmt->width);
	if (fmt__hex_prefix(fmt)
		&& (!fmt__use_precision(fmt) || fmt->precision >= 0 || n))
		ft_putstr_fd(&charset[sizeof(L_CHARSET) - 3], 1);
	putnchar_fd(fd, '0', fmt->precision);
	if (!fmt__use_precision(fmt) || fmt->precision != 0 || n != 0)
		_print_hex(charset, n);
	if (fmt__left_justify(fmt))
		putnchar_fd(fd, ' ', fmt->width);
}
