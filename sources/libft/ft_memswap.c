/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:55:02 by amassias          #+#    #+#             */
/*   Updated: 2023/11/12 14:50:47 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memswap.c
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
 * @brief Swaps one byte of `a` and `b`.
 * @param a A memory area.
 * @param b A memory area.
 * @author Antoine Massias (amsssias@student.42lehavre.fr)
 * @date 2023-11-06
 */
static void	swap(
				unsigned char *a,
				unsigned char *b);

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

void	ft_memswap(
			void *_a,
			void *_b,
			size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = _a;
	b = _b;
	while (n--)
		swap(a++, b++);
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

static void	swap(
				unsigned char *a,
				unsigned char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
