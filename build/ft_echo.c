/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:39:03 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/13 12:31:38 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

int	echo_out(char *string)
{
	ft_putstr_fd(string, 1);
	if (!string)
		return (-1);
	return (0);
}

int	ft_echo(char **args)
{
	int	pos;

	pos = 0;
	/*if (!args[1]) //si hay argumentos aparte de echo que se encuentra en args[0]
	{
		write(1, "\n", 1);
		return (-1);
	}*/
	while (args[pos])
	{
		if (!echo_out(args[pos]))
			echo_out("ERROR");
		pos++;
	}
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
