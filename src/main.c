/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <tomartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:04:36 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/04 10:33:01 by tomartin         ###   ########.fr       */
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

	i = 0;
	while (env[i])
		i++;
	m_env = malloc(sizeof(t_env) * (i + 1));
	i = 0;
	while (env[i] != NULL)
	{
		m_env[i].v_env = ft_strdup(env[i]);
		m_env[i].var = ft_split(m_env[i].v_env, '=');
		m_env[i].global = true;
		m_env[i].visible = true;
		m_env[i].del = false;
		m_env[i].end = false;
		i++;
	}
	m_env[i].end = true;
	char	**aux;
	aux = (char **)malloc(sizeof(char *) * 2);
	aux[0] = ft_strdup("ABC=AAA");
	aux[1] = NULL;
	ft_export(m_env, aux);
	//print_env(m_env);
	//ft_export(m_env, NULL);
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
