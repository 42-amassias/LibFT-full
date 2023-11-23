/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:15:53 by amassias          #+#    #+#             */
/*   Updated: 2023/11/23 03:15:54 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line_utils.h
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @copyright Copyright (c) 2023
 */

#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

/* ************************************************************************** */
/*                                                                            */
/* Defines                                                                    */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

/* ************************************************************************** */
/*                                                                            */
/* Utils                                                                      */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * @param buffer_ptr 
 * @return char* 
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2023-11-22
 * @todo Make documentation.
 */
char	*prime_buffer(
			char **buffer_ptr);

/**
 * @brief Frees `*buffer_ptr` then sets it to `NULL`.
 * @param buffer_ptr A pointer to a memory area that has been allocated
 * (man 3 malloc)
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2023-11-23
 */
void	full_free(
			void **buffer_ptr);

#endif