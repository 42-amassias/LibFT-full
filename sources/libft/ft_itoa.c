/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:26:44 by amassias          #+#    #+#             */
/*   Updated: 2023/11/12 14:49:54 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_itoa.c
 * @author Antoine Massias (amassias@student.42lehavre.fr)
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
 * @brief Writes at most `len` digits of `n` into `out`.
 * @param n The number to write.
 * @param len The size of `buf`.
 * @param buf A buffer in which to write `n`.
 * @author Antoine Massias (amassias@42lehavre.fr)
 * @date 2023-11-06
 */
static void	itoa(
				int n,
				int len,
				char *buf);

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

char	*ft_itoa(
			int n)
{
	long	cpy;
	int		len;
	char	*str;

	cpy = n;
	len = 1;
	if (cpy < 0)
	{
		cpy = -cpy;
		++len;
	}
	while (cpy > 9)
	{
		cpy /= 10;
		++len;
	}
	str = (char *) malloc(len + 1);
	if (str)
		itoa(n, len, str);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementation                                                      */
/*                                                                            */
/* ************************************************************************** */

static void	itoa(
				int _n,
				int len,
				char *buf)
{
	long	n;

	n = _n;
	if (n < 0)
	{
		n = -n;
		*buf++ = '-';
		--len;
	}
	buf[len] = '\0';
	while (len--)
	{
		buf[len] = '0' + n % 10;
		n /= 10;
	}
}
