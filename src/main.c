/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tommy <tommy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:04:36 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/30 19:02:08 by tommy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "hered.h"
#include "parse.h"
//This function initialice and copy the env var to list 
//(m_env)
static void	copy_env(char **env)
{
	t_env	*m_env;
	int		i;

	i = 0;
	while(env[i])
		i++;
	m_env = malloc(sizeof(t_env) * i);
	i = 0;
	while (env[i])
	{
		m_env[i].v_env= ft_strdup(env[i]);
		m_env[i].global = true;
		m_env[i].visible = true;
		m_env[i].del = false;
		i++;
	}	
}

int	main(int argc, char **argv, char **env)
{
	char		*str;
	char		*line;
	t_element	*element;

	while (1)
	{
		str = readline("🔥ShellFromHell🔥: > ");
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
			rutine_parse(line, element);
			copy_env(env);
			print_list(element);
			printf("%d - %s - %s\n", argc, argv[0], env[0]);
		}
	}
}
