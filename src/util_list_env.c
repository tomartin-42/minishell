#include "minishell.h"

void	init_env_list(t_env *m_env)
{
	m_env->next = NULL;
	m_env->prev = NULL;
	m_env->global = true;
}

t_env	*ft_lstlast_env(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back_env(t_env **env, t_env *new)
{
	if (!*env)
	{
		*env = new;
		return ;
	}
	if (!env)
		return ;
	new->prev = (ft_lstlast_env(*env));
	(ft_lstlast_env(*env))->next = new;
	printf ("%p\n", new->next);
	printf ("%p\n", new->prev);
}

// Copy env var and add nodes to the m_emv list 
void	copy_env_to_list(t_env *m_env, char **env)
{
	int		i;
	t_env	*new;
	
	m_env = m_env,
	i = 0;
	while (env[i] != NULL)
	{
		new = malloc(sizeof(t_env));
	//	printf("-----%s-----\n", env[i]);
		new->v_env = ft_strdup(env[i]);
		new->global = true;
		new->next = NULL;
		ft_lstadd_back_env(&m_env, new);
		free(new->v_env);
	//	free(new);
		new = NULL;
		i++;
	}
}

void print_env(t_env *env)
{
	while (env->next != NULL)
	{
		printf("[%s]\n", env->v_env);
		printf("==================================\n");
		env = env->next;
	}
	printf("[%s]\n", env->v_env);
	printf("==================================\n");
}
