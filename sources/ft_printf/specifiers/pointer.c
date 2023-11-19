/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 05:25:18 by amassias          #+#    #+#             */
/*   Updated: 2023/11/19 17:30:38 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#define BASE "0123456789abcdef"
#define PREFIX "0x"

int	printer__pointer(
		int fd,
		va_list *args,
		t_format *fmt)
{
	static t_number_base	_base = (t_number_base){
	{.size = sizeof(BASE) - 1, .str = BASE},
	{.size = sizeof(PREFIX) - 1, .str = PREFIX},
		0,
	};
	long long				n;

	n = (long long) va_arg(*args, void *);
	if (n == 0)
		return (string_printer_fd(fd, fmt, "(nil)"));
	fmt->flags |= FMT_FLAG__PREFIX;
	return (integer_printer_fd(fd, fmt, &_base, n));
}
