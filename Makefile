# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/04 19:11:19 by tomartin          #+#    #+#              #
#    Updated: 2021/09/18 20:36:02 by tomartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME = minishell

# Compiling flags
FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
F_RL = -I ~/.brew/opt/readline/include -I ~/.brew/opt/readline/lib -lreadline

# Folders
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./includes/

# Source files and object files
SRC_FILES = main.c

OBJ_FILES = $(SRC_FILES:.c=.o)

# Paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# Libft linkers
#LNK  = -L $(LIBFT_DIR) -lft

# all rule
all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) $(F_RL) -I $(INC_DIR) -o $@ -c $<

# Compiling
$(NAME): $(OBJ)
	@gcc $(OBJ) $(FLAGS) $(F_RL) -lm -o $(NAME)
	@echo "Compilation OK!!"
	@echo "$(NAME) ready!".

bonus: all

# clean rule
clean:
	@rm -Rf $(OBJ_DIR)
	@echo "Objects removed!"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed!"

 # re rule
 re: fclean all

 # phony
 .PHONY: all clean fclean re