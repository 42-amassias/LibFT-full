/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 02:55:50 by amassias          #+#    #+#             */
/*   Updated: 2023/11/13 18:12:23 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file char.c
 * @author Antoine Massias (amassias@student.42lehavre.fr)
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
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

int	printer__char(
		int fd,
		va_list *list,
		t_format *fmt)
{
	int	len;

	if (fmt->width <= 0)
		fmt->width = 1;
	len = fmt->width--;
	if (fmt__left_justify(fmt))
		ft_putchar_fd(va_arg(*list, int), fd);
	while (fmt->width--)
		ft_putchar_fd(' ', fd);
	if (!fmt__left_justify(fmt))
		ft_putchar_fd(va_arg(*list, int), fd);
	return (len);
}
