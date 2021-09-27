#include "hered.h"
//This function buind a no existing temp file in /tmp/ and return
//the path of thid file
static char	*open_tmp_hered(void)
{
	char	*path;
	int		i;

	path = ft_strdup("/tmp/sfh.hd");
	i = 0;
	while (!ft_access(path))
	{	
		path = ft_super_strjoin(path, ft_itoa(i), 1);
		i++;
	}
	return (path);
}			

int	hered_main(t_element *element)
{
	open_tmp_hered();
	printf ("%s\n", element->str);
	return (1);
}
