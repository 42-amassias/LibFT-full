/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antoine Massias <massias.antoine.pro@gm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:29:11 by amassias          #+#    #+#             */
/*   Updated: 2023/11/22 16:23:10 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atoi.c
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
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

int	ft_atoi(
	const char *str)
{
	int		value;
	int		sign;

	value = 0;
	sign = 1;
	while (ft_isspace(*str))
		++str;
	if (*str == '-')
	{
		++str;
		sign = -sign;
	}
	else if (*str == '+')
		++str;
	while (ft_isdigit(*str))
		value = 10 * value + (*str++) - '0';
	return (sign * value);
}
