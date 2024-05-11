/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antoine Massias <massias.antoine.pro@gm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 03:22:28 by amassias          #+#    #+#             */
/*   Updated: 2023/11/06 11:24:39 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstmap.c
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

t_list	*ft_lstmap(
			t_list *list,
			void *(*f)(void *),
			void (*del_fun)(void *))
{
	t_list	*res;
	t_list	*node;

	res = NULL;
	while (list)
	{
		node = ft_lstnew(NULL);
		if (!node)
		{
			ft_lstclear(&res, del_fun);
			break ;
		}
		node->content = f(list->content);
		ft_lstadd_back(&res, node);
		list = list->next;
	}
	return (res);
}
