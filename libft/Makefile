NAME = libft.a

MY_SOURCES = ft_isalnum.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_putchar_fd.c \
			ft_strchr.c \
			ft_strlcpy.c \
			ft_strrchr.c \
			ft_isalpha.c \
			ft_memcmp.c \
			ft_putendl_fd.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_strtrim.c \
			ft_atoi.c \
			ft_isascii.c \
			ft_memcpy.c \
			ft_putnbr_fd.c \
			ft_striteri.c \
			ft_strmapi.c \
			ft_substr.c \
			ft_bzero.c \
			ft_isdigit.c \
			ft_memmove.c \
			ft_putstr_fd.c \
			ft_strjoin.c \
			ft_strncmp.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_isprint.c \
			ft_memset.c \
			ft_split.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_toupper.c \
			ft_lstadd_back.c \
			ft_lstlast.c \
			ft_lstclear.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstsize.c \
			ft_lstadd_front.c \
			ft_lstmap.c \
			ft_lstiter.c \
			ft_printf.c \
			ft_putnbr_base.c \
			get_next_line_bonus.c 

MY_OBJS = $(MY_SOURCES:.c=.o)
CFLAGS += -Wall -Werror -Wextra
CC = gcc

all: $(NAME)
$(NAME): $(MY_OBJS)
	$(CC) $(CFLAGS) -c $(MY_SOURCES)
	ar -rcs $(NAME) $(MY_OBJS)
clean: $(MY_OBJS)
	rm -f $(MY_OBJS)
fclean:  clean
	rm -f $(NAME)
re: fclean all
