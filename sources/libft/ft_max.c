/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:57:11 by amassias          #+#    #+#             */
/*   Updated: 2023/11/18 15:57:25 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_max.c
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-18
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

int	ft_maxmin(
		int a,
		int b)
{
	if (a > b)
		return (a);
	return (b);
}