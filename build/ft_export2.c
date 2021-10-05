#include "build.h"

// Search in env list and return 1 if had a global var, 0 locat var
// and -1 if don't had
static int	search_if_var(t_env *env, char *arg)
{
	t_env	p_env;

	p_env = env;
	while (p_env)
	{
		if (ft_strcmp(p_env->var[0], arg) == 0 && (p_env->global == true))
			return (1);
		else if (ft_strcmp(p_env->var[0], arg) == 0 && (p_env->local == true))
			return (0);
		p_env = p_env->next;
	}
	return (-1);
}

void	without_equal_export(t_env *env, char *arg)
{
	int	i;

	i = search_if_var(t_env *envi, arg);
	if (i = 0)
		//promociona local a global
	else if (i = -1)
		//añade a global var
}
