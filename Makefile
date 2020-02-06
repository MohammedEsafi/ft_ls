# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 13:51:29 by mesafi            #+#    #+#              #
#    Updated: 2020/02/06 10:02:42 by mesafi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Usage:
# make			# compile all binary
# make clean	# remove all binaries and objects
# make fclean	# remove created library
# make re		# Get recompiled

# Standard variables
NAME		= ft_ls
LIBFT		= libft/libft.a
FT_PRINTF	= libft/ft_printf/ft_printf.a
HEADER		= ft_ls.h
OBJS		= ft_ls.o \
				helpers/ft_options.o \
				helpers/ft_get_list.o \
				helpers/ft_merge_sort.o \
				helpers/ft_reader.o \
				helpers/free_list_dir.o \
				helpers/find_max_lenght.o \
				helpers/ft_print_flag_list.o \
				helpers/ft_join_path.o \
				helpers/ft_print_flag.o \
				helpers/cursor_first_pos.o
CC			= gcc
CFLAGS		= -ltermcap

# Colors
BLACK		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[93m
BLUE		= \033[34m
MAGENTA		= \033[35m
CYAN		= \033[36m
WHITE		= \033[37m
RESET		= \033[0m

# Start rules
all: build $(NAME)

build:
	@if [ ! -f $(NAME) ] ; then \
		echo "⇾ building $(NAME)..." ; \
	fi;

$(NAME): $(OBJS) $(HEADER)
	@make -s -C libft
	@if [ ! -f $(NAME) ] ; then \
		echo "⇾ $(NAME) $(GREEN)done$(RESET)"; \
	else \
		echo "⇾ $(NAME) $(GREEN)updated$(RESET)"; \
	fi;
	@gcc $(CFLAGS) $(LIBFT) $(FT_PRINTF) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@
	@if [[ -f $(NAME) ]] ; then \
		echo "⇾ $@ $(GREEN)updated$(RESET)" ; \
	fi;

clean:
	@make -s clean -C libft
	@rm -f $(OBJS)
	@echo "⇾ $(NAME) $(RED)cleaned$(RESET)"
	
fclean: clean
	@rm -f $(FT_PRINTF)
	@rm -f $(LIBFT)
	@echo "⇾ libft.a $(RED)deleted$(RESET)"
	@rm -f $(NAME)
	@echo "⇾ $(NAME) $(RED)deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re build
