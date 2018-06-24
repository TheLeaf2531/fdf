# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 17:11:05 by vboissel          #+#    #+#              #
#    Updated: 2018/06/24 16:25:49 by vboissel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FLAGSMLIB = -lmlx -framework OpenGL -framework AppKit
LIBFT_DIR = ./libft/
LIBFT = ./libft/libft.a
SRC = $(wildcard ./sources/fdf/*.c) $(wildcard ./sources/parser/*.c) $(wildcard ./sources/geometry/*.c)
INC = ./headers/
INC_MLX = /usr/local/include

all : $(NAME)

$(NAME): $(SRC) $(INC)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(FLAGSMLIB) -I $(INC) -I $(LIBFT_DIR) $(LIBFT) $(SRC)  
	@mv a.out $(NAME)

clean :
	@(cd $(LIBFT_DIR) && $(MAKE) $@)

fclean : clean
	@(cd $(LIBFT_DIR) && $(MAKE) $@)
	@rm $(NAME)

re : fclean all

.phony : $(NAME)
