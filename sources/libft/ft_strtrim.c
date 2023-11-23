/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:14:55 by amassias          #+#    #+#             */
/*   Updated: 2023/11/06 11:32:46 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strtrim.c
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

char	*ft_strtrim(
			char const *str,
			char const *set)
{
	char	*trimmed;
	size_t	len;

	while (*str && ft_strchr(set, *str))
		++str;
	len = ft_strlen(str);
	while (*str && ft_strchr(set, str[len - 1]))
		--len;
	trimmed = malloc(len + 1);
	if (trimmed)
	{
		ft_memcpy(trimmed, str, len);
		trimmed[len] = '\0';
	}
	return (trimmed);
}
