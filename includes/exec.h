#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

typedef struct s_command{
	char		**env;
	t_element	*multi_cmd[2];
	t_element	*special_cmd[2];
	t_element	*cmd;
	int			fd_stdin;
	int			fd_stdout;
	int			pid_num;
}	t_command;

void		main_exec(t_element *element, t_env *env);
void		rutine_command(t_element *element, t_env *env, t_command *command);
void		redir_files(t_command *command);
void		start_hered(t_element *element);

char		*find_exec_path(char **cmd, char **env);
//build_filter.c//
int			is_build(t_element *p_elem);
void		main_build_filt(t_element *element);
////////////////////
void		get_fd_pipes(t_element *element);
#endif
