/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 08:30:08 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/25 11:03:36 by dpuente-         ###   ########.fr       */
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
void	change_single_env_var(t_env *env, char *var, char *n_value);
/////////////
//ft_exit.c//
int		ft_exit(t_command *command, t_env *env);
/////////////
int		ft_unset(t_command *command, t_env *env);
void	print_env_vars(t_env *env);
#endif
