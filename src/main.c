/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommy <tommy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:04:36 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/30 09:15:26 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "hered.h"
#include "parse.h"
//This function initialice and copy the env var to list 
//(m_env)
static void	copy_to_g_env(char **env)
{
	t_env	*m_env;

	m_env = malloc (sizeof(t_env));
//	init_env_list(m_env);
	copy_env_to_list(m_env, env);
//	free_first_node_env(m_env);
	print_env(m_env);
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
			check_fault_marks(line);
			element = malloc(sizeof(t_element));
			element->next = NULL;
			element->prev = NULL;
			element->str = ft_strdup(line);
			element->type = 'G';
			add_history(line);
			copy_to_g_env(env);
			rutine_parse(line, element);
			//print_list(element);
			printf("%d - %s - %s\n", argc, argv[0], env[0]);
		}
	}
}
