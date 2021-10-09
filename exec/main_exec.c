#include "exec.h"
#include "hered.h"

static void	start_hered(t_element *element)
{
	t_element	*aux_ele;

	aux_ele = element; 
	while(aux_ele)
	{
		if (aux_ele->type == 'H')
			main_hered(aux_ele);
		aux_ele = aux_ele->next;
	}
}

static void	open_to_read(t_element *element)
{
	element->fd = open(element->arg[0], O_RDONLY);
	if (element->fd < 0)
	{
		printf("error %d\n", errno);
		exit (errno);
	}
	else
		dup2(element->fd, STDIN_FILENO);
	close(element->fd);
}

static void	open_to_write(t_element *element)
{
	element->fd = open(element->arg[0], O_WRONLY | O_CREAT, 0644);	 
	if (element->fd < 0)
	{
		printf("error %d\n", errno);
		exit (errno);
	}
	else
		dup2(element->fd, STDOUT_FILENO);
	close(element->fd);
}

static void	open_to_trunk(t_element *element)
{
	element->fd = open(element->arg[0], O_APPEN, 0644);
	if (element->fd < 0)
	{
		printf("error %d\n", errno);
		exit (errno);
	}
	else
		dup2(element->fd, STDOUT_FILENO);
	close(element->fd);
}

static void redir_hered(t_element *element)
{
	dup2(element->fd, STDIN_FILENO);
	close(element->fd);
}

static t_element	*redir_files(t_element *element)
{
	t_element	*p_elem;
	t_element	*p_end;

	p_elem = element;
	while (p_elem && p_elem->type != 'P')
	{
		if (p_elem->type == 'I')
			open_to_read(element);
		else if (p_elem->type == 'O')
			open_to_write(element);
		else if (p_elem->type == 'T')
			open_to_trunk(element);
		else if (p_elem->type == 'H')
			redir_hered(element);
	p_elem = p_elem->next;
	}
	if (p_elem->type == 'P')
		p_end = p_elem;
	else 
		p_end = NULL;
	return (p_end);
}

void	main_exec(t_element *element, t_env *env)
{
	int	fd_stdin;
	int fd_stdout;

	fd_stdin = dup(STDIN_FILENO);
	fd_stdout = dup(STDOUT_FILENO);	
	start_hered(element);
	redir_files(element);
	*env = *env;
}
