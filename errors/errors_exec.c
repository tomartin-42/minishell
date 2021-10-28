#include "errorlib.h"

int	error_cmd_not_found(char *str)
{
	ft_putstr_fd("SFH: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("command not found\n", 2);
	g_state = 127;
	exit (g_state);
}

int	error_open_marks(void)
{
	ft_putstr_fd("SFH: ", 2);
	ft_putstr_fd("unclosed commas in command line\n", 2);
	g_state = 42;
	return (g_state);
}

int	error_undef_redir(void)
{
	ft_putstr_fd("SFH: error near unexpected token `newline'\n", 2);
	g_state = 258;
	return (g_state);
}

int	error_forbidden_char(void)
{
	ft_putstr_fd("SFH: Hey men!! Don't use forbudden chars!!! 😜 \n", 2);
	g_state = 42;
	return (g_state);
}
