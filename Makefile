# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khakala <khakala@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 16:11:53 by khakala           #+#    #+#              #
#    Updated: 2019/12/18 13:54:07 by khakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = libft/libft.a srcs/main.c srcs/error.c srcs/read_map.c

OBJ = $(SRC:.c=.o)

CCFL = gcc -g -Wall -Wextra -Werror

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