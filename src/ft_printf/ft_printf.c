/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antoine Massias <massias.antoine.pro@gm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:35:23 by amassias          #+#    #+#             */
/*   Updated: 2024/05/11 18:04:36 by Antoine Mas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_printf.c
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @copyright Copyright (c) 2023
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

#include <stdarg.h>

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

int	ft_vprintf(
		const char *fmt,
		va_list	args)
{
	return (ft_vdprintf(STDOUT_FILENO, fmt, args));
}

int	ft_dprintf(
		int fd,
		const char *fmt,
		...)
{
	va_list	args;
	int		len;

	va_start(args, fmt);
	len = ft_vdprintf(fd, fmt, args);
	va_end(args);
	return (len);
}

int	ft_printf(
		const char *fmt,
		...)
{
	va_list	args;
	int		len;

	va_start(args, fmt);
	len = ft_vdprintf(STDOUT_FILENO, fmt, args);
	va_end(args);
	return (len);
}
