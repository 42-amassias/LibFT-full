/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:35:23 by amassias          #+#    #+#             */
/*   Updated: 2023/11/20 01:29:37 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_printf.c
 * @author Antoine Massias (amassias@student.42lehavre.fr)
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
	int		len;

	va_start(args, fmt);
	len = ft_vprintf(fd, fmt, &args);
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
	len = ft_vprintf(STDOUT_FILENO, fmt, &args);
	va_end(args);
	return (len);
}
