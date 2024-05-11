/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antoine Massias <massias.antoine.pro@gm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:57:57 by amassias          #+#    #+#             */
/*   Updated: 2023/11/22 20:33:41 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strcpy.c
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-22
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

char	*ft_strcpy(
			char *dst,
			const char *src)
{
	char	*dst_cpy;

	dst_cpy = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (dst_cpy);
}
