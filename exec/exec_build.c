/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 08:54:38 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/12 12:23:32 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "build.h"

void	*return_p_function_build(char *elem)
{
	void	(*funct_build)(char **);

	if (ft_strlen(arg[0]) == 3 && ft_strncmp(arg[0], "pwd", 3))
		return (func_build = ft_pwd);
	else if (ft_strlen(arg[0]) == 2 && ft_strncmp(arg[0], "cd", 2))
		return (func_build = ft_cd);
	else if (ft_strlen(arg[0]) == 4 && ft_strncmp(arg[0], "echo", 4))
		return (func_build = ft_echo);
	else if (ft_strlen(arg[0]) == 3 && ft_strncmp(arg[0], "env", 3))
		return (func_build = ft_env);
	else if (ft_strlen(arg[0]) == 6 && ft_strncmp(arg[0], "export", 6))
		return (func_build = ft_export);
	else if (ft_strlen(arg[0]) == 5 && ft_strncmp(arg[0], "unset", 5))
		return (func_build = ft_unset);
	else if (ft_strlen(arg[0]) == 4 && ft_strncmp(arg[0], "exit", 4))
		return (func_build = ft_exit);
	else if (ft_strlen(arg[0]) == 10 && ft_strncmp(arg[0], "do_nothing", 10))
		return (func_build = ft_exit);
	else
		return (NULL);
}
