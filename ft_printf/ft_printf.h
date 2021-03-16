/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdaan <mdaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 13:26:23 by mdaan         #+#    #+#                 */
/*   Updated: 2021/01/12 17:14:22 by mdaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_info {
	char	flag;
	int		width;
	int		precbool;
	int		precision;
	char	specifier;
	char	padding;
	int		print_count;
}					t_info;

int					ft_printf(const char *s, ...);

void				print_variable(t_info *info, va_list args);

int					ft_inset(char c, const char *set);

int					ft_count_numbers(char *s);

void				ft_put_unsig_nbr(t_info *info, unsigned int n);

char				*ft_parse_input(char *s, t_info *info, va_list args);

void				print_basic_string(t_info *info, char *s);

void				print_char(t_info *info, va_list args);

void				print_string(t_info *info, va_list args);

void				print_int(t_info *info, va_list args);

void				print_pos_int(t_info *info, unsigned int dec, int len);

void				print_unsig_int(t_info *info, va_list args);

int					ft_put_hex_nbr(t_info *info, unsigned long long nbr,
					char *basestr);

void				print_hexa(t_info *info, va_list args);

void				print_pointer(t_info *info, va_list args);

void				print_width(t_info *info, int len);

void				put_padding(t_info *info, char c, int len);

void				left_padding(t_info *info, int len);

void				right_padding(t_info *info, int len);

int					check_zero(t_info *info, unsigned int num);

char				*print_space(t_info *info, char *s);

#endif
