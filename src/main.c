/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:04:36 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/01 12:26:01 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "hered.h"
#include "parse.h"
#include "build.h"
#include "exec.h"
#include "errorlib.h"

int	g_state; //VARIABLE GLOBAL para indicar el estado

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
	char	*aux;

	i = 0;
	m_env = NULL;
	new = NULL;
	aux = ft_strdup("Specialthanksto=Jagonza and Carce-bo");
	new = new_env_node_global(new, aux);
	new->visible = false;
	ft_lstadd_back_env(&m_env, new);
	free(aux);
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

static void	init_element(t_element *element, char *line)
{
	element->next = NULL;
	element->prev = NULL;
	element->arg = NULL;
	element->str = ft_strdup(line);
	element->type = 'G';
}

static void	(t_env *env)
{



int	main(int argc, char **argv, char **env)
{
	char		*str;
	char		*line;
	t_element	*element;
	t_env		*m_env;

	m_env = NULL;
	select_signal();
	if (*env == NULL)
		printf("HOLA\n");
	else 
	{
		mute_unused(argc, argv);
		m_env = copy_env(env);
		change_shlvl(m_env);
	}
	g_state = 0;
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
			if (main_error(line))
				free (line);
			else
			{
				check_fault_marks(line);
				element = malloc(sizeof(t_element));
				init_element(element, line);
				rutine_parse(line, element, m_env);
				print_list(element);//////////////////////////////////////////borrar
				main_exec(element, m_env);
				free (line);
			}
		}
	}
}
