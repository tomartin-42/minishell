# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/04 19:11:19 by tomartin          #+#    #+#              #
#    Updated: 2021/09/19 21:20:19 by tomartin         ###   ########.fr        #
#    Updated: 2021/09/19 13:35:25 by tomartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME = minishell

# Compiling flags
FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
F_RL = -I ~/.brew/opt/readline/include -I ~/.brew/opt/readline/lib 

# Folders
SRC_DIR = ./src/
EXEC_DIR = ./exec/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/

# Source files and object files
SRC_FILES = main.c
EXEC_FILES = check.c error.c free_resource.c main_exec.c utils.c parse.c

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_FILES := $(OBJ_FILES) $(EXEC_FILES:.c=.o)

# Paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
EXE = $(addprefix $(EXEC_DIR), $(EXEC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

# Libft linkers
LNK = -L $(LIBFT_DIR) -lft

# all rule
all: obj $(LIBFT) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	@gcc $(FLAGS) $(F_RL) -I $(INC_DIR) -I $(LIBFT_DIR) -o $@ -c $<
$(OBJ_DIR)%.o: $(EXEC_DIR)%.c 
	@gcc $(FLAGS) $(F_RL) -I $(INC_DIR) -I $(LIBFT_DIR) -o $@ -c $<

$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compiling
$(NAME): $(OBJ)
	@gcc $(OBJ) $(FLAGS) $(LNK) -lreadline $(F_RL) -lm -o $(NAME)
	@echo "Compilation OK!!"
	@echo "$(NAME) ready!".

bonus: all

# clean rule
clean:
	@rm -Rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "Objects removed!"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(NAME) removed!"

 # re rule
 re: fclean all

 # phony
 .PHONY: all clean fclean re
