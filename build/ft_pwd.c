/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:27:59 by dpuente-          #+#    #+#             */
/*   Updated: 2021/10/14 11:50:53 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

void	ft_pwd(char **envs)
{
	int	pos;
	int	n;

	pos = 0;
	n = 4;
	while (envs[pos]
		&& (envs[pos][0] != 'P' && envs[pos][1] != 'W' && envs[pos][2] != 'D'))
	{
		pos++;
	}
	if (envs[pos])
	{
		if (envs[pos][0] == 'P' && envs[pos][1] == 'W' && envs[pos][2] == 'D')
		{
			while (envs[pos][n] != '\0')
			{
				write (1, &envs[pos][n], 1);
				n++;
			}
			write(1, "\n", 1);
		}
	}
}
