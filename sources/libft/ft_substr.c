/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:21:28 by amassias          #+#    #+#             */
/*   Updated: 2023/11/06 11:32:55 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_substr.c
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

char	*ft_substr(
			char const *s,
			unsigned int start,
			size_t len)
{
	char	*copy;
	size_t	tmp;

	tmp = ft_strlen(s);
	if (start >= tmp)
		return (ft_strdup(""));
	tmp -= start;
	if (tmp < len)
		len = tmp;
	copy = (char *) malloc(len + 1);
	if (copy)
	{
		ft_memcpy(copy, s + start, len);
		copy[len] = '\0';
	}
	return (copy);
}
