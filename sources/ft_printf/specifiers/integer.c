/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _integer_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:33:38 by amassias          #+#    #+#             */
/*   Updated: 2023/10/20 04:25:59 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	_integer_printer(va_list *list, t_format *fmt)
{
	int	n;

	n = va_arg(*list, int);
	return (number_printer(fmt, (long) n));
}
