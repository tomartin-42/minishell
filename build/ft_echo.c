/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:39:03 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 21:25:08 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

int	infinity_n(char *args)
{
	int	pos;

	pos = 2;
	if (args[0] == '-' && args[1] == 'n')
	{
		while (args[pos] != '\0' && args[pos] == 'n')
		{
			pos++;
		}
		if (args[pos] != '\0' && args[pos] != 'n')
			return (0);
		else if (args[pos] == '\0')
			return (1);
	}
	return (0);
}

int	echo_print(char **args, int flag)
{
	int	pos;
	int	space;

	space = 0;
	pos = 1;
	while (args[pos])
	{
		if (infinity_n(args[pos]))
			flag = 1;
		else if (args[pos][0] == '$' && args[pos]
			&& args[pos][1] == '?')
		{
			printf("errno\n");
		}
		else
		{
			if (space != 0)
				write(1, " ", 1);
			ft_putstr_fd(args[pos], 1);
			space++;
		}
		pos++;
	}
	return (flag);
}

int	ft_echo(char **args)
{
	int		pos;
	int		flag;

	flag = 0;
	pos = 1;
	if (!args[1])
	{
		write (1, "\n", 1);
		return (0);
	}
	if (ft_strcmp(args[pos], "errno") == 0)
		printf("%d\n", g_state);
	else
	{
		flag = echo_print(args, flag);
		if (flag == 0)
			write(1, "\n", 1);
	}
	return (0);
}
