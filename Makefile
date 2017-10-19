#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 16:47:54 by tshevchu          #+#    #+#              #
#    Updated: 2017/07/14 14:30:31 by tshevchu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = filler

FLAGS = -Wall -Wextra -Werror

LIBFT = libft/

OBJECTS = additional_func.o algo3.o deal_with_map.o deal_with_piece.o deal_with_struct.o find_coord.o find_dist.o filler.o

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(LIBFT)
	@gcc $(OBJECTS) $(FLAGS) $(LIBFT)libft.a -o $(NAME)
	@echo "\x1B[01;91m>>>>>FILLER IS READY!!<<<<<"

%.o: ./%.c
	@gcc $(FLAGS) -o $@ -c $<

clean:
	@make clean -C libft
	@rm -f $(OBJECTS)
	@echo "\x1B[01;90m>>>CLEAN FILLER & LIBFT OBJ<<<"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "\x1B[01;93m>>>EVERYTHING IS CLEAR:)<<<"

re: fclean all