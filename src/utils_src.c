/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_src.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:50:13 by tomartin          #+#    #+#             */
/*   Updated: 2021/10/24 13:03:39 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//This function sustitute access();
int	ft_access(char *fname)
{
	int			fd;
	int			is_file;
	struct stat	s_stat;

	is_file = 0;
	fd = open(fname, O_RDONLY);
	if (fd != -1)
	{
		fstat(fd, &s_stat);
		if (!S_ISDIR(s_stat.st_mode))
			is_file = 1;
		close(fd);
	}
	return (is_file);
}
