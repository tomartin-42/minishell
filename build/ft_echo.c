/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:39:03 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/13 20:23:16 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

int	infinity_n(char *args)
{
	int	pos;

	pos = 2;
	printf("-->%s<--", args);
	if (args[0] == '-' && args[1] == 'n')
	{
		while (args[pos] != '\0' && args[pos] == 'n')
		{
			pos++;
		}
		if (args[pos] != '\0' && args[pos] != 'n')
			return (1);
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
	bool	flag;

	flag = false;
	pos = 0;
	while (args[pos])
	{
		if (!ft_strncmp(args[pos], "-n", 2))// cambiar por infinity_n para saber si -n esta bien puesto y no entrear siempre que las dos primeras son -n
			printf("CABESHAAAA");
			//flag = true;
		else
		{
			//printf("[%s]\n", args[pos]);
			if (!echo_out(args[pos]))
				echo_out("ERROR");
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
