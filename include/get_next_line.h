/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antoine Massias <massias.antoine.pro@gm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 03:15:53 by amassias          #+#    #+#             */
/*   Updated: 2024/05/11 17:35:13 by Antoine Mas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line.h
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @copyright Copyright (c) 2023
 */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-22
 * @todo Make documentation.
 */
char	*prime_buffer(
			char **buffer_ptr);

/**
 * @brief Frees `*buffer_ptr` then sets it to `NULL`.
 * @param buffer_ptr A pointer to a memory area that has been allocated
 * (man 3 malloc)
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-23
 */
void	full_free(
			void **buffer_ptr);

#endif