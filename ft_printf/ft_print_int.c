/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_int.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 13:29:59 by mdaan         #+#    #+#                 */
/*   Updated: 2021/01/12 12:55:23 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				print_unsig_int(t_info *info, va_list args)
{
	int				len;
	unsigned int	dec;

	dec = va_arg(args, unsigned int);
	len = ft_get_unsig_len(dec);
	print_pos_int(info, dec, len);
}

void				print_pos_int(t_info *info, unsigned int dec, int len)
{
	int		len_exprec;

	if (check_zero(info, dec))
		return ;
	len_exprec = len;
	if (info->precbool == 1 && info->precision >= 0)
		info->padding = ' ';
	if (info->precision > len)
		len = info->precision;
	left_padding(info, len);
	put_padding(info, '0', info->precision - len_exprec);
	ft_put_unsig_nbr(info, dec);
	right_padding(info, len);
}

void				print_neg_int(t_info *info, int dec, int len)
{
	unsigned int	num;
	int				len_exprec;

	info->print_count++;
	num = ft_abs(dec);
	len_exprec = len;
	if (info->precbool == 1 && info->precision >= 0)
		info->padding = ' ';
	if (info->precision >= len)
		len = info->precision + 1;
	if ((info->flag == '0' && info->precbool == 0)
		|| (info->flag == '0' && info->precision < 0))
		ft_putchar_fd('-', 1);
	left_padding(info, len);
	if (!(info->flag == '0' && info->precbool == 0)
		&& !(info->flag == '0' && info->precision < 0))
		ft_putchar_fd('-', 1);
	put_padding(info, '0', info->precision - len_exprec + 1);
	ft_put_unsig_nbr(info, num);
	right_padding(info, len);
}

void				print_int(t_info *info, va_list args)
{
	int		dec;
	int		len;

	dec = va_arg(args, int);
	len = ft_get_len(dec);
	if (dec < 0)
		print_neg_int(info, dec, len);
	else
		print_pos_int(info, dec, len);
}
