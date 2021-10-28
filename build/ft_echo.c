/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:39:03 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/28 08:43:52 by tomartin         ###   ########.fr       */
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

void	echo_out(char *string)// quitar, funcion inecesaria, usar directamente ft_putstr_fd();
{
	ft_putstr_fd(string, 1);
}

int	ft_echo(char **args)
{
	int		pos;
	int		space;
	bool	flag;

	space = 0;
	flag = false;
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
		while (args[pos])
		{
			if (infinity_n(args[pos]))
				flag = true;
			else
			{
				if (space != 0)
					write(1, " ", 1);
				echo_out(args[pos]);
				space++;
			}
			pos++;
		}
		if (flag == false)
			write(1, "\n", 1);
	}
	//if (flag == false)
		//write(1, "\n", 1);
	//exit (0);
	return (0);
}
