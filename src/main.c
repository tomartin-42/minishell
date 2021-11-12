/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:04:36 by tomartin          #+#    #+#             */
/*   Updated: 2021/11/12 12:37:58 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "hered.h"
#include "parse.h"
#include "build.h"
#include "exec.h"
#include "errorlib.h"

int	g_state;

//This function initialice and copy the env var to list 
//(m_env)
void	mute_unused(int argc, char **argv)
{
	argc = argc + 1 - 1;
	argv[0] = argv[0];
}

static t_env	*copy_env(char **env)
{
	t_env	*m_env;
	int		i;
	t_env	*new;
	char	*aux;

	i = 0;
	m_env = NULL;
	new = NULL;
	aux = ft_strdup("Specialthanksto=Javgonza and Carce-bo");
	new = new_env_node_global(new, aux);
	new->visible = false;
	ft_lstadd_back_env(&m_env, new);
	free(aux);
	while (env[i])
	{
		new = new_env_node_global(new, env[i]);
		ft_lstadd_back_env(&m_env, new);
		i++;
	}
	return (m_env);
}

void	init_element(t_element *element, char *line)
{
	element->next = NULL;
	element->prev = NULL;
	element->arg = NULL;
	element->str = ft_strdup(line);
	element->type = 'G';
}

static void	secure_env(t_env *env)
{
	t_env	*new;
	char	*aux;

	new = NULL;
	aux = getcwd(NULL, 0);
	aux = ft_super_strjoin("PWD=", aux, 2);
	new = new_env_node_global(new, aux);
	ft_lstadd_back_env(&env, new);
	free (aux);
	aux = getcwd(NULL, 0);
	aux = ft_super_strjoin("OLDPWD=", aux, 2);
	new = new_env_node_global(new, aux);
	ft_lstadd_back_env(&env, new);
	free (aux);
}

int	main(int argc, char **argv, char **env)
{
	t_env			*m_env;
	struct termios	old;

	(void)argc;
	(void)argv;
	tcgetattr(0, &old);
	m_env = NULL;
	m_env = copy_env(env);
	change_shlvl(m_env);
	if (*env == NULL)
		secure_env(m_env);
	g_state = 0;
	main_loop(old, m_env);
}
