/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:05:41 by amassias          #+#    #+#             */
/*   Updated: 2023/11/06 11:27:23 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putnbr_fd.c
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @copyright Copyright (c) 2023
 * @note This function is part of the original libft.
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                                                            */
/* Helper prototypes                                                          */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Outputs the unsigned integer n to the given file descriptor.
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
static void	_ft_putnbr_fd(
				unsigned int n,
				int fd);

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr_fd(signed int _n, int fd)
{
	long	n;

	n = _n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	_ft_putnbr_fd(n, fd);
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

static void	_ft_putnbr_fd(
				unsigned int n,
				int fd)
{
	if (n > 9)
		_ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
}
