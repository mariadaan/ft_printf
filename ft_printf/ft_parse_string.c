/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parse_string.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 13:27:10 by mdaan         #+#    #+#                 */
/*   Updated: 2021/01/12 16:35:54 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_struct(t_info *info)
{
	info->flag = 0;
	info->width = 0;
	info->precbool = 0;
	info->precision = 0;
	info->specifier = 0;
}

char	*check_flags(t_info *info, char *s)
{
	while (*s && ft_strchr("-0", *s))
	{
		if (*s == '-')
			info->flag = '-';
		else if (*s == '0' && info->flag != '-')
			info->flag = '0';
		s++;
	}
	return (s);
}

char	*check_width(t_info *info, va_list args, char *s)
{
	if (*s && ft_isdigit(*s))
	{
		info->width = ft_atoi(s);
		s += ft_count_numbers(s);
	}
	if (*s == '*')
	{
		info->width = va_arg(args, int);
		s++;
	}
	if (info->width < 0)
	{
		info->width = ft_abs(info->width);
		info->flag = '-';
		info->padding = ' ';
	}
	return (s);
}

char	*check_prec(t_info *info, va_list args, char *s)
{
	if (*s == '.')
	{
		info->precbool = 1;
		s++;
		if (ft_isdigit(*s))
		{
			info->precision = ft_atoi(s);
			s += ft_count_numbers(s);
		}
		else if (*s == '*')
		{
			info->precision = va_arg(args, int);
			s++;
		}
	}
	return (s);
}

char	*ft_parse_input(char *s, t_info *info, va_list args)
{
	if (!*s || !s)
		return (NULL);
	initialize_struct(info);
	s = ft_strchr(s, '%') + 1;
	if (*s == ' ')
		s = print_space(info, s);
	s = check_flags(info, s);
	s = check_width(info, args, s);
	s = check_prec(info, args, s);
	if (*s && ft_strchr("cspdiuxX%", *s))
	{
		info->specifier = *s;
		s++;
	}
	info->padding = info->flag == '0' ? '0' : ' ';
	return (s);
}
