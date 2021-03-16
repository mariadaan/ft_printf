/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_padding.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 13:30:56 by mdaan         #+#    #+#                 */
/*   Updated: 2021/01/08 13:57:58 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_padding(t_info *info, char c, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(c, 1);
		info->print_count++;
		i++;
	}
}

void		left_padding(t_info *info, int len)
{
	if (info->flag != '-')
		put_padding(info, info->padding, info->width - len);
}

void		right_padding(t_info *info, int len)
{
	if (info->flag == '-')
		put_padding(info, info->padding, info->width - len);
}
