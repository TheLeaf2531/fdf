# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 17:11:05 by vboissel          #+#    #+#              #
#    Updated: 2018/04/03 17:39:50 by vboissel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FLAGSMLIB = -lmlx -framework OpenGL -framework AppKit
LIBFT_DIR = libft/
LIBFT = libft/libft.h libft/libft.a
SRC = $(wildcard src/*.c)
INC = $(wildcard inc/*.h)
INC_MLX = /usr/local/include

all : $(NAME)

$(NAME): $(SRC) $(INC)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -I $(INC_MLX) $(LIBFT) $(SRC) $(INC) $(FLAGSMLIB)
	@mv a.out $(NAME)

clean :
	@(cd $(LIBFT_DIR) && $(MAKE) $@)

fclean : clean
	@(cd $(LIBFT_DIR) && $(MAKE) $@)
	@rm $(NAME)

re : fclean all

.phony : $(NAME)
