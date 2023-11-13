/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 06:55:10 by amassias          #+#    #+#             */
/*   Updated: 2023/11/13 17:20:02 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	_up_hex_printer(
		int fd,
		va_list *args,
		t_format *fmt)
{
	unsigned int	x;

	x = va_arg(*args, unsigned int);
	fmt->flags &= ~(FMT_FLAG__ALIGN_SIGN | FMT_FLAG__FORCE_SIGN);
	return (hex_printer_fd(fd, fmt, (size_t) x));
}
