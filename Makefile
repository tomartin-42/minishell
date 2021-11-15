# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/04 19:11:19 by tomartin          #+#    #+#              #
#    Updated: 2021/11/15 10:01:20 by tomartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Collors
BLU = \033[0;34m
GRN = \033[0;32m
YEL = \033[0;33m
RED = \033[0;31m
WHT = \033[0;37m
ORG = \033[38;5;202m

RESET = \033[0m                        

# Name of the program
NAME = minishell

# Compiling flags
FLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
F_RL = -I ~/.brew/opt/readline/include -I ~/.brew/opt/readline/lib 
F_RL2 = -lreadline -L /Users/$(USER)/.brew/opt/readline/lib \
		-I /Users/$(USER)/.brew/opt/readline/include


# Folders
LIBFT_DIR = ./libft/
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
PARSE_DIR= ./parse/
HERED_DIR= ./hered/
BUILD_DIR = ./build/
ERRORS_DIR=./errors/
EXPANSION_DIR=./expansion/
EXEC_DIR= ./exec/
INC_DIR = ./includes/

# Source files and object files
SRC_FILES = main.c main_loop.c utils_list.c util_env.c expand.c \
			util_env2.c utils_src.c \
			get_env.c signal.c free_resources.c exit_process.c
PARSE_FILES = main_parse.c procesing_parse.c parse_operation.c \
			  sec_parse_proc.c in_args.c parse_utils.c parse_utils_2.c \
			  copy_dell_args.c in_args_memory.c hered_expand_loop.c \
			  str_ex_utils.c
HERED_FILES = main_hered.c
BUILD_FILES = ft_export.c ft_export2.c ft_export3.c ft_echo.c ft_env.c \
			  ft_pwd.c ft_cd.c super_tolower.c \
			  ft_exit.c ft_count_char.c ft_unset.c cmd_exec_build_filt.c \
			  ft_do_nothing.c
ERRORS_FILES = check_error.c errors.c errors_exec.c main_errors.c
EXPANSION_FILES = env_ex.c str_ex.c expansion.c env_ex2.c
EXEC_FILES = main_exec.c rutine.c path_find.c builds_filter.c \
			 cmd_execution.c rutine_utils.c open_read_write_trunk.c \
			 open_read_write_trunk_np.c
INC_FILES = (build.h errorlib.h exec.h hered.h minishell.h parse.h

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_FILES := $(OBJ_FILES) $(PARSE_FILES:.c=.o)
OBJ_FILES := $(OBJ_FILES) $(HERED_FILES:.c=.o)
OBJ_FILES := $(OBJ_FILES) $(BUILD_FILES:.c=.o)
OBJ_FILES := $(OBJ_FILES) $(ERRORS_FILES:.c=.o)
OBJ_FILES := $(OBJ_FILES) $(EXPANSION_FILES:.c=.o)
OBJ_FILES := $(OBJ_FILES) $(EXEC_FILES:.c=.o)

# Paths
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
PARSE = $(addprefix $(PARSE_DIR), $(PARSE_FILES))
HERED = $(addprefix $(HERED_DIR), $(HERED_FILES))
BUILD = $(addprefix $(BUILD_DIR), $(BUILD_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
ERROR = $(addprefix $(ERRORS_DIR), $(ERRORS_FILES))
EXPAND = $(addprefix $(EXPANSION_DIR), $(EXPANSION_FILES))
ERROR = $(addprefix $(EXEC_DIR), $(EXEC_FILES))
INC = $(addprefix $(INC_DIR), $(INC_FILES))

# Libft linkers
LNK = -L $(LIBFT_DIR) -lft

# all rule
all: obj $(LIBFT) $(NAME) 

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	@gcc $(FLAGS) $(F_RL) -I $(INC_DIR) -I $(LIBFT_DIR) -o $@ -c $<
$(OBJ_DIR)%.o: $(ERRORS_DIR)%.c 
	@gcc $(FLAGS) $(F_RL) -I $(INC_DIR) -I $(LIBFT_DIR) -o $@ -c $<
$(OBJ_DIR)%.o: $(PARSE_DIR)%.c 
	@gcc $(FLAGS) $(F_RL) -I $(INC_DIR) -I $(LIBFT_DIR) -o $@ -c $<
$(OBJ_DIR)%.o: $(HERED_DIR)%.c 
	@gcc $(FLAGS) $(F_RL) -I $(INC_DIR) -I $(LIBFT_DIR) -o $@ -c $<
$(OBJ_DIR)%.o: $(BUILD_DIR)%.c 
	@gcc $(FLAGS) $(F_RL) -I $(INC_DIR) -I $(LIBFT_DIR) -o $@ -c $<
$(OBJ_DIR)%.o: $(EXPANSION_DIR)%.c 
	@gcc $(FLAGS) $(F_RL) -I $(INC_DIR) -I $(LIBFT_DIR) -o $@ -c $<
$(OBJ_DIR)%.o: $(EXEC_DIR)%.c 
	@gcc $(FLAGS) $(F_RL) -I $(INC_DIR) -I $(LIBFT_DIR) -o $@ -c $<

$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compiling
$(NAME): $(OBJ)
	@echo "$(RED) █  ████ ████╗     █  █ ███ ███ █╗    ██  █╗    ██  █╗"
	@echo "$(RED)███ ████████ ║     ██ █ ████ ██  ║    █   █║     ██ █║"
	@echo "$(ORG) ████╔═══════╝     █  █ ╔════════╝    ██ ██║      ███║"
	@echo "$(RED)███ █║             █ ███║              ████║    █████║"
	@echo "$(ORG)█  ██║             ██ ██║             ████ ║     ███ ║"
	@echo "$(ORG)███████  ██ ═╗      █████  ██ █═╗     ███████████████║"
	@echo "$(YEL) █ █████ ██ █║      ██████ █████║      ███  ████ ████║"
	@echo "$(ORG)╚═══════███ █║     █████╔═══════╝     █████╔════████ ║"
	@echo "$(YEL)         ███ ║      ████║             █████║     ████║"
	@echo "$(ORG)        █████║     ████ ║              ██  ║    █████║"
	@echo "$(YEL)██  ███ ████ ║     ███  ║             █████║    ████ ║"
	@echo "$(YEL)███ █ █████ █║ ██╗ █ ██ ║         ██╗ ║███ ║    ║█ ██║ ██╗"
	@echo "$(YEL)╚════════════╝ ╚═╝ ╚════╝         ╚═╝ ╚════╝    ╚════╝ ╚═╝$(RESET)"
	@gcc $(OBJ) $(FLAGS) $(LNK) $(F_RL) -lm -o $(NAME) $(F_RL2)
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

 normi:
	@norminette */*.c */*.h

 # phony
 .PHONY: all clean fclean re
