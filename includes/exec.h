/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:34:33 by tommy             #+#    #+#             */
/*   Updated: 2021/09/19 21:07:48 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_param{
	char	*file[2];
	char	*cmd[2];
	char	**cmd1;
	char	**cmd2;
	int		n_comand;
	int		n_inputf;
	int		n_outputf;
}	t_param;

void	check(int argc, char **argv, char **env);
void	command_not_found_error(char **cmd);
void	execut_error(char *text, int numerror);
void	get_params(t_param *param, char **argv, char **env);

char	*get_path(char *argv, char **env);
char	*get_correct_path(char **tem_p, char *argv);

void	free_aux(char **aux_path);
void	free_param(t_param *param);

void	open_and_read(t_param param, int *pp);
void	open_and_write(t_param param, int *pp);

void	execut(int argc, char **argv, char **env, char *str);

///---------------------------------------------------/

void	fast_parse(char *str, t_param *param);

#endif
