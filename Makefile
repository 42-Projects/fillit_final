# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlewis-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/31 12:16:17 by mlewis-l          #+#    #+#              #
#    Updated: 2018/06/06 14:04:30 by mlewis-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIBFT = libft/libft.a
CC = gcc

CONFIG = $(CC) -Wall -Wextra -Werror

HEADER = -I libft/

SRC = points.c lst_util.c read_file.c grid.c main.c \
	  solve_puzzle.c tetrimino.c tetri_utils.c place_tetrimino.c

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CONFIG) $(HEADER) $(LIBFT) $(OBJ) -o $(NAME)

$(LIBFT):
	@make -C libft/

%.o: %.c
	@echo "Re-compiling... $<"
	@$(CONFIG) $(HEADER) -c $<

clean:
	@echo "Cleaning!"
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@echo "Fcleaning!"
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
