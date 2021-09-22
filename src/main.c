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

int main(int argc, char **argv, char **env)
{
	char *str;
	char *line;
	t_element	element;
	
	while (1)
	{
		str = readline("ShellFromHell: > ");
		line = ft_strdup(str);
		free(str);
		if(ft_strlen(line) != 0)
		{
			add_history(line);
			main_parse(line, &element);
			//execut(argc, argv, env, line);
			printf("%d - %s - %s\n", argc, argv[0], env[0]);
		}

	}
}
