# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inskim <inskim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 22:08:10 by inskim            #+#    #+#              #
#    Updated: 2022/12/21 12:48:58 by inskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRC = free.c ft_split.c ft_strncmp.c handle_error.c heredoc_pipe.c main.c make_command_process.c parse.c pipex.h pipex_strjoin.c read_file_pipe.c 
HEADER = pipex.h
OBJ = $(SRC:.c=.o)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	cc -o $(NAME) *.o

clean:
	rm $(OBJ)
fclean: clean
	rm -f $(NAME) 

re: fclean
	make all

.phony: all clean fclean re