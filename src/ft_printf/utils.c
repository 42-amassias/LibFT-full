/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antoine Massias <massias.antoine.pro@gm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 07:48:43 by amassias          #+#    #+#             */
/*   Updated: 2024/05/11 17:46:44 by Antoine Mas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file utils.c
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

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

void	putnchar_fd(
			int fd,
			char c,
			int count)
{
	while (count--)
		ft_putchar_fd(c, fd);
}