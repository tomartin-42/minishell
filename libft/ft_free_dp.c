#include "libft.h"

void	ft_free_dp(char **dp)
{
	int	i;

	i = 0;
	if (dp != NULL)
	{
		while (dp[i] != NULL)
		{
			free(dp[i]);
			i++;
		}
		free(dp);
	}
}
