/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 13:54:42 by mdaan         #+#    #+#                 */
/*   Updated: 2021/01/12 15:35:47 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_basic_string(t_info *info, char *s)
{
	while (*s != '\0' && *s != '%')
	{
		ft_putchar_fd(*s, 1);
		info->print_count++;
		s++;
	}
}

void		ft_put_unsig_nbr(t_info *info, unsigned int n)
{
	char c;

	if (n > 9)
		ft_put_unsig_nbr(info, n / 10);
	c = ((n % 10) + '0');
	info->print_count++;
	ft_putchar_fd(c, 1);
}

int			ft_put_hex_nbr(t_info *info, unsigned long long nbr, char *basestr)
{
	unsigned long long	exp;
	int					len;
	int					base;

	base = 16;
	exp = 1;
	len = 1;
	while (nbr / base / exp)
	{
		exp *= base;
		len++;
	}
	while (exp)
	{
		ft_putchar_fd(basestr[nbr / exp % base], 1);
		info->print_count++;
		exp /= base;
	}
	return (len);
}

char		*print_space(t_info *info, char *s)
{
	info->print_count++;
	ft_putchar_fd(' ', 1);
	while (*s == ' ')
		s++;
	return (s);
}

int			check_zero(t_info *info, unsigned int num)
{
	if (num == 0 && info->precbool && info->precision == 0)
	{
		put_padding(info, ' ', info->width);
		return (1);
	}
	else if (num == 0 && info->precbool && info->precision < 0)
	{
		left_padding(info, 1);
		ft_putchar_fd('0', 1);
		info->print_count++;
		right_padding(info, 1);
		return (1);
	}
	return (0);
}
