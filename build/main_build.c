/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 08:32:00 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/14 10:52:01 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"

// Build pwd

void	ft_pwd(char **g_env)
{
	char	*pwd;
	int		i;

	i = 0;
	while (ft_strncmp(g_env[i], "PWD=", 4) && g_env[i])
		i++;
	pwd = g_env[i];
	pwd += 4;
	printf("%s\n", pwd);
}
// Build env

void	ft_env(char **g_env)
{
	int	i;

	i = 0;
	while (g_env[i])
	{
		printf("%s\n", g_env[i]);
		i++;
	}
}
