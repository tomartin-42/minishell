#include "libft.h"

void	ft_free_db(char **dp)
{
	int	i;

	i = 0;
	while (dp[i] != NULL)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}
