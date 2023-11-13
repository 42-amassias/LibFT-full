/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:15:03 by amassias          #+#    #+#             */
/*   Updated: 2023/11/13 17:12:54 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* ************************************************************************** */
/*                                                                            */
/* Helper prototypes                                                          */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Puts at `len` characters of `str` to the file descriptor `fd`.
 * @param str The string to print.
 * @param len The number of characters to print.
 * @author amassias (amassias@42lehavre.fr)
 * @date 2023-11-06
 * @warning This funciton is very unsafe, it does not check if `str` is smaller
 * than `len` and thus will try to print characters after `str`.
 */
static void	_putnstr_fd(
				int fd,
				const char *str,
				size_t len);

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

int	string_printer_fd(
		int fd,
		t_format *fmt,
		char *str)
{
	size_t	slen;
	size_t	len;

	slen = ft_strlen(str);
	if (fmt__use_precision(fmt))
		slen = min(fmt->precision, slen);
	fmt->width = max(0, fmt->width - slen);
	len = slen + fmt->width;
	if (fmt__left_justify(fmt))
		_putnstr_fd(fd, str, slen);
	putnchar_fd(fd, ' ', fmt->width);
	if (!fmt__left_justify(fmt))
		_putnstr_fd(fd, str, slen);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

static void	_putnstr_fd(
				int fd,
				const char *str,
				size_t len)
{
	while (len--)
		ft_putchar_fd(*str++, fd);
}
