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
		srcs/exec_it/main.c\
		srcs/exec_it/tools.c\
		srcs/exec_it/tools_env.c\
		srcs/exec_it/sh_abort.c\
		srcs/history/hst_browse_next.c\
		srcs/history/hst_browse_prev.c\
		srcs/history/hst_push.c\
		srcs/history/hst_retrieve.c\
		srcs/history/hst_update_cbuf.c\
		srcs/history/hst_tmp_push.c\
		srcs/history/get_histfile_path.c\
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
		srcs/termcaps/signal.c\
		srcs/termcaps/clipboard/cb_copy_internal.c\
		srcs/termcaps/clipboard/cb_cut_internal.c\
		srcs/termcaps/clipboard/cb_paste_external.c\
		srcs/termcaps/clipboard/cb_paste_internal.c\
		srcs/termcaps/command_buffer/cbuf_append.c\
		srcs/termcaps/command_buffer/cbuf_check_size.c\
		srcs/termcaps/command_buffer/cbuf_insert.c\
		srcs/termcaps/command_buffer/cbuf_print.c\
		srcs/termcaps/command_buffer/cbuf_reset.c\
		srcs/termcaps/highlighting/highlight.c\
		srcs/termcaps/highlighting/highlight_cleanup.c\
		srcs/termcaps/key_events/evt_backspace.c\
		srcs/termcaps/key_events/evt_ctrl_d.c\
		srcs/termcaps/key_events/evt_ctrl_dpad_down.c\
		srcs/termcaps/key_events/evt_ctrl_dpad_left.c\
		srcs/termcaps/key_events/evt_ctrl_dpad_right.c\
		srcs/termcaps/key_events/evt_ctrl_dpad_up.c\
		srcs/termcaps/key_events/evt_ctrl_h.c\
		srcs/termcaps/key_events/evt_ctrl_p.c\
		srcs/termcaps/key_events/evt_del.c\
		srcs/termcaps/key_events/evt_tab.c\
		srcs/termcaps/key_events/evt_dpad_down.c\
		srcs/termcaps/key_events/evt_dpad_left.c\
		srcs/termcaps/key_events/evt_dpad_right.c\
		srcs/termcaps/key_events/evt_dpad_up.c\
		srcs/termcaps/key_events/evt_end.c\
		srcs/termcaps/key_events/evt_handler.c\
		srcs/termcaps/key_events/evt_home.c\
		srcs/termcaps/key_events/evt_newline.c\
		srcs/termcaps/key_events/evt_printable.c\
		srcs/termcaps/tc_init.c\
		srcs/termcaps/tc_restore_default.c\
		srcs/termcaps/tc_set_blocking_read.c\
		srcs/termcaps/tc_set_timed_read.c\
		srcs/termcaps/tc_unset_canonical.c\
		srcs/termcaps/tc_write.c\
		srcs/termcaps/termcaps.c\
		srcs/termcaps/autocompletion.c\
		srcs/termcaps/autocompletion2.c

OBJS = $(SRCS:.c=.o)

DEPS = $(LIBFTDIR)/$(LIBFT)\
		includes/ast.h\
		includes/exec.h\
		includes/lexer_parser.h\
		includes/shell.h\
		includes/termcaps.h

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
