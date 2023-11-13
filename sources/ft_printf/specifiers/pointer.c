/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 05:25:18 by amassias          #+#    #+#             */
/*   Updated: 2023/11/13 18:12:41 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	printer__pointer(
		int fd,
		va_list *args,
		t_format *fmt)
{
	void	*ptr;
	size_t	n;

	ptr = va_arg(*args, void *);
	n = *(long *)&ptr;
	if (!n)
		return (string_printer_fd(fd, fmt, "(nil)"));
	fmt->flags |= FMT_FLAG__HEX_PREFIX;
	return (hex_printer_fd(fd, fmt, n));
}
