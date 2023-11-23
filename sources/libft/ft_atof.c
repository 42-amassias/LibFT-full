/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:16:29 by amassias          #+#    #+#             */
/*   Updated: 2023/11/22 16:26:09 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atof.c
 * @author Antoine Massias (amassias@student.42lehavre.fr)
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

double	ft_atof(
			const char *str)
{
	double	integer;
	double	fract;
	int		sign;

	integer = 0;
	fract = 0;
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
		integer = 10 * integer + (*str++) - '0';
	if (*str++ == '.')
		while (ft_isdigit(*str))
			fract = fract / 10. + (*str++) - '0';
	return (sign * (integer + fract / 10.));
}
