#include "minishell.h"

t_element	*ft_lstlast(t_element *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_element **lst, t_element *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!lst)
		return ;
	(ft_lstlast(*lst))->next = new;
}

void	print_list(t_element *element)
{
	while (element->next)
	{
		printf("%s\n", element->str);
	printf("HOLA2\n");
		element = element->next;
	}
}

