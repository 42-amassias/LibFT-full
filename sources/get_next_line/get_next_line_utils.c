/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 02:00:07 by amassias          #+#    #+#             */
/*   Updated: 2023/11/23 02:06:17 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line_utils.c
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-23
 * @copyright Copyright (c) 2023
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "get_next_line_utils.h"

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

char	*prime_buffer(
			char **buffer_ptr)
{
	char	*end;
	char	*line;

	end = ft_strchr(*buffer_ptr, '\n');
	if (end == NULL)
		end = ft_strchr(*buffer_ptr, '\0') - 1;
	++end;
	line = (char *) malloc(end - *buffer_ptr + 1);
	if (line == NULL)
	{
		free(*buffer_ptr);
		*buffer_ptr = NULL;
		return (NULL);
	}
	ft_memcpy(line, *buffer_ptr, end - *buffer_ptr);
	line[end - *buffer_ptr] = '\0';
	ft_strcpy(*buffer_ptr, end);
	return (line);
}

void	full_free(
			void	**buffer_ptr)
{
	free(*buffer_ptr);
	*buffer_ptr = NULL;
}
