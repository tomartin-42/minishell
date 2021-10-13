#include "exec.h"
#include "hered.h"

void	start_hered(t_element *element)
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
	element->fd = open(element->arg[1], O_RDONLY);
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
	element->fd = open(element->arg[1], O_WRONLY | O_CREAT, 0644);	 
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
	element->fd = open(element->arg[1], O_APPEND, 0644);
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

void	redir_files(t_element *element)
{
	t_element	*p_elem;

	p_elem = element;
	while (p_elem && p_elem->type != 'P')
	{
		if (p_elem->type == 'I')
			open_to_read(p_elem);
		else if (p_elem->type == 'O')
			open_to_write(p_elem);
		else if (p_elem->type == 'T')
			open_to_trunk(p_elem);
		else if (p_elem->type == 'H')
			redir_hered(p_elem);
		p_elem = p_elem->next;
	}
}

void	main_exec(t_element *element, t_env *env)
{
	t_command	command;

	command.fd_stdin = dup(0);
	command.fd_stdout = dup(1);
	command.multi_cmd = element;
	command.pid_num = 0;
	start_hered(element);
	rutine_command(element, env, &command);
}

