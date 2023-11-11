/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:33:38 by amassias          #+#    #+#             */
/*   Updated: 2023/11/11 19:17:04 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	_unsigned_printer(
		int fd,
		va_list *list,
		t_format *fmt)
{
	unsigned int	n;

	n = va_arg(*list, unsigned int);
	fmt->flags &= ~(FMT_FLAG__ALIGN_SIGN | FMT_FLAG__FORCE_SIGN);
	return (number_printer_fd(fd, fmt, (long) n));
}
