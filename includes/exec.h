/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:17:24 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/02 11:56:01 by tomartin         ###   ########.fr       */
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
	t_element	*p_elem;
	t_env		*m_env;
}	t_command;

void		main_exec(t_element *element, t_env *env);
void		rutine_command(t_element *element, t_env *env, t_command *command);
void		redir_files(t_command *command);
void		start_hered(t_element *element, t_env *env, int sig);

char		*find_exec_path(char **cmd, char **env);
//build_filter.c//
int			is_build(t_element *p_elem);
void		main_build_filt(t_element *element);
////////////////////
//build_filt_complete.c//
int			build_filt_complete(t_command *command, t_env *env, int	error_num);
////////////////////
//close_forks.c//
void		close_forks(t_element *element);
////////////////////
////
void		open_to_read(t_element *element);
void		open_to_write(t_element *element);
void		open_to_trunk(t_element *element);
////////////////////
//cmd_exwcution.c//
void		cmd_execution(t_element *element, t_command *command, t_env *env);
int			build_filt(t_command *command, t_env *env);
////////////////////
//rutine.c//
void		execut_cmd_build(t_env *env, t_command *command);
void		execut_cmd_build_np(t_env *env, t_command *command);
void		execut_cmd(char **env, t_command *command);
///////////////////
//extct_cmd_args.c//
void		extract_cmd_and_arg(t_command *command);
////////////////////
//super_tolower.c//
char		*super_tolower(char *str);
/////////////
//ft_count_wrd.c//
int			ft_count_char(char *str, char	caracter);
/////////////
void		get_fd_pipes(t_element *element);
void		*return_p_function_build(char *elem);

bool		check_pipes_in_line(t_element *element);
bool		check_pipes_or_cmd(t_element *element);
#endif
