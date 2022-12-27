# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inskim <inskim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 22:08:10 by inskim            #+#    #+#              #
#    Updated: 2022/12/27 09:30:29 by inskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra 

SRC = free.c ft_split.c ft_strncmp.c get_next_line.c get_next_line_utils.c handle_error.c main.c make_process.c parse.c pipex_strjoin.c read_file_pipe.c pipex_split.c
HEADER = pipex.h get_next_line.h
OBJ = $(SRC:.c=.o)
BONUS_SRC = $(patsubst %.c, $(basename %)_bonus.c, $(SRC)) heredoc_pipe_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): make_mandatory

bonus: make_bonus

make_mandatory: $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	touch $@
	rm -f make_bonus

make_bonus: $(BONUS_OBJ) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJ)
	touch $@
	rm -f make_mandatory

clean:
	rm -f make_mandatory
	rm -f make_bonus
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.phony: all clean fclean re bonus
