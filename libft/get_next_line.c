/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 18:05:42 by tomartin          #+#    #+#             */
/*   Updated: 2021/09/01 08:05:26 by tomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cpy_to_buff_r(char *read_f, char **buff_r)
{
	char	*aux;

	if (!read_f)
		read_f = ft_strdup ("");
	if (!*buff_r)
		 aux = ft_strdup (read_f);
	else
	{
		aux = ft_strjoin (*buff_r, read_f);
		if (*buff_r)
			free (*buff_r);
	}
	return (aux);
}

static void	ft_resize_buff(char **buff)
{
	char	*aux;

	aux = ft_strdup (ft_strchr (*buff, '\n') + 1);
	free (*buff);
	*buff = ft_strdup (aux);
	free(aux);
}

static int	ft_extract_line(char **buff, char **line)
{	
	int		answ;
	int		i;

	i = 0;
	answ = 0;
	if (ft_strchr (*buff, '\n'))
	{
		while (*(*buff + i) != '\n')
			i++;
		*line = ft_substr (*buff, 0, i);
		ft_resize_buff (&*buff);
		answ = 1;
	}
	else
	{
		*line = ft_strdup (*buff);
		free (*buff);
		*buff = NULL;
		answ = 0;
	}
	return (answ);
}

int	get_next_line(int fd, char **line)
{
	char		*read_f;
	static char	*buff_r[FD_SETSIZE];
	ssize_t		len;
	int			answ;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > FD_SETSIZE || !line)
		return (-1);
	read_f = malloc (BUFFER_SIZE + 1);
	len = read (fd, read_f, BUFFER_SIZE);
	if (len < 0)
	{
		free (read_f);
		return (-1);
	}
	while (1)
	{
		read_f[len] = '\0';
		buff_r[fd] = ft_cpy_to_buff_r (read_f, &buff_r[fd]);
		if (ft_strchr (buff_r[fd], '\n') || len == 0)
			break ;
		len = read (fd, read_f, BUFFER_SIZE);
	}
	answ = ft_extract_line (&buff_r[fd], &*line);
	free (read_f);
	return (answ);
}
