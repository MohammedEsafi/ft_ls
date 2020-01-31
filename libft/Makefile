# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/29 23:34:49 by mesafi            #+#    #+#              #
#    Updated: 2020/01/31 15:56:11 by mesafi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Usage:
# make			# compile all binary
# make clean	# remove all binaries and objects
# make fclean	# remove created library
# make re		# Get recompiled

# Standard variables
NAME		= libft.a

FT_PRINTF	= ft_printf/ft_printf.a

OBJS		= ft_atoi.o \
			ft_bzero.o \
			ft_del.o \
			ft_isalnum.o \
			ft_isalpha.o \
			ft_isascii.o \
			ft_isdigit.o \
			ft_isprint.o \
			ft_itoa.o \
			ft_lstadd.o \
			ft_lstadd_i.o \
			ft_lstcount.o \
			ft_lstdel.o \
			ft_lstdelone.o \
			ft_lstiter.o \
			ft_lstmap.o \
			ft_lstnew.o \
			ft_lstpop.o \
			ft_lstpush.o \
			ft_lstrm.o \
			ft_lstrm_i.o \
			ft_memalloc.o \
			ft_memccpy.o \
			ft_memchr.o \
			ft_memcmp.o \
			ft_memcpy.o \
			ft_memdel.o \
			ft_memmove.o \
			ft_memset.o \
			ft_putchar.o \
			ft_putchar_fd.o \
			ft_putendl.o \
			ft_putendl_fd.o \
			ft_putlst.o \
			ft_putnbr.o \
			ft_putnbr_fd.o \
			ft_putstr.o \
			ft_putstr_fd.o \
			ft_strcat.o \
			ft_strchr.o \
			ft_strclr.o \
			ft_strcmp.o \
			ft_strcpy.o \
			ft_strdel.o \
			ft_strdup.o \
			ft_strequ.o \
			ft_striter.o \
			ft_striteri.o \
			ft_strjoin.o \
			ft_strlcat.o \
			ft_strlen.o \
			ft_strmap.o \
			ft_strmapi.o \
			ft_strncat.o \
			ft_strncmp.o \
			ft_strncpy.o \
			ft_strnequ.o \
			ft_strnew.o \
			ft_strnstr.o \
			ft_strrchr.o \
			ft_strsplit.o \
			ft_strstr.o \
			ft_strsub.o \
			ft_strtrim.o \
			ft_tolower.o \
			ft_toupper.o \
			get_int_len.o \
			ft_strjoin_free.o \
			get_next_line.o \
			queue/init_queue.o \
			queue/free_queue.o \
			queue/dequeue.o \
			queue/enqueue.o \
			stack/init_stack.o \
			stack/free_stack.o \
			stack/pop.o \
			stack/push.o \
			graph/create_graph.o \
			graph/add_edge.o \
			graph/print_graph.o \
			array_list/init_array_list.o \
			array_list/free_array_list.o \
			array_list/append.o

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

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

$(NAME): $(OBJS) libft.h
	@make -s -C ft_printf
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "⇾ $(NAME) $(GREEN)done ( ˆᴗˆ )$(RESET)"

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@
	@if [[ -f $(NAME) ]] ; then \
		echo "⇾ $@ $(GREEN)updated$(RESET)" ; \
	fi;

clean:
	@rm -f $(OBJS)
	@echo "⇾ $(NAME) $(RED)cleaned$(RESET)"
	@make -s clean -C ft_printf

fclean: clean
	@rm -f $(NAME)
	@echo "⇾ $(NAME) $(RED)deleted$(RESET)"
	@rm -f $(FT_PRINTF)

re: fclean all
