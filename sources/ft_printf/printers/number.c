/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:13:08 by amassias          #+#    #+#             */
/*   Updated: 2023/11/18 16:24:51 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file number.c
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

#include <stdio.h>

/* ************************************************************************** */
/*                                                                            */
/* Helper prototypes                                                          */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Computes the length in characters of the integer `u`. This does not
 * take into account the sign of `u`.
 * @param u An integer.
 * @return The length in characters of `u`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
static int	_len(
				long u);

/**
 * @brief Puts an unsigned integer `n` onto the file descriptor `fd`.
 * @param n The unsigned integer to print.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
static void	_print_number_fd(
				int fd,
				unsigned long n);

/**
 * @brief Using the specified format `fmt`, puts a formatted integer `n` to the
 * file descriptor `fd`.
 * @param fd The file descriptor on which to put the formatted integer `n`.
 * @param fmt The format to use.
 * @param n The integer to format.
 * @param pn Flag to indicate if the number should be printed or not.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 * @todo Get rid of the parameter `pn`.
 */
static void	_print_fd(
				int fd,
				t_format *fmt,
				long n,
				int pn);

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

int	number_printer_fd(
		int fd,
		t_format *fmt,
		long n)
{
	int	number_size;

	if (fmt__use_precision(fmt) && fmt->precision == 0 && n == 0)
		number_size = 0;
	else
		number_size = _len(n);
	fmt->precision -= number_size;
	if (n < 0 || fmt__align_sign(fmt) || fmt__force_sign(fmt))
		++number_size;
	if (fmt__zero_padding(fmt)
		&& !fmt__left_justify(fmt)
		&& !fmt__use_precision(fmt))
		fmt->precision = fmt->width - number_size;
	fmt->precision = ft_max(0, fmt->precision);
	fmt->width = ft_max(0, fmt->width - number_size - fmt->precision);
	_print_fd(fd, fmt, n, number_size != 0);
	return (number_size + fmt->width + fmt->precision);
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

static int	_len(
				long u)
{
	int	len;

	len = 1;
	if (u < 0)
		u = -u;
	while (u > 9)
	{
		++len;
		u /= 10;
	}
	return (len);
}

static void	_print_number_fd(
				int fd,
				unsigned long n)
{
	if (n > 9)
		_print_number_fd(fd, n / 10);
	ft_putchar_fd('0' + n % 10, fd);
}

static void	_print_fd(
				int fd,
				t_format *fmt,
				long n,
				int pn)
{
	if (!fmt__left_justify(fmt))
		putnchar_fd(fd, ' ', fmt->width);
	if (!fmt__force_sign(fmt) && fmt__align_sign(fmt) && n >= 0)
		ft_putchar_fd(' ', fd);
	if (fmt__force_sign(fmt) && n >= 0)
		ft_putchar_fd('+', fd);
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	putnchar_fd(fd, '0', fmt->precision);
	if (pn)
		_print_number_fd(fd, (unsigned long) n);
	if (fmt__left_justify(fmt))
		putnchar_fd(fd, ' ', fmt->width);
}
