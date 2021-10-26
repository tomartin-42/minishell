/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:04:36 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/26 11:38:46 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "hered.h"
#include "parse.h"
#include "build.h"
#include "exec.h"

int	g_state;

//This function initialice and copy the env var to list 
//(m_env)
void	mute_unused(int argc, char **argv)
{
	argc = argc + 1 - 1;
	argv[0] = argv[0];
}
/////RESTAURAR init_env_list SI SE DESCOMENTA LAS PARTES DE ESTA FUNCION//////////////
static t_env	*copy_env(char **env)
{
	t_env	*m_env;
	int		i;
	t_env	*new;

	i = 0;
	m_env = NULL;
	while (env[i])
	{
//		if (!m_env)
//			init_env_list(&m_env, env[i]);
//		else
//		{
			new = new_env_node_global(new, env[i]);
			ft_lstadd_back_env(&m_env, new);
//		}
		i++;
	}
	return (m_env);
	//ft_expand(m_env, "hola$PWDxx la 2hola $");
}

int	main(int argc, char **argv, char **env)
{
	char		*str;
	char		*line;
	t_element	*element;
	t_env		*m_env;

	m_env = NULL;
	select_signal();
	mute_unused(argc, argv);//Mute unused variales, argv and argc
	m_env = copy_env(env);
	g_state = 0;
	//change_shlvl(m_env);
	while (1)
	{
		str = readline("🔥ShellFromHell🔥: > ");
		if (str == NULL)
		{
			printf("exit\n");
			exit (0);
		}
		line = ft_strdup(str);
		free(str);
		if (ft_strlen(line) != 0)
		{
			add_history(line);
			check_fault_marks(line);
			//printf("***%s***\n", line);
			//line = ft_expand(m_env, line);///////////////////////////////////////////////////
			//printf("***%s***\n", line);
			element = malloc(sizeof(t_element));
			//g_plist->p_element = element;
			element->next = NULL;
			element->prev = NULL;
			element->str = ft_strdup(line);
			element->type = 'G';
			rutine_parse(line, element, m_env);
			main_exec(element, m_env);
		}
	}
}
