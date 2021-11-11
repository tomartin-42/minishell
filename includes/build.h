/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 08:30:08 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/11 19:38:49 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_H
# define BUILD_H

# include "minishell.h"
# include "exec.h"

//void	ft_env(char **g_env);
//void	ft_echo(t_element *element);
char	**extract_env_list(t_env *env);
char	**extract_all_env_list(t_env *env);
int		ft_export(t_env *m_env, char **args);
void	without_equal_export(t_env *env, char *arg);
void	with_equal_export(t_env *env, char *arg);
char	**separate_env_var(char *var);
int		search_if_var(t_env *env, char *arg);
void	print_env_vars(t_env *env);
//ft_echo.c//
int		ft_echo(char **args);
/////////////
//ft_pwd.c//
int		ft_pwd(t_env *env);
/////////////
//ft_env.c//
int		ft_env(t_env *env);
/////////////
//ft_cd.c//
int		ft_cd(t_command *command, t_env	*env);
/////////////
//util_env2.c//
void	ch_env_var(t_env *env, char *var, char *n_value);
/////////////
//ft_exit.c//
int		ft_exit(t_command *command, t_env *env);
/////////////
//ft_cd_utils.c//
void	remove_end_trash(t_command *command);
int		check_consec_dots(char *arg);
/////////////
int		ft_unset(t_command *command, t_env *env);

int		ft_do_nothing(void);
void	print_env_vars(t_env *env);

#endif
