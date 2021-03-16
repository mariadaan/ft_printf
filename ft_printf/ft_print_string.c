/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 13:31:06 by mdaan         #+#    #+#                 */
/*   Updated: 2021/01/08 13:58:44 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putstr_len(char *s, int len)
{
	if (s)
		write(1, s, len);
}

void		print_string(t_info *info, va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (info->width < 0)
	{
		info->width = ft_abs(info->width);
		info->flag = '-';
	}
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (info->precision > len || info->precision < 0)
		info->precbool = 0;
	if (info->precbool && info->precision < len)
		len = info->precision;
	left_padding(info, len);
	ft_putstr_len(str, len);
	info->print_count += len;
	right_padding(info, len);
}
