#include "exec.h"
#include "hered.h"

static void	start_hered(t_element *element)
{
	t_element	*aux_ele;

	aux_ele = element;
//	aux_ele = ft_lstlast(element);
	while(aux_ele)
	{
	//	printf("HERED FD = %p\n", aux_ele->arg[0]);
		if (aux_ele->type == 'H')
			main_hered(aux_ele);
		aux_ele = aux_ele->next;
	}
}

void	main_exec(t_element *element, t_env *env)
{
	start_hered(element);
	*env = *env;
	*element = *element;
}

