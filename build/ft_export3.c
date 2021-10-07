#include "build.h"

//Separate the env var in doble pointer name and value
char	**separate_env_var(char *var)
{
}	char	**var_dual;
	int		i;
	char	*aux;
	
	i = 0;
	var_dual = malloc(sizeof(char *) * 2);
	while (var[i] != '=' && var[i] != '\0')
		i++;
	var_dual[0] = ft_substr(var, 0, i);
	aux = ft_strchr(var, '=');
	aux++;
	var_dual[1] = ft_strdup(aux);
	return (var_dual);
}

