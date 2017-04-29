# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/17 17:09:35 by sbeline           #+#    #+#              #
#    Updated: 2017/04/29 13:36:48 by sbeline          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

SRC_NAME = main.c tools.c lexer.c lexer_pt2.c option_parser.c stock_line.c
SRC_NAME += parser.c token.c lexem.c lexem_pt2.c tool_lexem.c tools_env.c
SRC_NAME += tools_lexer.c
SRC_NAME += manage_history.c termcaps_checker.c mode_termcaps.c
SRC_NAME += termcaps.c parsing_line.c line_and_array.c signal.c push_line.c
SRC_NAME += depush_line.c history_termcaps.c
SRC_NAME += tools_for_mode.c move_cursr.c
SRC_NAME += ast.c an_ll.c node_tool.c fd_file.c
SRC_NAME += exec_tree.c pipe_function.c pipe_function2.c
SRC_NAME += redirection.c cmd_gestion.c log_sep.c tools_builltin2.c
SRC_NAME += echo.c setenv.c cd.c env.c tools_builltin.c history.c
SRC_NAME += print_proto.c env_fct.c

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
