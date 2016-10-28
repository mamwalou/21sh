# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/17 17:09:35 by sbeline           #+#    #+#              #
#    Updated: 2016/10/28 14:27:18 by sbeline          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

SRC_NAME = main.c \
			exec_cmd.c \
			my_setenv.c \
			my_env.c \
			lexer_data.c \
			data.c \
			parsing_line.c \
			ft_cd.c \
			ft_echo.c \
			ft_variables.c \
			termcaps_checker.c \
			termcaps.c \
			manage_error.c \
			my_unsetenv.c \
			memory.c \
			search.c \
			auto_compl.c \
			option_parser.c \
			move_cursr.c \
			export_var.c \
			parser.c

INC_PATH = ./includes/
SRC_PATH = ./srcs/*/
OBJ_PATH = ./obj/
LIB_PATH = ./libft/
LIB_NAME = libft.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))
INC = $(addprefix -I,$(INC_PATH))

all:$(NAME)

$(NAME): $(OBJ) libf
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(INC) -lncurses -o $@

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) -c $< -o $@

libf:
	make -C $(LIB_PATH)

clean:
	make -C $(LIB_PATH) fclean
	rm -rf $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
