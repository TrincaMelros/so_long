# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malmeida <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 12:30:32 by malmeida          #+#    #+#              #
#    Updated: 2021/10/20 10:37:05 by malmeida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS	+=	--quiet

			# Library Name #
NAME		=
SO_LONG		=	so_long

			# Libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

			# Mandatory Variables #
SRCS	=	./srcs/*.c

			# Compiling Variables #
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address
MLX		= -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL \
		  -framework AppKit
INC		= -I./includes -I$(LIBFT_DIR)
RM		= rm -f

			# Color Variables #
GREEN		= \e[0;32m
RED			= \e[0;31m
YELLOW		= \e[0;33m
RESET		= \e[0m

all: $(SO_LONG)

$(NAME): all

$(SO_LONG): $(LIBFT) $(SRCS)
	@ $(CC) $(CFLAG) $(SRCS) $(LIBFT) $(MLX) -o $(SO_LONG)
	@printf "[$(GREEN)SUCCESS$(RESET)] So_long compiled.\n"

$(LIBFT):
	@ $(MAKE) -C ./libft

clean:
	@ $(RM) $(SO_LONG)
	@printf "[$(YELLOW)SUCCESS$(RESET)] Executable removed.\n"

fclean:
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(RM) $(SO_LONG)
	@printf "[$(YELLOW)SUCCESS$(RESET)] Library removed.\n"
	@printf "[$(YELLOW)SUCCESS$(RESET)] Executable removed.\n"

re: fclean all

mandatory:	$(SO_LONG)
bonus:		mandatory

m:	mandatory
b: 	bonus
