/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 13:28:20 by mdaan         #+#    #+#                 */
/*   Updated: 2021/01/12 14:52:03 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_hexa(t_info *info, va_list args)
{
	unsigned	hex;
	int			len;
	int			len_exprec;

	hex = va_arg(args, unsigned);
	if (check_zero(info, (unsigned)hex))
		return ;
	len = ft_get_hex_len(hex);
	len_exprec = len;
	if (info->precbool == 1 && info->precision >= 0)
		info->padding = ' ';
	if (info->precision > len)
		len = info->precision;
	left_padding(info, len);
	put_padding(info, '0', info->precision - len_exprec);
	if (info->specifier == 'x')
		ft_put_hex_nbr(info, hex, "0123456789abcdef");
	else if (info->specifier == 'X')
		ft_put_hex_nbr(info, hex, "0123456789ABCDEF");
	right_padding(info, len);
}

void		print_pointer(t_info *info, va_list args)
{
	long	ptr;
	int		len;

	ptr = (unsigned long long)va_arg(args, void *);
	len = ft_get_hex_len(ptr) + 2;
	if (info->precbool && info->precision == 0 && !ptr)
		len = 2;
	else if (!(info->precbool) && !ptr)
		len = 3;
	else
		info->precbool = 0;
	left_padding(info, len);
	print_basic_string(info, "0x");
	if (ptr || (!ptr && info->precbool == 0))
		ft_put_hex_nbr(info, ptr, "0123456789abcdef");
	right_padding(info, len);
}
