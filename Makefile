# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khakala <khakala@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 16:11:53 by khakala           #+#    #+#              #
#    Updated: 2020/01/28 15:44:53 by khakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = libft/libft.a srcs/main.c srcs/draw.c srcs/read_map.c srcs/key_bindings.c

OBJ = $(SRC:.c=.o)

CCFL = gcc -g -Wall -Wextra -Werror -I /usr/local/include/ -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@$(CCFL) -o $(NAME) $(OBJ) $(SRCS)

clean:
	@/bin/rm -f $(OBJ)5
	@make -C $(LIBFT) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean
	
re: fclean all

.PHONY = all $(NAME) clean fclean re