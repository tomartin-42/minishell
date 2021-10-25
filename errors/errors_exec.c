#include "errorlib.h"

int	error_cmd_not_found(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("command not found\n", 2);
	errno = 127;
	exit (errno);
}
