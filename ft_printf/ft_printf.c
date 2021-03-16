/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 13:26:11 by mdaan         #+#    #+#                 */
/*   Updated: 2021/01/08 13:26:43 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_variable(t_info *info, va_list args)
{
	if (info->specifier == 'c' || info->specifier == '%')
		print_char(info, args);
	else if (info->specifier == 's')
		print_string(info, args);
	else if (info->specifier == 'd' || info->specifier == 'i')
		print_int(info, args);
	else if (info->specifier == 'u')
		print_unsig_int(info, args);
	else if (info->specifier == 'x' || info->specifier == 'X')
		print_hexa(info, args);
	else if (info->specifier == 'p')
		print_pointer(info, args);
}

int			ft_printf(const char *s, ...)
{
	t_info	info;
	va_list	args;

	va_start(args, (char *)s);
	info.print_count = 0;
	while (s && *s)
	{
		print_basic_string(&info, (char *)s);
		if (!(ft_strchr(s, '%')))
			break ;
		s = ft_parse_input((char *)s, &info, args);
		print_variable(&info, args);
	}
	va_end(args);
	return (info.print_count);
}
