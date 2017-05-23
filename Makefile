#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/14 01:34:45 by mbourget          #+#    #+#              #
#    Updated: 2016/04/27 23:43:53 by mbourget         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = clang
NAME = 21sh

CPPFLAGS = -Iincludes -Ilibft/Includes
CFLAGS =  -g -Wall -Wextra
# -Werror
# -O1 -g -fsanitize=address -fno-omit-frame-pointer
LIBFT = libft.a
LIBFTDIR = libft

LDFLAGS = -L$(LIBFTDIR)
LDLIBS = -lft -ltermcap

SRCDIR = src
SRCS =	srcs/ast/an_ll.c\
		srcs/ast/ast.c\
		srcs/ast/node_tool.c\
		srcs/builltin/cd.c\
		srcs/builltin/echo.c\
		srcs/builltin/env.c\
		srcs/builltin/export.c\
		srcs/builltin/history.c\
		srcs/builltin/setenv.c\
		srcs/builltin/tools_builltin.c\
		srcs/builltin/tools_builltin2.c\
		srcs/exec/access_gestion.c\
		srcs/exec/cmd_gestion.c\
		srcs/exec/exec_tree.c\
		srcs/exec/gestion_redirection.c\
		srcs/exec/log_sep.c\
		srcs/exec/pipe_function.c\
		srcs/exec/pipe_function2.c\
		srcs/exec/redirection.c\
		srcs/exec_it/history_tools.c\
		srcs/exec_it/main.c\
		srcs/exec_it/tools.c\
		srcs/exec_it/tools_env.c\
		srcs/history/manage_history.c\
		srcs/lexer_parser/lexem.c\
		srcs/lexer_parser/lexem_pt2.c\
		srcs/lexer_parser/lexer.c\
		srcs/lexer_parser/lexer_pt2.c\
		srcs/lexer_parser/option_parser.c\
		srcs/lexer_parser/parser.c\
		srcs/lexer_parser/stock_line.c\
		srcs/lexer_parser/token.c\
		srcs/lexer_parser/tool_lexem.c\
		srcs/lexer_parser/tools_lexer.c\
		srcs/termcaps/autocompletion.c\
		srcs/termcaps/autocompletion2.c\
		srcs/termcaps/depush_line.c\
		srcs/termcaps/end_home.c\
		srcs/termcaps/history_termcaps.c\
		srcs/termcaps/loop_read.c\
		srcs/termcaps/mode_termcaps.c\
		srcs/termcaps/move_cursr.c\
		srcs/termcaps/push_line.c\
		srcs/termcaps/signal.c\
		srcs/termcaps/termcaps.c\
		srcs/termcaps/termcaps_checker.c\
		srcs/termcaps/tools_for_mode.c\
		srcs/termcaps/tools_line_edition.c


OBJS = $(SRCS:.c=.o)

DEPS = $(LIBFTDIR)/$(LIBFT)\
		includes/ast/ast.h\
		includes/exec/exec.h\
		includes/lexer_parser/lexer_parser.h\
		includes/shell.h\
		includes/termcaps/termcaps.h

.PHONY: target makelib clean fclean re

all: target makelib $(NAME)

target:
	@echo 'Target name: $(NAME)'

$(NAME): $(OBJS)
	@echo 'Linking objects...'
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)
	@echo 'Done :)'

%.o: %.c $(DEPS)
	@echo 'Compiling $<...'
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

makelib:
	@echo 'Building library...'
	@$(MAKE) -C $(LIBFTDIR)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFTDIR) clean
	@echo 'Cleared objects.'

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean
	@echo 'Cleared binary.'

re: fclean all
