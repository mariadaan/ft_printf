# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mdaan <mdaan@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/30 22:25:48 by mdaan         #+#    #+#                  #
#    Updated: 2021/01/12 16:47:53 by mdaan         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	ft_printf.c			\
				ft_printf_utils.c	\
				ft_print_padding.c	\
				ft_parse_string.c	\
				ft_print_char.c		\
				ft_print_string.c	\
				ft_print_int.c		\
				ft_print_hex.c

LIBFT		=	libft
LIBFT_LIB	=	libft.a
S_PATH		=	ft_printf/
OBJS		=	$(SRCS:%.c=$(S_PATH)%.o)
RM			=	rm -f
LIBC		=	ar -rcs
FLAGS		=	-Wall -Wextra -Werror
INCS		=	.
COMPILER	=	gcc

.c.o:
	${COMPILER} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME): ${OBJS}
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	${LIBC} $(NAME) $(OBJS)

all: $(NAME)

fclean: clean
	$(RM) $(NAME) $(bonus)
	make fclean -C $(LIBFT)

clean:
	$(RM) -f $(OBJS) $(OBJS_B)
	make clean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re .c.o bonus
