/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 08:30:08 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/05 11:45:13 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_H
# define BUILD_H

# include "minishell.h"

void	ft_pwd(char **g_env);
void	ft_env(char **g_env);
void	ft_echo(t_element *element);
char	**extract_env_list(t_env *env);
char	**extract_all_env_list(t_env *env);
int		ft_export(t_env *m_env, char **args);
void	without_equal_export(t_env *env, char *arg);
void	with_equal_export(t_env *env, char *arg);
char	**separate_env_var(char *var);

#endif

