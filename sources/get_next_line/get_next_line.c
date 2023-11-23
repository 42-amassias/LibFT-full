/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:41:25 by amassias          #+#    #+#             */
/*   Updated: 2023/11/23 02:13:56 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line.c
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2023-11-22
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
/* Defines                                                                    */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Number of file descriptor that `get_next_line` can handle.
 */
#define FD_LIMIT 1024

/* ************************************************************************** */
/*                                                                            */
/* Helper prototypes                                                          */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * @param buffer 
 * @param static_buffer 
 * @param n 
 * @param line_length 
 * @return char* 
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2023-11-22
 * @todo Make documentation.
 */
static char	*_make_line(
				char *buffer,
				char *static_buffer,
				size_t n,
				size_t line_length);

/**
 * @brief 
 * @param fd 
 * @param line_length 
 * @param last_buffer 
 * @param static_buffer 
 * @return char* 
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2023-11-22
 * @todo Make documentation.
 */
static char	*_recursivly_read_fd(
				int fd,
				size_t line_length,
				char *last_buffer,
				char *static_buffer);

/**
 * @brief 
 * @param fd 
 * @param buffer 
 * @return char* 
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2023-11-22
 * @todo Make documentation.
 */
static char	*_get_next_line(
				int fd,
				char **buffer);

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(
			int fd)
{
	static char	*buffers[FD_LIMIT] = {NULL};
	char		*line;

	if (fd < 0 || fd >= FD_LIMIT)
		return (NULL);
	line = _get_next_line(fd, &buffers[fd]);
	if (line == NULL)
		buffers[fd] = NULL;
	if (line != NULL && ft_strlen(line) == 0)
	{
		free(buffers[fd]);
		buffers[fd] = NULL;
		return (free(line), NULL);
	}
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

static char	*_make_line(
				char *buffer,
				char *static_buffer,
				size_t n,
				size_t line_length)
{
	char	*line;
	char	*sep;
	size_t	buffer_copy_size;

	sep = ft_strchr(buffer, '\n');
	if (sep == NULL)
		sep = ft_strchr(buffer, '\0') - 1;
	++sep;
	buffer_copy_size = sep - buffer;
	line = (char *) malloc(line_length + buffer_copy_size + 1);
	if (line == NULL)
		return (free(buffer), NULL);
	line[line_length + buffer_copy_size] = '\0';
	ft_memcpy(line + line_length, buffer, buffer_copy_size);
	line[buffer_copy_size] = '\0';
	ft_strcpy(static_buffer, sep);
	return (line);
}

static char	*_recursivly_read_fd(
				int fd,
				size_t line_length,
				char *last_buffer,
				char *static_buffer)
{
	ssize_t	n;
	char	*buffer;
	char	*line;

	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	n = read(fd, buffer, BUFFER_SIZE);
	if (n < 0)
		return (free(buffer), NULL);
	if (n != 0)
		buffer[n] = '\0';
	if (n == 0)
		return (free(buffer),
			_make_line(last_buffer, static_buffer, n, line_length));
	if (ft_strchr(buffer, '\n'))
	{
		line = _make_line(buffer, static_buffer, n, line_length);
		return (free(buffer), line);
	}
	line = _recursivly_read_fd(fd, line_length + n, buffer, static_buffer);
	if (line == NULL)
		return (free(buffer), NULL);
	ft_memcpy(&line[line_length], buffer, (size_t) n);
	return (free(buffer), line);
}

static char	*_get_next_line(
				int fd,
				char **buffer_ptr)
{
	char	*line;
	char	*buffer_head;

	if (*buffer_ptr == NULL)
	{
		*buffer_ptr = (char *) malloc(BUFFER_SIZE + 1);
		if (*buffer_ptr == NULL)
			return (NULL);
		(*buffer_ptr)[0] = '\0';
	}
	buffer_head = prime_buffer(buffer_ptr);
	if (buffer_head == NULL)
		return (full_free(buffer_ptr), NULL);
	if (ft_strchr(buffer_head, '\n'))
		return (buffer_head);
	line = _recursivly_read_fd(fd, ft_strlen(buffer_head), *buffer_ptr,
			*buffer_ptr);
	if (line == NULL)
		return (full_free(buffer_ptr), free(buffer_head), NULL);
	ft_memcpy(line, buffer_head, ft_strlen(buffer_head));
	return (free(buffer_head), line);
}
