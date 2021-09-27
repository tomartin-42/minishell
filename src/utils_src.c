/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_src.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:50:13 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/27 11:51:18 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_access(char *fname)
{
	int	fd;
	int	errno;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
	{
		if (errno == ENOENT)
			return (-1);
		else
			return (-2);
	}
	return (fd);
}