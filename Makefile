# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnetshik <dnetshik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 11:44:46 by dnetshik          #+#    #+#              #
#    Updated: 2017/12/22 13:08:13 by dnetshik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = gcc -g -Wall -Werror -Wextra

SRC  = echo.c free_args.c free_tmp.c main.c mini_prompt.c setenv.c unsetenv.c get_path.c tilder.c initialisation.c

OBJ = $(SRC:%.c=%.o)

all:$(NAME)

$(NAME):
	@make -C libft/
	@$(FLAGS) -c $(SRC)
	@$(FLAGS) -o $(NAME) $(SRC) -L libft/ -lft

clean:
	@make clean -C libft/
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re:fclean all

.PHONY:all clean fclean re

