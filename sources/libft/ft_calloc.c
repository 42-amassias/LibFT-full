/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:01:26 by amassias          #+#    #+#             */
/*   Updated: 2023/11/06 11:20:32 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_calloc.c
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
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

void	*ft_calloc(
			size_t nmemb,
			size_t size)
{
	void	*ptr;
	size_t	sz;

	sz = nmemb * size;
	if (nmemb == 0)
		return (malloc(0));
	if ((size_t)(-1 / nmemb) < size)
		return (NULL);
	ptr = malloc(sz);
	if (ptr)
		ft_bzero(ptr, sz);
	return (ptr);
}
