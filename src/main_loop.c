/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:22:33 by dpuente-          #+#    #+#             */
/*   Updated: 2021/11/11 13:43:17 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "hered.h"
#include "parse.h"
#include "build.h"
#include "exec.h"
#include "errorlib.h"

void	valid_instruction(struct termios old, t_env *m_env, char *line)
{
	t_element		*element;

	add_history(line);
	if (main_error(line))
		free (line);
	else
	{
		check_fault_marks(line);
		element = malloc(sizeof(t_element));
		init_element(element, line);
		rutine_parse(line, element, m_env);
		main_exec(element, m_env);
		tcsetattr(0, TCSANOW, &old);
		free (line);
		free_element(element);
	}
}

void	main_loop(struct termios old, t_env *m_env)
{
	char			*str;
	char			*line;

	while (1)
	{
		select_signal();
		str = readline("🔥ShellFromHell🔥:> ");
		if (str == NULL)
		{
			printf("exit\n");
			exit (0);
		}
		line = ft_strdup(str);
		free(str);
		if (ft_strlen(line) != 0)
		{
			valid_instruction(old, m_env, line);
		}
	}
}
