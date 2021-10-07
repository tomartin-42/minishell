#include "exec.h"
#include "hered.h"

static void	start_hered(t_element *element)
{
	t_element	*aux_ele;

	aux_ele = ft_lstlast(element);
	while(aux_ele)
	{
		if (aux_ele->type == 'H')
			main_hered(aux_ele);
		aux_ele = aux_ele->prev;
	}
}

void	main_exec(t_element *element, t_env *env)
{
	start_hered(element);
	*env = *env;
	*element = *element;
}

