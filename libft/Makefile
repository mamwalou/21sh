# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/14 14:10:26 by sbeline           #+#    #+#              #
#    Updated: 2016/10/17 17:11:40 by sbeline          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c
SRC += ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c
SRC += ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c
SRC += ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c
SRC += ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c
SRC += ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c
SRC += ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c
SRC += ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c
SRC += ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c
SRC += ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c
SRC += ft_strjoin.c  ft_strlen.c ft_strmap.c
SRC += ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c
SRC += ft_strnew.c ft_strnstr.c ft_strrchr.c
SRC += ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c
SRC += ft_tolower.c ft_toupper.c ft_list_search.c
SRC += ft_strconct.c ft_strnb.c ft_putstr_rev.c
SRC += ft_nbsize.c ft_lenghtwchar.c ft_lenghtstrwchar.c
SRC += ft_printunint.c ft_lenghtunint.c ft_isdir.c
SRC += get_next_line.c ft_stradd.c ft_strmove.c
SRC +=  ft_strtrijoin.c ft_strndup.c ft_findstr.c ft_chrstr.c

DEL = rm -f

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $(OBJ)
	@ranlib $(NAME)
	@echo
	@echo "make -> $@ created"
	@echo

%.o: %.c
	@gcc -o $@ -c $< -I.Includes/

clean:
	@$(DEL) $(OBJ)
	@echo
	@echo "clean -> .o deleted"
	@echo

fclean: clean
	@$(DEL) $(NAME)
	@echo
	@echo "fclean -> ... and $(NAME) deleted"
	@echo

re: fclean all
	@echo
	@echo "re -> $(NAME) reloaded"
	@echo

.PHONY: all clean fclean re
