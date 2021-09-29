# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tommy <tommy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/04 19:11:19 by tomartin          #+#    #+#              #
#    Updated: 2021/09/29 11:19:43 by tomartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Name of the program
NAME = minishell

# Compiling flags
FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
F_RL = -I ~/.brew/opt/readline/include -I ~/.brew/opt/readline/lib 

# Folders
LIBFT_DIR = ./libft/
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
PARSE_DIR= ./parse/
HERED_DIR= ./hered/
BUILD_DIR = ./build/

# Source files and object files
SRC_FILES = main.c utils_list.c
PARSE_FILES = main_parse.c procesing_parse.c check_error.c parse_operation.c
HERED_FILES = main_hered.c
BUILD_FILES = main_build.c ft_export.c

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_FILES := $(OBJ_FILES) $(PARSE_FILES:.c=.o)
OBJ_FILES := $(OBJ_FILES) $(HERED_FILES:.c=.o)
OBJ_FILES := $(OBJ_FILES) $(BUILD_FILES:.c=.o)

# Paths
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
PARSE = $(addprefix $(PARSE_DIR), $(PARSE_FILES))
HERED = $(addprefix $(HERED_DIR), $(HERED_FILES))
BUILD = $(addprefix BUILD_DIR), $(BUILD_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# Libft linkers
LNK = -L $(LIBFT_DIR) -lft

# all rule
all: obj $(LIBFT) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
 
$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	@gcc $(FLAGS) $(F_RL) -I $(INC_DIR) -I $(LIBFT_DIR) -o $@ -c $<
$(OBJ_DIR)%.o: $(PARSE_DIR)%.c 
	@gcc $(FLAGS) $(F_RL) -I $(INC_DIR) -I $(LIBFT_DIR) -o $@ -c $<
$(OBJ_DIR)%.o: $(HERED_DIR)%.c 
	@gcc $(FLAGS) $(F_RL) -I $(INC_DIR) -I $(LIBFT_DIR) -o $@ -c $<
$(OBJ_DIR)%.o: $(BUILD_DIR)%.c 
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
