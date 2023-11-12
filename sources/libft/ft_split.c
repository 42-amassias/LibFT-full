/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 05:37:05 by amassias          #+#    #+#             */
/*   Updated: 2023/11/12 15:32:21 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_split.c
 * @author amassias (amassias@student.42lehavre.fr)
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
/* Helper prototypes                                                          */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Counts how many tokens separated by `c` are in `str`.
 * @param str A string.
 * @param c The separator.
 * @return how many tokens separated by `c` are in `str`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
static size_t		count_strings(
						const char *str,
						char c);

/**
 * @brief Duplicates the next sub string in `src` in which there is not the
 * character `c`, puts it in `*dst` then returns a pointer to the character
 * following this substring in `str`.<br>If an error occured, `*dst` is set to
 * `NULL` and the function will return `NULL`.
 * @param dst A pointer to a string. `*dst` must not contain a pointer to an
 * allocated memory area, otherwise it will be lost.
 * @param src The string in from which the substring will be duplicated.
 * @param c The separator.
 * @return A pointer to the charater following the substring within `str` or
 * `NULL` if an error occured.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @note If `*dst` is not `NULL`, it will have to be freed (man 3 free).
 */
static const char	*dup_until_c(
						char **dst,
						const char *src,
						char c);

/**
 * @brief Frees `len` string from `*strs` then frees `*strs` then sets `*strs`
 * to `NULL`.
 * @param strs A pointer to a list of strings.
 * @param len The number of strings to free within `*strs`
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
static void			free_strs(
						char ***strs,
						size_t len);

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

char	**ft_split(
			const char *s,
			char c)
{
	char	**strs;
	size_t	string_count;
	size_t	i;

	string_count = count_strings(s, c);
	strs = (char **) malloc(sizeof(char *) * (string_count + 1));
	if (strs)
	{
		strs[string_count] = NULL;
		i = 0;
		while (i < string_count)
		{
			s = dup_until_c(strs + i++, s, c);
			if (!s)
				return (free_strs(&strs, i - 1), NULL);
		}
	}
	return (strs);
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

static size_t	count_strings(
					const char *str,
					char c)
{
	size_t	string_count;

	string_count = 0;
	while (*str)
	{
		if (*str == c)
		{
			++str;
			continue ;
		}
		while (*str && *str != c)
			str++;
		string_count++;
	}
	return (string_count);
}

static const char	*dup_until_c(
						char **dst,
						const char *src,
						char c)
{
	size_t	len;

	while (*src == c)
		src++;
	len = 0;
	while (src[len] && src[len] != c)
		len++;
	*dst = (char *) malloc(sizeof(char) * (len + 1));
	if (*dst == NULL)
		return (NULL);
	ft_memcpy(*dst, src, len);
	(*dst)[len] = '\0';
	src += len + 1;
	return (src);
}

static void	free_strs(
				char ***strs,
				size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		free((*strs)[i++]);
	free(*strs);
	*strs = NULL;
}
