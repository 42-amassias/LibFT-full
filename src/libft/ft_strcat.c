/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antoine Massias <massias.antoine.pro@gm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 04:50:16 by amassias          #+#    #+#             */
/*   Updated: 2023/11/29 04:58:56 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strcat.c
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-29
 * @copyright Copyright (c) 2023
 * @note This function is not part of the original libft.
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

char	*ft_strcat(
			const char *first,
			const char *second)
{
	size_t	length__first;
	size_t	length__second;
	char	*res;

	length__first = ft_strlen(first);
	length__second = ft_strlen(second);
	res = (char *) malloc(length__first + length__second + 1);
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, first, length__first);
	ft_memcpy(res + length__first, second, length__second);
	res[length__first + length__second] = '\0';
	return (res);
}
