/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 03:58:39 by amassias          #+#    #+#             */
/*   Updated: 2023/11/11 19:53:07 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#define NULL_STRING "(null)"

int	_string_printer(
		int fd,
		va_list *list,
		t_format *fmt)
{
	char	*str;

	str = va_arg(*list, char *);
	if (str)
		return (string_printer_fd(fd, fmt, str));
	if (!fmt__precision(fmt)
		|| (unsigned long) fmt->precision + 1 >= sizeof(NULL_STRING))
		return (string_printer_fd(fd, fmt, (char *) NULL_STRING));
	return (string_printer_fd(fd, fmt, (char *) ""));
}
