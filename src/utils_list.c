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

