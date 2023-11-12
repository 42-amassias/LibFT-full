/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:13:08 by amassias          #+#    #+#             */
/*   Updated: 2023/11/12 14:45:32 by amassias         ###   ########.fr       */
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
 * @brief 
 * @param u 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
static int	_len(
				long u);

/**
 * @brief 
 * @param n 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
static void	_print_number_fd(
				int fd,
				unsigned long n);

/**
 * @brief 
 * @param fmt 
 * @param n 
 * @param pn 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
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

	if (fmt__precision(fmt) && fmt->precision == 0 && n == 0)
		number_size = 0;
	else
		number_size = _len(n);
	fmt->precision -= number_size;
	if (n < 0 || fmt__align_sign(fmt) || fmt__force_sign(fmt))
		++number_size;
	if (fmt__zero_padding(fmt)
		&& !fmt__left_justify(fmt)
		&& !fmt__precision(fmt))
		fmt->precision = fmt->width - number_size;
	fmt->precision = max(0, fmt->precision);
	fmt->width = max(0, fmt->width - number_size - fmt->precision);
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
