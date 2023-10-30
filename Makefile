# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afarheen <afarheen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 09:59:04 by afarheen          #+#    #+#              #
#    Updated: 2023/02/07 18:34:00 by afarheen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

MY_SOURCES = libft/ft_lstnew.c \
			libft/ft_striteri.c \
			libft/ft_atoi.c \
			libft/ft_lstsize.c \
			libft/ft_strjoin.c \
			libft/ft_bzero.c \
			libft/ft_memchr.c \
			libft/ft_strlcat.c \
			libft/ft_calloc.c \
			libft/ft_memcmp.c \
			libft/ft_strlcpy.c \
			libft/ft_isalnum.c \
			libft/ft_memcpy.c \
			libft/ft_strlen.c \
			libft/ft_isalpha.c \
			libft/ft_memmove.c \
			libft/ft_strmapi.c \
			libft/ft_isascii.c \
			libft/ft_memset.c \
			libft/ft_strncmp.c \
			libft/ft_isdigit.c \
			libft/ft_printf.c \
			libft/ft_strnstr.c \
			libft/ft_isprint.c \
			libft/ft_strrchr.c \
			libft/ft_itoa.c \
			libft/ft_putchar_fd.c \
			libft/ft_strtrim.c \
			libft/ft_lstadd_back.c \
			libft/ft_putendl_fd.c \
			libft/ft_substr.c \
			libft/ft_lstadd_front.c \
			libft/ft_putnbr_base.c \
			libft/ft_tolower.c \
			libft/ft_lstclear.c \
			libft/ft_putnbr_fd.c \
			libft/ft_toupper.c \
			libft/ft_lstdelone.c \
			libft/ft_putstr_fd.c \
			libft/ft_lstiter.c \
			libft/ft_split.c \
			libft/get_next_line_bonus.c \
			libft/ft_lstlast.c \
			libft/ft_strchr.c \
			libft/ft_lstmap.c \
			libft/ft_strdup.c \
			libft/ft_strcmp.c \
			pipex.c \
			utils.c \
			error_handling.c \
			parsing.c \
			main.c

MY_OBJS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

CC = gcc

all: $(NAME)

$(NAME): $(MY_OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(MY_SOURCES) -o $(NAME)

clean:
	rm -f $(MY_OBJS)

fclean: clean
	rm -f $(NAME) libft/libft.a
	rm -rf pipex.dSYM

re: fclean all
