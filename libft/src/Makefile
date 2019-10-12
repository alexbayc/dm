# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmanfred <cmanfred@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 17:23:57 by htillman          #+#    #+#              #
#    Updated: 2019/07/13 17:31:48 by cmanfred         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_strsplit_alex.c get_next_line.c ./ft_putchar.c ./ft_putstr.c ./ft_strlen.c ./ft_isdigit.c ./ft_isalpha.c ./ft_isascii.c ./ft_isalnum.c ./ft_isprint.c ./ft_toupper.c ./ft_tolower.c ./ft_strdup.c ./ft_strcpy.c ./ft_strncpy.c ./ft_strcmp.c ./ft_strncmp.c ./ft_atoi.c ./ft_strcat.c ./ft_strncat.c ./ft_strlcat.c ./ft_memset.c ./ft_bzero.c ./ft_memcpy.c ./ft_memccpy.c ./ft_memmove.c ./ft_memchr.c ./ft_memcmp.c ./ft_strchr.c ./ft_strrchr.c ./ft_strstr.c ./ft_strnstr.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ./ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ./ft_putendl_fd.c ft_putnbr_fd.c ft_strsplit.c ft_wlen.c ft_nbofwords.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_putstr_error.c ft_lstlen.c ft_strsort_bubble.c ft_return.c ft_free2darr.c ft_lstrev.c ft_swap.c ft_memdup.c ft_set.c ft_free.c
FILESO = $(addprefix ../objectives/, ${SRC:.c=.o})
FLAGS = -Wall -Wextra -Werror
all: $(NAME)
$(NAME): $(FILESO)
	ar rc $(NAME) $(FILESO)
	ranlib $(NAME)
clean:
	rm -rf ../objectives/*.o
fclean: clean
	rm -f $(NAME)
re: fclean
	make

../objectives/%.o: %.c
	gcc $(FLAGS) -o $@ -c $< -I ../include