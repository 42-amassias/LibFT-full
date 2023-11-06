/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:52:05 by amassias          #+#    #+#             */
/*   Updated: 2023/11/06 11:28:15 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_qsort.c
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
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
/* Helper prototypes                                                          */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * @param base 
 * @param nmemb 
 * @param size 
 * @param cmp 
 * @return void* 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
static void	*_partition(
				void *base,
				size_t nmemb,
				size_t size,
				t_comparator cmp);

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

void	ft_qsort(
			void *base,
			size_t nmemb,
			size_t size,
			t_comparator cmp)
{
	void	*pivot;
	size_t	len;

	if (nmemb < 2)
		return ;
	pivot = _partition(base, nmemb, size, cmp);
	len = (char *)pivot - (char *)base;
	len /= size;
	ft_qsort(base, len, size, cmp);
	ft_qsort((char *)pivot + size, nmemb - len - 1, size, cmp);
}

//TODO add separator

static void	*_partition(
				void *base,
				size_t nmemb,
				size_t size,
				t_comparator cmp)
{
	void	*pivot;
	int		r;

	pivot = (char *)base + (nmemb - 1) * size;
	while (pivot > base)
	{
		r = cmp(base, pivot);
		if (r > 0)
		{
			ft_memswap(base, pivot, size);
			pivot -= size;
			ft_memswap(base, pivot, size);
		}
		else
			base += size;
	}
	return (pivot);
}
