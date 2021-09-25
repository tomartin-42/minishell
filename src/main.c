/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommy <tommy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:04:36 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/25 12:58:21 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"							

static void	copy_to_g_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	i++;
	g_env = (char **)malloc(sizeof(char *) * i);
	i = 0;
	while (env[i])
	{
		g_env[i] = ft_strdup(env[i]);
		i++;
	}
	g_env[i] = NULL;
	i = 0;
}

int	main(int argc, char **argv, char **env)
{
	char		*str;
	char		*line;
	t_element	*element;

	while (1)
	{
		str = readline("ShellFromHell: > ");
		line = ft_strdup(str);
		free(str);
		if (ft_strlen(line) != 0)
		{
			element = malloc(sizeof(t_element));
			element->next = NULL;// we might need to use a prev pointer
			element->str = ft_strdup(line);
			add_history(line);
			copy_to_g_env(env);
			main_parse(line, element);
			print_list(element);
			printf("%d - %s - %s\n", argc, argv[0], env[0]);
		}
	}
}
