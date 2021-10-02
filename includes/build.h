/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 08:30:08 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/02 19:51:14 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_H
# define BUILD_H

# include "minishell.h"

void	ft_pwd(char **g_env);
void	ft_env(char **g_env);
void	ft_echo(t_element *element);
void	ft_export(t_env *m_env, char **args);

#endif

