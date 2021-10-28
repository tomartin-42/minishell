#include "errorlib.h"

int	main_error(char *line)
{
	if (check_fault_marks(line))
		return (1);
	return (0);
}
