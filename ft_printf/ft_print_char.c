/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_char.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 13:28:06 by mdaan         #+#    #+#                 */
/*   Updated: 2021/01/08 13:28:08 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_char(t_info *info, va_list args)
{
	char c;

	if (info->specifier == '%')
		c = '%';
	else
		c = va_arg(args, int);
	left_padding(info, 1);
	ft_putchar_fd(c, 1);
	info->print_count++;
	right_padding(info, 1);
}
