/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:33:38 by amassias          #+#    #+#             */
/*   Updated: 2023/11/11 19:16:26 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	_integer_printer(
		int fd,
		va_list *list,
		t_format *fmt)
{
	int	n;

	n = va_arg(*list, int);
	return (number_printer_fd(fd, fmt, (long) n));
}
