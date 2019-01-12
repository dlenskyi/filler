# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 16:22:11 by dlenskyi          #+#    #+#              #
#    Updated: 2019/01/12 16:25:30 by dlenskyi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dlenskyi.filler

FLAGS = -Wall -Wextra -Werror -O3
CC = gcc

LIBX_KEY = -lmlx -lm -framework OpenGL -framework AppKit

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HEAD = $(LIBFT_DIR)includes/
FILLER_HEAD = filler.h

INCLUDES = -I$(FDF_HEAD) -I$(LIBFT_HEAD)

SRC = main.c get_data.c magic.c get_coords.c fill_piece.c put_coords.c \
	  validate_piece.c

OBJ = $(patsubst %.c, %.o, $(SRC))

RED = \x1B[31m
GREEN = \x1B[32m
YELLOW = \x1B[33m
OFF = \x1B[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(FLAGS) $(LIBX_KEY) $(INCLUDES) $(LIBFT) $(OBJ) -o $(NAME)
	@echo "$(GREEN)filler completed!\n$(OFF)"
	@echo "$(GREEN)usage example: ./filler_vm -f resources/maps/map01 -p1 ./dlenskyi.filler -p2 resources/players/grati.filler$(OFF)"

%.o: %.c $(FILLER_HEAD)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@echo "$(YELLOW)Compiling filler project...\n$(OFF)"
	@echo "$(YELLOW)Compiling libft...$(OFF)"
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo "$(GREEN)libft.a was created.$(OFF)"

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -f $(OBJ)
	@rm -f filler.trace
	@echo "$(RED)libft.a was removed$(OFF)"

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@rm -f $(OBJ)
	@rm -f filler.trace
	@echo "$(RED)All objects were removed$(OFF)"

re: fclean all
