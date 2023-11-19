/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:55:28 by amassias          #+#    #+#             */
/*   Updated: 2023/11/19 19:50:49 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file integer_printer.c
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-18
 * @copyright Copyright (c) 2023
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

/* ************************************************************************** */
/*                                                                            */
/* Helper prototypes                                                          */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * @param base 
 * @param n 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-18
 * @todo Make documentation.
 */
static int	_len(
				t_number_base *base,
				long long n);

/**
 * @brief 
 * @param fd 
 * @param base 
 * @param n 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-18
 * @todo Make documentation.
 */
static void	_print_integer_fd(
				int fd,
				t_number_base *base,
				unsigned long long n);

/**
 * @brief 
 * @param fd 
 * @param fmt 
 * @param base 
 * @param n 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-18
 * @todo Make documentation.
 */
static void	_print_fd(
				int fd,
				t_format *fmt,
				t_number_base *base,
				long long n);

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

int	integer_printer_fd(
		int fd,
		t_format *fmt,
		t_number_base *base,
		long long n)
{
	int	number_size;
	int	prefix_size;

	number_size = _len(base, n);
	if (fmt__use_precision(fmt) && fmt->precision == 0 && n == 0)
		number_size = 0;
	fmt->precision -= _len(base, n);
	if (base->has_sign
		&& (n < 0 || fmt__align_sign(fmt) || fmt__force_sign(fmt)))
		++number_size;
	if (n == 0)
		fmt->flags &= ~FMT_FLAG__PREFIX;
	prefix_size = 0;
	if (fmt__prefix(fmt))
		prefix_size = base->prefix.size;
	fmt->width -= prefix_size;
	if (fmt__zero_padding(fmt)
		&& !fmt__left_justify(fmt)
		&& !fmt__use_precision(fmt))
		fmt->precision = fmt->width - number_size;
	fmt->width = ft_max(0,
			fmt->width - number_size - ft_max(0, fmt->precision));
	_print_fd(fd, fmt, base, n);
	return (prefix_size + number_size + fmt->width + ft_max(0, fmt->precision));
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

static int	_len(
				t_number_base *base,
				long long _n)
{
	unsigned long long	n;
	int					len;

	len = 1;
	if (_n < 0 && base->has_sign)
		_n = ~_n + 1;
	n = _n;
	while (n >= base->base.size)
	{
		++len;
		n /= base->base.size;
	}
	return (len);
}

static void	_print_integer_fd(
				int fd,
				t_number_base *base,
				unsigned long long n)
{
	if (n >= base->base.size)
		_print_integer_fd(fd, base, n / base->base.size);
	ft_putchar_fd(base->base.str[n % base->base.size], fd);
}

static void	_print_fd(
				int fd,
				t_format *fmt,
				t_number_base *base,
				long long n)
{
	if (!fmt__left_justify(fmt))
		putnchar_fd(fd, ' ', fmt->width);
	if (n < 0 && base->has_sign)
		write(fd, "-", 1);
	else if (fmt__force_sign(fmt) && base->has_sign)
		write(fd, "+", 1);
	else if (fmt__align_sign(fmt) && base->has_sign)
		write(fd, " ", 1);
	if (fmt__prefix(fmt)
		&& (!fmt__use_precision(fmt) || fmt->precision >= 0 || n != 0))
		ft_putstr_fd(base->prefix.str, fd);
	if (fmt->precision > 0)
		putnchar_fd(fd, '0', fmt->precision);
	if (!fmt__use_precision(fmt) || fmt->precision >= 0 || n != 0)
	{
		if (n < 0 && base->has_sign)
			n = ~n + 1;
		_print_integer_fd(fd, base, (unsigned long long) n);
	}
	if (fmt__left_justify(fmt))
		putnchar_fd(fd, ' ', fmt->width);
}
