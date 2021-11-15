/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:10:13 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/15 10:00:11 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ======================================================================
 * C = Comand--
 * P = Pipe
 * S = String
 * I = InputFile--
 * O = OutputFile--
 * T = Trunc--
 * H = HereDoc--
 * X = Delete Node
 * G = All line
 * F = File
 * A = Argument
 * ? = Unknown
 * E = ADD VAR
 * $ = CALL VAR
 * ======================================================================*/

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <dirent.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <signal.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <termios.h>
# include "libft.h"

# define OK			1
# define KO			0
# define MAX_PIPE	128 

typedef struct s_env{
	char			*v_env;
	char			**var;	
	bool			global;
	bool			visible;
	struct s_env	*next;
}	t_env;

typedef struct s_element{
	char				*str;
	char				**arg;
	char				type;
	int					fd;
	int					p_fd[2];
	int					cmd_num;
	bool				hd_expand;
	struct s_element	*next;
	struct s_element	*prev;
}	t_element;

extern int	g_state;

t_element	*ft_lstlast(t_element *lst);
void		ft_lstadd_back(t_element **lst, t_element *new);
void		ft_lst_del_all_x(t_element *elemnt);

int			ft_access(char *fname);
char		*expand_var(t_env *m_env, char *str);

void		init_env_list(t_env **m_env, char *var);
void		ft_lstadd_back_env(t_env **lst, t_env *new);
t_env		*new_env_node_global(t_env *new, char *var);
t_env		*new_env_node_export(t_env *new, char *var);
t_env		*ft_lstlast_env(t_env *lst);
void		change_shlvl(t_env *env);
void		change_sigle_env_var(t_env *env, char *var, char *n_value);

char		*ft_expand(t_env *m_env, char *str);

//src/get_env.c//
char		*get_env(char **envs, char *var);
char		*get_t_env(t_env *env, char *var);
int			errno_dollar(char *str);
/////////////////
//expand.c//
char		*remplace_str(char *str, char *var_value);
/////////////////
////
int			errno_dollar(char *str);
/////////////////
//main.c//
void		init_element(t_element *element, char *line);
/////////////////
//exit_process.c//
void		exit_proces(int sig);
/////////////////
//main_loop,c//
void		main_loop(struct termios old, t_env *m_env);
/////////////////
void		select_signal(void);
void		signal_in_proces(void);
void		signal_hered(void);
void		signal_build_hered(void);
void		signal_ignorate(void);
//void		exit_in_proces(int sig);

void		free_element(t_element *element);
void		free_env_list(t_env *env);
/////////////////////
void		print_list(t_element *element);
void		print_arg_list(t_element *element);

#endif
