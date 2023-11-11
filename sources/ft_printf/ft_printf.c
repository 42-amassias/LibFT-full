/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:35:23 by amassias          #+#    #+#             */
/*   Updated: 2023/11/11 19:48:26 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_printf.c
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @copyright Copyright (c) 2023
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

#include <stdarg.h>

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

int	ft_fprintf(
		int fd,
		const char *fmt,
		...)
{
	va_list	args;

	va_start(args, fmt);
	ft_vprintf(fd, fmt, &args);
	va_end(args);
}

int	ft_printf(
		const char *fmt,
		...)
{
	va_list	args;

	va_start(args, fmt);
	ft_vprintf(0, fmt, &args);
	va_end(args);
}
