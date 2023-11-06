/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _pointer_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 05:25:18 by amassias          #+#    #+#             */
/*   Updated: 2023/10/20 04:26:28 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	_pointer_printer(va_list *args, t_format *fmt)
{
	void	*ptr;
	size_t	n;

	ptr = va_arg(*args, void *);
	n = *(long *)&ptr;
	if (!n)
		return (string_printer(fmt, "(nil)"));
	fmt->flags |= FMT_FLAG__HEX_PREFIX;
	return (hex_printer(fmt, n, 0));
}
