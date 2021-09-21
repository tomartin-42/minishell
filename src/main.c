/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:04:36 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/20 12:15:29 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"							

#define CLOSE "\001\033[0m\002"                 // cierra todas las propiedades
#define BLOD  "\001\033[1m\002"                 // enfatizar, negrita, resaltar
#define BEGIN(x,y) "\001\033["#x";"#y"m\002"    // x: fondo, y: primer plano

int main(int argc, char **argv, char **env)
{
	char *str;
	char *line;
	
	while (1)
	{
		str = readline(BEGIN(49, 34)"ShellFromHell: > "CLOSE);
		line = ft_strdup(str);
		free(str);
		if(ft_strlen(line) != 0)
		{
		add_history(line);
		execut(argc, argv, env, line);
		printf("%d - %s - %s\n", argc, argv[0], env[0]);
		}

	}
}
