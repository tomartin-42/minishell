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
}

// Copy env var and add nodes to the m_emv list 
void	copy_env_to_list(t_env *m_emv, char **env)
{
	int		i;
	t_env	*new;
	
	i = 0;
	while (env[i] != NULL)
	{
		new = malloc(sizeof(t_env));
		new->v_env = ft_strdup(env[i]);
		printf("**%s**\n", new->v_env);
		new->global = true;
		new->next = NULL;
		ft_lstadd_back_env(&m_emv, new);
		i++;
		if (new != NULL)
		{
			free(new->v_env);
			//free(new);
			new = NULL;
		}
	}
}

void print_env(t_env *env)
{
	while (env->next != NULL)
	{
		printf("HOLA\n");
		printf("[%s]\n", env->v_env);
		printf("==================================\n");
		env = env->next;
	}
	printf("[%s]\n", env->v_env);
	printf("==================================\n");
}
