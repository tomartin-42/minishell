/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:04:36 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/05 09:30:09 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "hered.h"
#include "parse.h"
#include "build.h"

//This function initialice and copy the env var to list 
//(m_env)
static void	copy_env(char **env)
{
	t_env	*m_env;
	int		i;
	t_env	*new;

	i = 0;
	m_env = NULL;
	while (env[i])
	{
		if (!m_env)
			init_env_list(&m_env, env[i]);
		else
		{
			new = new_env_node_global(new, env[i]);
			ft_lstadd_back_env(&m_env, new);
		}
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
			//g_plist->p_element = element;
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
