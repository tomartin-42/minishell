#include "exec.h"
#include "hered.h"

static void	start_hered(t_element *element)
{
	t_element	*aux_ele;

//	print_list(element);
	aux_ele = element; 
	print_list(aux_ele);
	while(aux_ele)
	{
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

