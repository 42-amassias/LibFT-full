/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:52:05 by amassias          #+#    #+#             */
/*   Updated: 2023/11/12 14:55:40 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_qsort.c
 * @author Antoine Massias (amassias@student.42lehavre.fr)
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
 * @brief Choses an element (p) in `base` then rearanges `base` such that every
 * element that is greater (according to `cmp`) than (p) is put after (p) and
 * every element that is less than (according to `cmp`) (p) is but before (p).
 * @param base An array.
 * @param nmemb The number of elements in `base`.
 * @param size The size (in bytes) of an element.
 * @param cmp A comparator.
 * @return A pointer within `base` to the pivot (p).
 * @see t_comparator
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
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

/* ************************************************************************** */
/*                                                                            */
/* Helper implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

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
