/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:39:03 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/14 10:52:22 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

int	infinity_n(char *args)
{
	int	pos;

	pos = 2;
	//printf("-->%s<--", args);
	if (args[0] == '-' && args[1] == 'n')
	{
		//printf("Entro pepote");
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

int	echo_out(char *string)
{
	ft_putstr_fd(string, 1);
	if (!string)
		return (-1);
	return (0);
}

int	ft_echo(char **args)
{
	int		pos;
	int		space;
	bool	flag;

	space = 0;
	flag = false;
	pos = 1;
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
	return (0);
}
/*
void	ft_echo(t_element *element)
{
	int		i;
	bool	flag;

	i = 0;
	flag = false;
	if (!ft_strncmp(element->arg[0], "-n", 2))
	{
		flag = true;
		i++;
	}
	while (element->arg[i])
	{
		printf("%s", element->arg[i]);
		if (element->arg[i + 1])
			printf(" ");
		i++;
	}
	if (flag == false)
		printf("\n");
}
*/
