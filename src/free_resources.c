#include "minishell.h"

void	free_element(t_element *element)
{
	t_element *aux;

	while (element)
	{
		aux = element;
		element = element->next;
		free(aux->str);
		if (aux->arg)
			ft_free_dp(aux->arg);
		free(aux);
	}
}

