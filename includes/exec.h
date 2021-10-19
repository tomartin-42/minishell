/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:17:24 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/19 13:40:06 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
//cmd_exwcution.c//
void		cmd_execution(t_command *command, t_env *env);
int			build_filt(t_command *command, t_env *env);
////////////////////
//rutine.c//
void		execut_cmd_build(char **cmd, t_env *env, t_command *command);
void		execut_cmd(char **cmd, char **env, t_command *command);
///////////////////
//super_tolower.c//
char	*super_tolower(char *str);
/////////////
void		get_fd_pipes(t_element *element);
void		*return_p_function_build(char *elem);
#endif
