/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:03:39 by amassias          #+#    #+#             */
/*   Updated: 2023/11/06 11:31:10 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_striteri.c
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
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(
			char *str,
			void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (*str)
		f(i++, str++);
}
