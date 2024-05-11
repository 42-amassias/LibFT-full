/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antoine Massias <massias.antoine.pro@gm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 03:05:48 by amassias          #+#    #+#             */
/*   Updated: 2023/11/06 11:24:53 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstsize.c
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @copyright Copyright (c) 2023
 * @note This function is part of the bonus of the original libft.
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

int	ft_lstsize(
		t_list *list)
{
	t_list	**list_ptr;
	int		size;

	list_ptr = &list;
	size = 0;
	while (*list_ptr)
	{
		++size;
		list_ptr = &(*list_ptr)->next;
	}
	return (size);
}
