/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 03:58:39 by amassias          #+#    #+#             */
/*   Updated: 2023/10/23 01:40:35 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#define NULL_STRING "(null)"

int	_string_printer(va_list *list, t_format *fmt)
{
	char	*str;

	str = va_arg(*list, char *);
	if (str)
		return (string_printer(fmt, str));
	if (!fmt__precision(fmt)
		|| (unsigned long) fmt->precision + 1 >= sizeof(NULL_STRING))
		return (string_printer(fmt, (char *) NULL_STRING));
	return (string_printer(fmt, (char *) ""));
}
