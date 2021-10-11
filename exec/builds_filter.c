/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builds_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:48:31 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/11 20:13:35 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	exec_build(char **command, char **env)
{
	printf("ES BUILD->%s, %s", command[0], env[0]);
}

int	is_build(t_element *element, t_command *command)
{
	int	n;

	n = 0;
	if (element)
		;
	if (ft_strcmp(command->command[0], "echo") == 0)
	{
		printf("\nES BUILD->%s\n\n", command->command[0]);
		return (1);
	}
	else if (ft_strcmp(command->command[0], "cd") == 0)
	{
		printf("\nES BUILD->%s\n\n", command->command[0]);
		return (1);
	}
	else if (ft_strcmp(command->command[0], "export") == 0)
	{
		printf("\nES BUILD->%s\n\n", command->command[0]);
		return (1);
	}
	else if (ft_strcmp(command->command[0], "unset") == 0)
	{
		printf("\nES BUILD->%s\n\n", command->command[0]);
		return (1);
	}
	else if (ft_strcmp(command->command[0], "env") == 0)
	{
		printf("\nES BUILD->%s\n\n", command->command[0]);
		return (1);
	}
	else if (ft_strcmp(command->command[0], "exit") == 0)
	{
		printf("\nES BUILD->%s\n\n", command->command[0]);
		return (1);
	}
	return (0);
}
